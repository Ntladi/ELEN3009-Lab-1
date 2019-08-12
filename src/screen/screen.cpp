#include "screen.h"

// Screen's constructor
Screen::Screen(string::size_type height, string::size_type width, char bkground) : height_ {
		height }, // initialises height_ with height
width_ { width },  // initialises width_ with width
_screen(height * width, bkground)	// size of _screen is height * width
// all positions initialized with
// character value of bkground
{ /* all the work is done in the member initialization list */
}

void Screen::forward()
{   // advance cursor_ one screen element
	++cursor_;

	// wrap around if the cursor_ is at the end of the screen
	if (cursor_ == _screen.size())
		home();

	return;
}

void Screen::back()
{   // move cursor_ backward one screen element
// check for top of screen; wrap around
	if (cursor_ == TOP_LEFT)
		end();
	else
		--cursor_;

	return;
}

void Screen::up()
{   // move cursor_ up one row of screen
// do not wrap around
	if (row() == 1) // at top?
	{
		if (cursor_ < width_ - 1) // cursor at edge?
		{
			string::size_type column = cursor_ + 2; // calculate the column
			move(height_, column); // wrap around
		}
		else if (cursor_ == width_ - 1) // cursor at the edge?
		{
			move(height_, 1); // wrap around to bottom left
		}
	}
	else
		cursor_ -= width_;

	return;
}

void Screen::down()
{   // move cursor_ down one row of screen
// wrap around
	if (row() == height_) // at bottom ?
	{
		if (cursor_ < ((height_ * width_) - 1)) // cursor at the edge?
		{
			string::size_type column = cursor_ + 2
					- ((height_ * width_) - width_); // calculate the column
			move(1, column); // wrap around
		}
		else if (cursor_ == ((height_ * width_) - 1)) // cursor at the edge?
		{
			home(); // wrap around to the top left
		}
	}
	else
		cursor_ += width_;

	return;
}

void Screen::move(string::size_type row, string::size_type col)
{   // move cursor_ to absolute position
// valid screen position?
	if (checkRange(row, col))
	{
		// row location
		auto row_loc = (row - 1) * width_;
		cursor_ = row_loc + col - 1;
	}

	return;
}

void Screen::move(Direction dir)
{
	// Move the cursor to the appropriate position by calling the
	// corresponding method.
	switch (dir)
	{
		case Direction::HOME:
			home();
			break;
		case Direction::FORWARD:
			forward();
			break;
		case Direction::BACK:
			back();
			break;
		case Direction::UP:
			up();
			break;
		case Direction::DOWN:
			down();
			break;
		case Direction::END:
			end();
			break;
		default:
			cerr << "Invalid Direction" << endl;
	}

}
char Screen::get(string::size_type row, string::size_type col)
{
	// position cursor_
	move(row, col);
	// the other get() member function
	return get();
}

void Screen::set(char ch)
{
	if (ch == '\0')
		cerr << "Screen::set warning: " << "null character (ignored).\n";
	else
		_screen[cursor_] = ch;

	return;
}

void Screen::set(const string &s)
{   // write string beginning at current cursor_ position
	auto space = remainingSpace();
	auto len = s.size();
	if (space < len)
	{
		cerr << "Screen::set - Truncating, " << "space available: " << space
				<< ", string length: " << len << endl;
		len = space;
	}

	_screen.replace(cursor_, len, s);
	cursor_ += len - 1;

	return;
}

void Screen::clear(char bkground)
{   // reset the cursor and clear the screen
	cursor_ = TOP_LEFT;
	// assign the string
	_screen.assign(
	// with size() characters
			_screen.size(),
			// of value bkground
			bkground);

	return;
}

void Screen::reSize(string::size_type h, string::size_type w, char bkground)
{   // can only *increase* a screen's size to height h and width w
// remember the content of the screen
	string local { _screen };
	auto local_pos = TOP_LEFT;

	// replaces the string to which _screen refers
	_screen.assign(      // assign the string
			h * w,           // with h * w characters
			bkground         // of value bkground
			);

	// copy content of old screen into the new one
	for (string::size_type ix = 0; ix < height_; ++ix)
	{ // for each row
		string::size_type offset = w * ix; // row position
		for (string::size_type iy = 0; iy < width_; ++iy)
			// for each column, assign the old value
			_screen.at(offset + iy) = local[local_pos++];
	}

	height_ = h;
	width_ = w;
	// cursor_ remains unchanged

	return;
}

