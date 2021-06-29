#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

char* scrubString(char rawstring[]);
bool checksum(char processedInput[]);

int main(){

    char inpstring[30];

    printf("Enter a credit card number: \n");
    scanf("%s", inpstring);

    printf("you entered: %s\n", inpstring);
    printf("which happens to be %ld characters long.\n", strlen(inpstring) );
  
    char* scrubbedString = scrubString(inpstring);

    printf("String scrubbed printing from MAIN: %s\n", scrubbedString);
    printf("checksum passes: %d\n",checksum(scrubbedString));

    return 0;

}


char* scrubString(char rawString[]){
    int i , j;
    static char cleanString[30];
    for (i=j=0; rawString[i] != '\0' ; ++i){
        if( isdigit(rawString[i]) ){
            cleanString[j]= rawString[i]; 
            j++;
        }
    }
    cleanString[j] = '\0';
    return cleanString;
}

bool checksum(char processedInput[]){
    int lengthOfCNum = strlen(processedInput);

    int firstGroup[ ((lengthOfCNum/2) + lengthOfCNum%2) ];
    int multiplyByTwoGroup[(lengthOfCNum - sizeof(firstGroup)/ sizeof(firstGroup[0]))];

    int firstInd = 0; 
    int secondInd = 0;
    for (int i =0; i<lengthOfCNum; i++){
        if( (lengthOfCNum-i) % 2 != 0){
            firstGroup[firstInd] = processedInput[i]-'0';
            firstInd++;
        }else {
            multiplyByTwoGroup[secondInd] = processedInput[i]-'0';
            secondInd++;
        }
    }

    int sumOfFirstGroup=0;
    printf("first group: ");
    for(int i=0; i< sizeof(firstGroup)/ sizeof(firstGroup[0]); i++){
        sumOfFirstGroup += firstGroup[i];
        printf("%d, ", firstGroup[i]);
    }
    printf("\n");



    int sumOfMultiplyGroup=0;
    printf("multiply by two group: ");
    for(int i=0; i< sizeof(multiplyByTwoGroup)/ sizeof(multiplyByTwoGroup[0]); i++){
        multiplyByTwoGroup[i] = multiplyByTwoGroup[i]*2;
        sumOfMultiplyGroup += (multiplyByTwoGroup[i]/10)+(multiplyByTwoGroup[i]%10);
        printf("%d, ", multiplyByTwoGroup[i]);
    }
    printf("\n");

    printf("sum of both groups: %d\n", sumOfMultiplyGroup+sumOfFirstGroup);

    // printf("Length of simple add group: %lu\n", sizeof(firstGroup)/ sizeof(firstGroup[0]));
    // printf("Length of *2 group: %lu\n", sizeof(multiplyByTwoGroup)/ sizeof(multiplyByTwoGroup[0]));


    return ( (sumOfFirstGroup+sumOfMultiplyGroup)%10==0 );
}