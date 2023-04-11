#include <ctype.h>
#include "cs50.h"
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Calculate score of both words using function compute_score
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!!\n");
    }
}

//Function declaration
int compute_score(string word)
{
    //Compute and return score for a word string
    int score = 0;
    int n = strlen(word);
    for (int i = 0; i < n; i++)
    {
        char l = toupper(word[i]);
        if (l >= 65 && l <= 90)
        {
            int x = l - 65;
            score = score + POINTS[x];
        }
    }
    return score;
}