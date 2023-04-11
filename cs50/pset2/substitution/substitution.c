#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// To take command line agruments
int main(int argc, string argv[])
{
    //comfirm correct no of cmd line args
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //take key string from argv[1]
    string key = argv[1];
    int n = strlen(key);

    for (int i = 0; i < n; i++)
    {
        // convert all letters to upper case to check they are only letters of alphabates
        char a = toupper(key[i]);
        if (a > 90 || a < 65)
        {
            printf("Key must contain alphabetic characters.\n");
            return 1;
        }

        //check whether vhar is repeated or not
        for (int j = i + 1; j < n; j++)
        {
            char b = toupper(key[j]);
            // If repeated then return 1 and ask for non repeated key
            if (a == b)
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    // if statement for full key length should 26
    if (n != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    } 
    //key check completed here

    //take text to cipher
    string s = get_string("PlainText: ");
    int text_len = strlen(s);

    printf("CipherText: ");

    // For loop to go through every letter of plaintext
    for (int i = 0; i < text_len; i++)
    {
        char a = s[i];
        //If char is capital then print capital ciphertext
        if (a > 64 && a < 91)
        {
            int cap = (a - 65);
            char b = key[cap];
            char c = toupper(b);
            printf("%c", c);
        }

        //if char is lowercase
        else if (a > 96 && a < 123)
        {
            int cap = (a - 97);
            char b = key[cap];
            char c = tolower(b);
            printf("%c", c);
        }
        // If char is not alphabate
        else
        {
            printf("%c", a);
        }
    }
    printf("\n");

    return 0;
}