//
// Created by flasque on 24/06/2022.
//

#include <stdio.h>
#include "timer.h"

void startTimer()
{
    _timer._start = clock();
}

void stopTimer()
{
    _timer._end = clock();
}

void displayTime()
{
    _timer._msecs = (1000.0 * (double) (_timer._end - _timer._start)) / CLOCKS_PER_SEC;
    printf("%g ms secs %g secs\n", _timer._msecs, _timer._msecs / 1000.0);
}