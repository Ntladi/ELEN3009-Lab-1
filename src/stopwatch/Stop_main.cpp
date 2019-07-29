#include <iostream>
#include <iomanip>
#include "StopWatch.h"
using namespace std;

int main()
{
	const double TIME_TO_RUN = 5;
	//// This Piece of code should take around 5 seconds to run
	cout << "This piece of code should take " << TIME_TO_RUN
			<< " seconds to run." << endl;
	cout << "Running Please wait..." << endl;

	auto watch1 = new StopWatch { }; // Instantiate a stop watch object

	watch1->start(); // Start counting
	while (1)
	{
		if (watch1->getTimeElapsed() >= TIME_TO_RUN) // If the elapsed time is equal to the specified run time then break the loop.
		{
			break;
		}
	}
	watch1->stop(); // Stop the first clock

	delete watch1; // Deallocate memory to this object and show me the final time of the stop watch
	return 0;

}
