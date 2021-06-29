#include <stdio.h>

void printTopdownBlocks(int levelsPrinted, int mountainHeight);

int main()
{
    int height;

    printf("Enter height for mario mountain.\n");
    scanf("%d", &height);
    printf("Height entered: %d\n", height);
    printTopdownBlocks(0, height);
    
    return 0;
}

 void printTopdownBlocks(int levelsPrinted, int mountainHeight){
    if(levelsPrinted < mountainHeight){
        for(int i = 0; i<=(mountainHeight - levelsPrinted); i++){   
            printf(" ");
        }
        for(int i = 0; i<=levelsPrinted; i++){   
            printf("#");
        }
        printf(" ");
        for(int i = 0; i<=levelsPrinted; i++){   
            printf("#");
        }
        printf("\n");
        printTopdownBlocks(levelsPrinted+1, mountainHeight);
    } 
    return;
 }
