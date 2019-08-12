#include "StopWatch.h"
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

// Destructor outputs the final time for each stop watch object
StopWatch::~StopWatch()
{
	cout << "The code took " <<  fixed << setprecision(5) << getStopTime() << " seconds to run." << endl; // Output the final time.
}

// Start the stop watch
void StopWatch::start()
{
	this->startTime_ = getProcessTime(); // record the current time
}

// Stop the stop watch
void StopWatch::stop()
{
	this->stop_ = timeElapsed(); // record the final time
}

// Get how much time has passed since the stop watch has started
const double StopWatch::getTimeElapsed()
{
	return timeElapsed(); // return the time elapsed
}

// Get the final time when the stop watch stopped counting
const double StopWatch::getStopTime() const
{
	return stop_; // return the final time
}

// returns the amount of time in seconds that has passed since the process (i.e. your program) started executing 
double StopWatch::getProcessTime()
{
	clock_t time = clock();
	return static_cast<double>(time) / CLOCKS_PER_SEC;
}

// Calculate how much time has passed since the stop watch started
double StopWatch::timeElapsed()
{
	elapsedTime_ = getProcessTime(); // record the current time

	elapsedTime_ -= startTime_; // take the difference from the start time

	return elapsedTime_; // return the difference

}
