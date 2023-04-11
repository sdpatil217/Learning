#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Max no of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct 
{
    string name;
    int vote;
}
candidate;

//Array of candidates
candidate candidates [MAX];

//Number of candidates
int candidate_count;

//Function prototype
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximun no of candidates is %i\n", MAX);
        return 2;
    }

    // Populate the candidate array
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].vote = 0;
    }

    int voter_count = get_int("Number of voters: ");

    //Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");
        if (!vote(name))
        {
            printf("Invalid name.\n");
        }
    }

    //Display winner of election

    print_winner();
}

//update vote totals given a new vote i.e. updates vote count for valid vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcasecmp((candidates[i].name), name) == 0)
        {
            candidates[i].vote = candidates[i].vote + 1;
            return true;
        }
    }
    return false;
}

//Print winner or winners of election
void print_winner(void)
{
    int max = candidates[0].vote;
    int index = 0;
    for (int i = 1; i < candidate_count; i++)
    {
        int current = candidates[i].vote;
        if (max < current)
        {
            max = current;
            index = i;
        }        
    }
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].vote == max)
        {
            printf("%s\n", candidates[j].name);
        }
    }
    return;
    
    

}
























