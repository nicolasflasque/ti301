//
// Created by flasque on 24/06/2022.
//

#ifndef UNTITLED1_TIMER_H
#define UNTITLED1_TIMER_H

#include <time.h>

clock_t _start;
clock_t _end;
double _msecs;

void startTimer();

void stopTimer();

void displayTime();

#endif //UNTITLED1_TIMER_H
