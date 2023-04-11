#include "cs50.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    string name[3];
    name[0] = "Suraj";
    name[1] = "Nikul";
    name[2] = "Swapnil";

    int length = strlen(name[0]);

    printf("%i\n", length);
}