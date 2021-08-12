# include <stdio.h>
# include <string.h>
# include <stdbool.h>
#include <ctype.h>

void validateKey(char usrInp[]);
char* charsCheck(char usrInp[]);

int main(int argc, char *argv[])
{
    // const char *KEY[26];
    /* code */
    // char key[26];

    // printf("Please enter your 26 character key for the substitution ciper:\n");
    // fgets(key, sizeof(key), stdin);

    // printf("You entered: ");
    // puts(key);
    // printf(" as your key.\n");

    // for(char i = 0; i < sizeof(key); i++){
    //     printf("char # %i is %c \n" , (i+1), *(key+i));
    // }
    validateKey(argv[1]);
        // build cipher text

    return 0;
}




// Validate command line argument argv[1]:
// if invalid print messages
void validateKey(char usrInp[]){
    

    //  check that it is 26 letters long with no whitespace
    int lengthCheck = strlen(usrInp) == 26;
    printf("%s \n", lengthCheck ? "Key is 26 characters long (correct)" : "Error: Key must contain 26 characters.");
    
    //  check that chars are only letters amd distinct
    char* charsAreValid = charsCheck(usrInp);
    printf("charsAreValid: %s\n", charsAreValid);

    printf("Usage: ./substitution key \n");

}

char* charsCheck(char usrInp[]){

    int asciiKey[256] = {0};
    int isUnique = 1;
    int allAlpha = 1;

    // For each letter, check for:
    for (int i = 0; i < strlen(usrInp); i++){
        // not a letter character
        if( !isalpha(usrInp[i]) ){
            allAlpha *= isalpha(usrInp[i]);
            printf("Error: The key must contain all alphabetic characters. \n");
        }

        // a character distint from previous characters
        if( asciiKey[(int) usrInp[i]] == 0 ){
            asciiKey[(int) usrInp[i]] = 1;
        }else{
            isUnique *= 0;
            printf("Error: The key must contain all unique letters \n");
            break;
        }
    }
    return( (allAlpha && isUnique) ? "true" : "false");
}