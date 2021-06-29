#include <stdio.h>
#include <string.h>

int main(void){
    // int i;
    // int j;

    // printf("Enter i: \n");
    // scanf("%d", &i);
    // printf("Enter j: \n");
    // scanf("%d", &j);

    // if(i==j){
    //     printf("Same\n");
    // }else{
    //     printf("Different\n");
    // }


    char first[20];
    char second[20];

    printf("Enter first string:\n");
    scanf("%s", first);

    printf("Enter second string:\n");
    scanf("%s", second);

    // printf("%s\n", first);
    // printf("%s\n", second);

    if(strcmp(first,second) == 0){
        printf("Same\n");
    }else {
        printf("Different\n");
    }


}