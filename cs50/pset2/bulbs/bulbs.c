#include "cs50.h"
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    //Get string from user
    string s = get_string("Message: ");

    //Loop to get every byte
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        int num = s[i];

        //strore in a array of bit
        int bit[8];
        for (int j = 0; j < 8; j++)
        {
            bit[j] = num % 2;
            //Fill the array of bits
            num = num / 2;
        }
        for (int k = 7; k >= 0; k--)
        {
            //printf("%i", bit[k]);
            print_bulb(bit[k]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
