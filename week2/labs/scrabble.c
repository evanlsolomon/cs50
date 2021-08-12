#include <ctype.h>
// #include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char *word);

int main(void)
{
    // Get input words from both players
    printf("Player 1: ");

    char str1[20];
    scanf("%s",str1);
    printf("%s \n",str1);

    printf("Player 2: ");
    
    char str2[20];
    scanf("%s",str2);
    printf("%s \n",str2);

    // Score both words
    int score1 = compute_score(str1);
    int score2 = compute_score(str2);
   
    printf("Player 1 Score: %d \n", score1 );
    printf("Player 2 Score: %d \n", score2 );

    // TODO: Print the winner
    if(score1 == score2){
        printf("Tie! \n");
    }else{
        int winner = (score1 > score2) ? 1 : 2;
        printf("Player %d wins! \n", winner);
    }
    return 0;
}

int compute_score(char *word)
{
    int score = 0;
    int len = strlen(word);

    for(int i = 0; i < len; i++){
        if( (word[i] >= 65 && word[i] <=90) || (word[i]>=97 && word[i] <= 122) ){
            int alphaIndex = (int) toupper(word[i]) - 65;
            score+=POINTS[alphaIndex];
        }else {
            continue;
        }
    }
    return score;
}
