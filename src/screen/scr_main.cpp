// Exercising the Screen class
// By printing the letter 'N'

#include "screen.h"
#include <iostream>

using namespace std;

void printEdge(Screen &myScreen, int edge, int height);
void printDiagonal(Screen &myScreen, int width);

int main()
{
	const int MAX_LENGTH = 6; // Define the maximum size of one side of the screen
	const int LEFT_EDGE = 1; // Define the left edge's column index
	const int RIGHT_EDGE = MAX_LENGTH; // Define the right edge's column index

	auto myScreen = Screen { MAX_LENGTH, MAX_LENGTH, ' '}; // initialize the screen

	printEdge(myScreen, LEFT_EDGE, MAX_LENGTH); // print the left edge of the letter 'N'

	printDiagonal(myScreen, MAX_LENGTH); // print the diagonal of the letter 'N'

	printEdge(myScreen, RIGHT_EDGE, MAX_LENGTH); // print the right edge of the letter 'N'

	myScreen.display(); // display the result

	return 0;
}

void printEdge(Screen &myScreen, int edge, int height)
{
	for (int rowIndex = 1; rowIndex <= height; rowIndex++)
	{
		myScreen.move(rowIndex, edge); // move along the edge of the screen
		myScreen.set('*'); // set a point on the screen
	}
}

void printDiagonal(Screen &myScreen, int width)
{
	for (int diagIndex = 1; diagIndex <= width; diagIndex++)
	{
		myScreen.move(diagIndex, diagIndex); // move along the diagonal of the screen
		myScreen.set('*'); // set a point on the screen
	}
}
