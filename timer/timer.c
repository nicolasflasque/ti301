//
// Created by flasque on 24/06/2022.
//

#include <stdio.h>
#include "timer.h"

void startTimer()
{
    _start = clock();
}

void stopTimer()
{
    _end = clock();
}

void displayTime()
{
    _msecs = (1000.0 * (double) (_end - _start)) / CLOCKS_PER_SEC;
    printf("%g ms secs %g secs\n", _msecs, _msecs / 1000.0);
}