void Screen::display() const
{
	for (string::size_type ix = 0; ix < height_; ++ix)
	{ // for each row
		string::size_type offset = width_ * ix; // row position
		for (string::size_type iy = 0; iy < width_; ++iy)
			// for each column, write element
			cout << _screen[offset + iy];
		cout << endl;
	}
	return;
}

bool Screen::checkRange(string::size_type row, string::size_type col) const
{   // validate coordinates
	if (row < 1 || row > height_ || col < 1 || col > width_)
	{
		cerr << "Screen coordinates (" << row << ", " << col
				<< " ) out of bounds.\n";
		return false;
	}
	return true;
}

void Screen::drawSquare(const string::size_type &topRow,
		const string::size_type &topCol, const string::size_type &length)
{
	if (!checkRange(topRow, topCol)) // are coordinates within screen range?
		return; // return if they are not

	if (!checkHeight(topRow, length)) // is the predicted height within range?
		return; // return if it is not

	if (!checkWidth(topCol, length)) // is the predicted width within range?
		return; // return if it is not

	//clearSquareSpace(topRow, topCol, length); // make space for the square on the screen
	setRowsSquare(topRow, topCol, length); // set the top and bottom edges of the square
	setVerticalX(topRow, topCol, length); // set the left and right edges of the square

}

bool Screen::checkHeight(const string::size_type &topRow,
		const string::size_type &length)
{
	if ((topRow + length - 1) > height()) // condition for an invalid height
	{ // print an error if condition is true and return false
		cerr << "Square height is out of bounds" << endl;
		return false;
	}
	return true; // return true if the height is valid
}

bool Screen::checkWidth(const string::size_type &topCol,
		const string::size_type &length)
{
	if ((topCol + length - 1) > width()) // condition for an invalid width
	{ // print an error if condition is true and return false
		cerr << "Square width is out of bounds" << endl;
		return false;
	}
	return true; // return true if the height is valid
}

void Screen::clearSquareSpace(const string::size_type &topRow,
		const string::size_type &topCol, const string::size_type &length)
{
	for (string::size_type i = 0; i < length; i++)
	{
		this->move(topRow + i, topCol); // sweep through each valid row

		for (string::size_type j = 1; j <= length; j++)
		{
			this->set(' '); // place an empty space for each spot occupied by the square
			this->move(Direction::FORWARD); // move the cursor forward
		}
	}
}

void Screen::setRowsSquare(const string::size_type &topRow,
		const string::size_type &topCol, const string::size_type &length)
{
	this->move(topRow, topCol); // move the cursor to the top row of the square

	setHorizontalX(length); // set the top row with X's

	this->move(topRow + length - 1, topCol); // move the cursor to the bottom row of the square

	setHorizontalX(length); // set the bottom row with X's
}

void Screen::setHorizontalX(const string::size_type &length)
{	// set an X at every point of the row
	for (string::size_type i = 0; i < length; i++)
	{
		this->set('X');
		this->move(Direction::FORWARD);
	}
}

void Screen::setVerticalX(const string::size_type &topRow,
		const string::size_type &topCol, const string::size_type &length)
{
	for (string::size_type i = 0; i < length; i++)
	{
		this->move(topRow + i, topCol); // move the cursor to the left edge
		this->set('X'); // set an X
		this->move(topRow + i, topCol + length - 1); // move the cursor to the right edge
		this->set('X'); // set an X
		this->move(Direction::DOWN); // move the cursor down
	}
}

string::size_type Screen::remainingSpace() const
{   // includes current position
	auto size = width_ * height_;
	return (size - cursor_);
}

string::size_type Screen::row() const
{   // return current row
	return (cursor_ + width_) / width_;
}

