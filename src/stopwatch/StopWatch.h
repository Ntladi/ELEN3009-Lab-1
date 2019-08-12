#ifndef STOPWATCH_H
#define STOPWATCH_H

class StopWatch {
public:
	StopWatch() : startTime_(0), elapsedTime_(0), stop_(0) {}; // Constructor to initialize private member variables
	~StopWatch(); // Destructor outputs the final time for each stop watch object
	void start(); // Start the stop watch
	void stop(); // Stop the stop watch
	const double getTimeElapsed(); // Get how much time has passed since the stop watch has started
	const double getStopTime() const; // Get the final time when the stop watch stopped counting

private:
	double startTime_; // Store the time when the stopwatch started
	double elapsedTime_; // Store the updated elapsed time since the stop watch started
	double stop_; // Store the final stop watch time

	// returns the amount of time in seconds that has passed since the process (i.e. your program) started executing
	double getProcessTime();
	// Calculate how much time has passed since the stop watch started
	double timeElapsed();
};

#endif
