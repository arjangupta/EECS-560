/**
 * @file: Timer.cpp
 * @author: Unknown (given code from class website)
 * @date: 2.20.2017
 * @purpose: CPP file for Timer class, Lab04, EECS 560
 */

#include "Timer.h"

void Timer::start(){
  gettimeofday(&startTime, NULL);
}

double Timer::stop(){
  long seconds, nseconds;
  double duration;

  gettimeofday(&endTime, NULL);

  seconds  = endTime.tv_sec  - startTime.tv_sec;
  nseconds = endTime.tv_usec - startTime.tv_usec;

  duration = seconds + nseconds/1000000.0;

  return duration;
}

void Timer::printTime(double duration){
  printf("%5.6f seconds\n", duration);
}
