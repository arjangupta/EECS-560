/**
 * @file: Timer.h
 * @author: Unknown (given code from class website)
 * @date: 2.20.2017
 * @purpose: Header file for Timer class, Lab04, EECS 560
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
using namespace std;

class Timer {
private:
	timeval startTime;
	timeval endTime;
public:
	void start();
 	double stop();
 	void printTime(double duration);
 };
