#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void){
   
    char s[20];
    printf("Enter s:");
    scanf("%s", s);
    
    //allocate the memory of strlen+1 bytes for t
    char *t = malloc(strlen(s)+1);

    //copy characters of s into t
    // for(int i=0; i<=strlen(s); i++){
    //     t[i] = s[i];
    // }
    strcpy(s,t);


    if(strlen(t)>0){
        t[0] = toupper(t[0]);
    }

    printf("s:%s\n", s);
    printf("t:%s\n", t);

    free(t);
}