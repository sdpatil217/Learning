#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

//locked[i][j] means i is locked over j
bool locked[MAX][MAX];

//Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

//Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

//function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
int loser(int winner, int loser2, int limit);


int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum no of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    //clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }
    
    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    //Querry for votes
    for (int i = 0; i < voter_count; i++)
    {
        //rank[i] is voters i th preference
        int ranks[candidate_count];

        //Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote. \n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

//update ranks for given new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates, name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count - 1; i++)
    {
        int cad_choice = ranks[i];
        for (int j = i + 1; j < candidate_count; j++)
        {
            int k = ranks[j];
            preferences[cad_choice][k] = preferences[cad_choice][k] + 1;
        }
    }
    return;
}

//Record pairs of candidates where one is preffered over other
void add_pairs(void)
{
    int index = -1;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            int k = preferences[i][j];
            int l = preferences[j][i];
            if (k > l)
            {
                index = index + 1;
                pairs[index].winner = i;
                pairs[index].loser = j;
                pair_count = pair_count + 1;
            }
            else if (k < l)
            {
                index = index + 1;
                pairs[index].loser = i;
                pairs[index].winner = j;
                pair_count = pair_count + 1;
            }
        }
    }
    return;
}

//sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    // TODO
    for (int i = 0; i < pair_count - 1; i++)
    {
        int w = pairs[i].winner;
        int l = pairs[i].loser;
        pair temp = pairs[i];
        int index = i;
        int diff1 = preferences[w][l] - preferences[l][w];
        for (int j = i + 1; j < pair_count; j++)
        {
            int ww = pairs[j].winner;
            int ll = pairs[j].loser;
            int diff2 = preferences[ww][ll] - preferences[ll][ww];
            if (diff1 < diff2)
            {
                diff1 = diff2;
                index = j;
            }
        }
        pairs[i] = pairs[index];
        pairs[index] = temp;
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        int lock = pairs[i].loser;
        int free = pairs[i].winner;
        if (i < 2)
        {
            locked[free][lock] = true;
        }
        if (i > 1)
        {
            int loop = loser(lock, free, i);
            if (loop == free)
            {
                locked[free][lock] = false;
            }
            else if (loop == 101)
            {
                locked[free][lock] = true;
            }
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    string winner = candidates[0];
    int count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            count = count + 1;
            if ((locked[i][j] == true && locked[j][i] == false) || (locked[i][j] == false && locked[j][i] == false))
            {
                continue;
            }
            else
            {
                winner = candidates[i + 1];
                break;
            }
        }
        if (count == candidate_count)
        {
            printf("%s\n", winner);
            break;
        }
    }
    return;
}

//cycle detect funtion
int loser(int winner, int loser2, int limit)
{
    int cont = 101;
    for (int i = 0; i < limit; i++)
    {

        int winner1 = pairs[i].winner;
        if (winner == winner1)
        {
            int loser1 = pairs[i].loser;
            if (loser1 == loser2)
            {
                return loser2;
            }
            else
            {
                cont = loser(loser1, loser2, limit);

                if (cont == loser2)
                {
                    return cont;
                }
                //printf("%i\n", cont);
            }
        }
    }
    return cont;
}
























