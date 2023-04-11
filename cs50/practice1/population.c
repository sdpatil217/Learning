#include "cs50.h"
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    //Get starting population
    int n;
    do
    {
        n = get_int("Start Size: ");
    }
    while (n < 9);

    //get ending population from user

    // TODO: Prompt for end size
    int m;
    do
    {
        m = get_int("End Size: ");
    }
    while (m < n);

    // TODO: Calculate number of years until we reach threshold
    // calculate no of yrs required to reach that population
    // and also print that years no..
    int ans = 0;
    if (n == m)
    {
        printf("Years: %i\n", ans);
    }
    else
    {
        do
        {
            n = n + n / 3 - n / 4;
            ans++;
        }
        while (n < m);
        printf("Years: %i\n", ans);
    }
}