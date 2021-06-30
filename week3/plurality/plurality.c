// #include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    char * name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(char* name);
void print_winner(void);

int main(int argc, char* argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count;
    printf("Number of voters: ");
    scanf("%d", &voter_count);

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {

        char name[30];
        printf("Vote: ");
        scanf("%s", name);
        
        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(char *name)
{
    bool result = false; //return value

    //loop through candidates to check for a match
    for(int i = 0; i < candidate_count; i++){
        if (strcmp(name,candidates[i].name) == 0){
             result = true;
             candidates[i].votes++;
             break;
        }
    }

    return result;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //identify the winning amount of votes
    int winning_total = 0;
    for(int i=0; i<candidate_count; i++){
        if(candidates[i].votes > winning_total){
            winning_total = candidate_count;
        }
    }

    //print all candidates with the winning amount of votes
    printf("Winning candidate(s)!: \n");
    for(int i = 0; i < candidate_count; i++){
        if(candidates[i].votes == winning_total){
            printf("%s \n", candidates[i].name);
        }
    }

    return;
}

