#include <cs50.h>
#include <stdio.h>
#include <string.h>
// check if word provided by user is in lower case alphabetical order or not

int main(void)
{
    string word = get_string("Word: ");

    int word_length = strlen(word);
    for (int i = 0; i < word_length - 1; i++)
    {
        if (word[i] > word[i + 1])
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}