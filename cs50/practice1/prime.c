#include "cs50.h"
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    //do while loop for least value of prime no calculations
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
    //int x = 1 % 2;
    //printf("%i\n", x);
}

bool prime(int number)
{
    // TODO
    // do prime no codition satisfaction
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}
