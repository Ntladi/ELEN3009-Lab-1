#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	cout << "Enter a number between 1 and 100: ";

	srand(time(0)); // seed to start at a new random number each time
	int num = rand() % 100 + 1; // store the random number
	const int MAX_GUESSES = 5; // define the maximum number of guesses

	// game loop
	for (int i = 0; i < MAX_GUESSES; i++)
	{
		// input guess from user
		int guess;
		cin >> guess;

		if (guess < num && i < MAX_GUESSES - 1)
		{	// output message if the guess is too low
			cout << "Guess Higher: ";
		}
		else if (guess > num && i < MAX_GUESSES - 1)
		{	// output message if the guess is too high
			cout << "Guess Lower: ";
		}
		else if (guess == num)
		{	// break out of the loop if the guess is correct
			cout << "You Win." << endl;
			break;
		}
		else if (guess != num && i == MAX_GUESSES - 1)
		{	// output message if the user exhausts all chances
			// at the end of the loop
			cout << "You Lose." << endl;
		}
	}

}
