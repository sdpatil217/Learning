#include "cs50.h"
#include <stdio.h>
#include <string.h>

typedef struct 
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2];

    people[0].name = "Suraj";
    people[0].number = "9021685379";

    people[1].name = "Nikul";
    people[1].number = "7066551611";

    
    string name = get_string("Name: ");
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("%s\n", people[i].number);
            return 0;
        }
    }
    printf("Not Found\n"); 
    return 1;
}