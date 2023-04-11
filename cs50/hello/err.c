#include "cs50.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    string a = "Hello";
    string b = "Zye";
    int c = strcmp(a, b);
    printf("%i\n", c);
}