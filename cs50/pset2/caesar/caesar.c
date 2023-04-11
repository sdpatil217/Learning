#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//Declaration of functions
int only_digits(string s);
char rotate(char a, int key);


int main(int argc, string argv[])
{
    //command line arg condition
    if (argc != 2 )
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //For arg to be int only
    else
    {
        int k = only_digits(argv[1]);
        if (k == 1)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);

    string s = get_string("Plaintext: ");

    int n = strlen(s);

    printf("Ciphertext: ");

    for (int i = 0; i < n; i++)
    {
        char a = s[i];
        char c = rotate(a, key);
        printf("%c", c);
    }
    printf("\n");

    return 0;
}

int only_digits(string s)
{
    int n = strlen(s);

    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (!isdigit(c))
        {
            return 1;
        }
    }
    return 0;
}

//Get Cipher text for every letter

char rotate(char a, int key)
{
    //if char is capital letter
    if (a > 64 && a < 91)
    {
        char b = (a - 65 + (key % 26));
        if (b >= 26)
        {
            return (b + 65 - 26);
        }
        else
        {
            return (b + 65);
        }
    }
    else if (a > 96 && a < 122)
    {
        char b = (a - 97 + (key % 26));
        if (b >= 26)
        {
            return (b + 97 - 26);
        }
        else 
        {
            return (b + 97);
        }
    }
    else 
    {
        return a;
    }
}