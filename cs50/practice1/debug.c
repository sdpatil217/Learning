// Getting familier with C syntax
// Learning to debug my buggy cod
#include "cs50.h"
#include <stdio.h>


int main(void)
{
    string name = get_string("What is your name? ");
    string location = get_string("Where do you live? ");

    printf("Hello, %s, from %s!\n", name, location);
}