# include <stdio.h>
#include <string.h>
#include<ctype.h>
#include <math.h>

int countLetters(char str[]);
int countWords(char str[]);
int countSentences(char str[]);

int main() {
    printf("please enter your text:");

    char inpstring[1000];
    fgets(inpstring, sizeof(inpstring), stdin);  // read string
    // printf("you entered: ");
    // puts(inpstring);

    // printf("Number of letter(s): %d \n", countLetters(inpstring));
    // printf("Number of word(s): %d \n", countWords(inpstring));
    // printf("Number of sentence(s): %d \n", countSentences(inpstring));
    
    float index = 
        (
            0.0588 * (float)countLetters(inpstring)/((float)countWords(inpstring)/100) - 
            0.296 * (float)countSentences(inpstring)/((float)countWords(inpstring)/100) - 
            15.8
        );
    printf("Recommended reading for Grade %d \n", (int) round(index));
    return 0;
}

int countLetters(char str[]){
    int letterCount=0;
    for(int i =0; i<strlen(str); i++){
        if(isalpha(str[i])){
            letterCount++;
        } 
    }
    return letterCount;
}

int countWords(char str[]){
    int wordCount=1;
    for(int i=0; i< strlen(str); i++){
        if (str[i] == ' '){
            wordCount++;
        }
    }
    return wordCount;
}

int countSentences(char str[]){
    int sentenceCount=0;
    for(int i=0; i< strlen(str); i++){
        if (str[i] == '.'|| str[i] == '?' || str[i] == '!'){
            sentenceCount++;
        }
    }
    return sentenceCount;
}