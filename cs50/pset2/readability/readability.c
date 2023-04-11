#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    // Count no of letters, words & sentences in text
    // count in float to round correctly
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);

    // Calculate l, s, and index using Coleman-Liau Formula
    float l = (letters / words) * (float)100;
    float s = (sentences / words) * 100.0;
    float index = (0.0588 * l) - (0.296 * s) - 15.8;

    //using round function rounded to nearest int to index
    int rounded = round(index);

    //Print grade 
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", rounded);
    }
}


//Function for letters count
int count_letters(string text)
{
    int n = strlen(text);
    int letter_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (text[i] > 64 && text[i] < 123)
        {
            letter_count++;
        }
    }
    return letter_count;
}

//function code for words count
int count_words(string text)
{
    int n = strlen(text);
    int word_count = 1;
    for (int i = 0; i < n; i++)
    {
        if (text[i] == 32)
        {
            word_count++;
        }
    }
    return word_count;
}

//function for sentences count
int count_sentences(string text)
{
    int n = strlen(text);
    int sen_count = 0;

    for (int i = 0; i < n; i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sen_count++;
        }
    }
    return sen_count;
}