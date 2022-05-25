#include <stdio.h>


#define MAX_SIZE 5

void insertArray(int array[MAX_SIZE], int *size, int *rear);
void removeArray(int array[MAX_SIZE], int *size, int *front);

int main(){
    int array[MAX_SIZE]; 
    int rear = 0;
    int front = 0;
    char userInput;
    int size = 0 ;
    
    printf("What do you want to do [i for insert, r for remove, q for quit] ");
    scanf("%c", &userInput);
    while(userInput == 'r' || userInput == 'i' || userInput == 'q') {
        if(userInput == 'q') {
            break;
    
        }
        if(userInput == 'i') {
            insertArray(array, &size, &rear);
    
    
        }
        if(userInput == 'r') {
            removeArray(array, &size, &front);
        
        }
        printf("What do you want to do [i for insert, r for remove, q for quit] ");
        scanf(" %c", &userInput);
    }
    

    return 0;
}

void insertArray(int array[MAX_SIZE], int *size, int *rear){
    int value = 0;
    
        if(*size >= MAX_SIZE) {
            printf("Can't insert, array is full \n");
            
        } else {
            printf("Enter an intger to insert: ");
            scanf("%d", &value);
            if(*rear == MAX_SIZE) {
                *rear = 0;
                
            }
            array[(*rear)++] = value;    
            (*size)++; 
        }
}


void removeArray(int array[MAX_SIZE], int *size, int *front){
    
        if(*size == 0){
            printf("Cannot remove, the queue is empty\n");

        } else if( *size > 0 && *size <= 5 ) {
            printf("%d removed from queue\n", array[*front]); 
            if(*front == MAX_SIZE) {
                *front = 0;
                
            }
            (*front)++;
            (*size)--;
        } 
}


