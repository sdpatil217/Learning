#include "cs50.h"
#include <stdio.h>

void print_spaces (int spaces);
void print_steps(int steps);


int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 10);
    for (int i = 0; i < n; i++)
    {
        int spaces = n - i - 1;
        int steps = i + 1;
        print_spaces(spaces);
        print_steps(steps);
        printf("  ");
        print_steps(steps);
        printf("\n");
    }
}

void print_spaces (int spaces)
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
}

void print_steps(int steps)
{
    for (int i = 0; i < steps; i++)
    {
        printf("#");
    }
    //printf("\n");
}