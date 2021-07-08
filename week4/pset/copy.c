#include<stdio.h>
#include<string.h>
#include <ctype.h>

int main(void){
   
    char s[20];
    printf("Enter s:");
    scanf("%s", s);
    
    char *t = s;


    t[0] = toupper(t[0]);

    printf("s:%s\n", s);
    printf("t:%s\n", t);
}