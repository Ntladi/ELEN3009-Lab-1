#ifndef SCREEN_H
#define SCREEN_H

// The existing interface of public functions is sufficient in order
// to draw empty squares on the screen.
// The drawSquare function does not need to form part of this class.
// It would be much better if a screen object is passed into a class that 
// manipulates the object by drawing the square.
// This is viable because the existing interface can be used to draw the square

#include <string>
#include <iostream>
using namespace std;

// The unsigned integral type which is used to store the number of
// characters in a string is nested within the string class, so it
// is accessed using "string::size_type".
// The range of string::size_type is guaranteed to be large enough to store the maximum
// *size* of any string that can be held by the string class as well as any index into
// the string.
	enum class Direction {HOME, FORWARD, BACK, UP, DOWN, END};

class Screen {
public:
	// Screen's constructor
	Screen(string::size_type height, string::size_type width, char bkground = '#');

	// get the Screen's height
	string::size_type height() const { return height_; }
	// get the Screen's width
	string::size_type width() const { return width_; }

	// place the cursor at the top-left corner of the screen
	void home() { cursor_ = 0;  return; }
	// place the cursor at the bottom-right corner of the screen
	void end() { cursor_ = width_ * height_ - 1; return; }
	// move the cursor one position to the right
	void forward();
	// move the cursor one position to the left
	void back();
	// move the cursor up one row
	void up();
	// move the cursor down one row
	void down();
	// move the cursor to the specified row and column
	void move(string::size_type row, string::size_type col);
	// overloading the move method
	void move(Direction dir);

	// get the character at the cursor's current position
	char get() const { return _screen[cursor_]; }
	// get the character at the specified row and column
	char get(string::size_type row, string::size_type col);

	// write a character on the screen at the current cursor position
	void set( char ch );
	// write a string of characters on the screen starting at the current cursor position
	void set( const string& s );
	// overwrite the entire screen with the specified character
	void clear( char bkground = '#');

	// resize the screen
	void reSize( string::size_type height, string::size_type width, char bkground = '#');
	// display the screen
	void display() const;
	// check whether the specified co-ordinates lie within the screen
	bool checkRange(string::size_type row, string::size_type col) const;

	// member function used to draw the square
	void drawSquare(const string::size_type & topRow, const string::size_type & topCol, const string::size_type & length);

private:
	// constants
	// 0 represents the top-left screen element
	const string::size_type TOP_LEFT = 0;
	
	// private member functions
	string::size_type remainingSpace() const;
	string::size_type row() const;

	// custom private member functions
	bool checkWidth( const string::size_type & topRow, const string::size_type & length );
	bool checkHeight( const string::size_type & col, const string::size_type & length );
	void clearSquareSpace( const string::size_type & topRow, const string::size_type & topCol, const string::size_type & length );
	void setRowsSquare( const string::size_type & topRow, const string::size_type & topCol, const string::size_type & length );
	void setHorizontalX( const string::size_type & length );
	void setVerticalX( const string::size_type & topRow, const string::size_type & topCol, const string::size_type & length );
	void setRightColSquare( const string::size_type & topRow, const string::size_type & topCol, const string::size_type & length );

	// private data members
	// (using a trailing underscore is a naming convention for private data - not a requirement)

	// number of Screen rows
	string::size_type height_;
	// number of Screen columns
	string::size_type width_;	
	// default position of the Screen's cursor, use in-class initilisation
	string::size_type cursor_ = TOP_LEFT;
	// the Screen's data is stored as a string
	string _screen;
};


#endif

