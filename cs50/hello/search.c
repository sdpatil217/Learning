#include "cs50.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimblr", "top hat"};

    string n = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        //printf("%s     ,     %s\n", strings[i], n);
        if (strcmp(strings[i], n) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}