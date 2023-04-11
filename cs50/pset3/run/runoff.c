#include <cs50.h>
#include <string.h>
#include <stdio.h>

//Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

//prefernces[i][j] is j th prefernce for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// candidate have name, votes, and elimination status
typedef struct 
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

//Array of candidates
candidate candidates[MAX_CANDIDATES];

//no of actual candidates and votes
int voter_count;
int candidate_count;

//Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // check for Invalid input usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    //populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum no. of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum no of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    //keep asking for votes to voters
    for (int i = 0; i < voter_count; i++)
    {
        //ask for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            //Record vote unless its invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }
    // Keep running runoff until winner exists
    while (true)
    {
        //calculate votes given remaining candidates
        tabulate();

        //Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }
        
        //Eliminate last place candidate
        int min = find_min();
        bool tie = is_tie(min);

        //If tie, everyone wins
        if(tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }
        eliminate(min);
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].votes = 0;
    }
    return 0;
} 

// Record prefernce if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int j = 0; j < candidate_count; j++)
    {
        if (strcmp((candidates[j].name), name) == 0)
        {
            preferences[voter][rank] = j;
            return true;
        }   
    }
    return false;
}

//Tabulate votes for non eliminated candidates
void tabulate (void)
{
    for (int i = 0; i < voter_count; i++)
    {
        int choice;
        for (int j = 0; j < candidate_count; j++)
        {
            choice = preferences[i][j];
            if (candidates[choice].eliminated == false)
            {
                candidates[choice].votes = candidates[choice].votes + 1;
                break;
            }
        }
    }
    return;
}

bool print_winner(void)
{
    int win = (voter_count / 2) ;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > win)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

//return the min no of votes of any remaining cadidates has
int find_min(void)
{
    int min = 101;
    for (int i = 0; i < candidate_count; i++)
    {
        if ((candidates[i].votes < min) && (candidates[i].eliminated == false))
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > min)
        {
            return false;
        }
    }
    return true;
}

void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}








































