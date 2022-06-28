//
// Created by flasque on 28/06/2022.
//

#include "intpow.h"

long int intpow(int base, unsigned int exp)
{
    long int result = 1;
    while (exp)
    {
        if (exp % 2)
        {
            result *= base;
        }

        exp /= 2;
        base *= base;
    }
    return result;
}
