#include <stdio.h>

//void swap(int *a, int *b);


int main(void)
{
    int x = 1; 
    int y = 2; 

    printf("X is %i, Y is %i\n", x, y);
    
    int temp = x;
    x = y;
    y = x;


    printf("X is %i, Y is %i\n", x, y);
}
/*
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
*/