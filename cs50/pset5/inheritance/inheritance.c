// Stimulates genetic inheritannce of blood type 

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

const int GENERATIONS =  3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    //seed random number generator
    srand(time(0));

    //Create a new family with 3 generations
    person *p = create_family(GENERATIONS);

    //print family tree of blood types
    print_family(p, 0);

    //Free memory
    free_family(p);

}

//Create a new individual with generations  recursive fuction
person *create_family(int generations)
{
    //allocate memory for new person
    person *p = malloc(sizeof(person));

    //if there are still generations left to create
    if (generations > 1)
    {
        //create two new parents for current person by recursively calling create_family
        p->parents[0] = create_family(generations - 1);
        p->parents[1] = create_family(generations - 1);

        //TODO: set parent pointer for current person
        

        //TODO: randomly assign current persons alleles based on alleles of their parents
        p->alleles[0] = p->parents[0]->alleles[rand() % 2];
        p->alleles[1] = p->parents[1]->alleles[rand() % 2];

    }

    //If there are no generations left to create
    else
    {
        //set parent pointer to null
        p->parents[0] = NULL;
        p->parents[1] = NULL;

        p->alleles[0] = random_allele();
        p->alleles[1] = random_allele();
    }

    //Return newly created person
    return p;
}


//Free p and all ancestors of p
void free_family(person *p)
{
    //Handle the base case
    if (p == NULL)
    {
        return;
    }
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    //free child
    free(p);
}

//print each family member and their alleles.
void print_family(person *p, int generation)
{
    //Handle base case
    if (p == NULL)
    {
        return;
    }

    //print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    //print person
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);        
    }
    else if (generation == 1)
    {
        printf("parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    //print parents of current generations
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

//Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}






















