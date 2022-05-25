#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    char data;
    struct List* next;
    
} List;

List *createNewElement(List *next, char charInsert);
void insertToQueue(List **Q, char charInsert);
void removeFromQueue(List **Q);

int main() {
    List *Q = NULL;
    char userInput;
    char character;
    
    printf("Enter 'i' to insert a new element, 'r' to remove an element, 'q' to quit: ");
    scanf(" %c", &userInput);
    while(userInput == 'r' || userInput == 'i' || userInput == 'q') {
        switch(userInput) {
            case 'i' :
                printf("Enter a character to be enqueued: ");
                scanf(" %c", &character);
                insertToQueue(&Q, character);
                break;
                
            case 'r' :
                removeFromQueue(&Q);
                break;
                
            case 'q' :
                return 0;
                break;
        }
        printf("Enter 'i' to insert a new element, 'r' to remove an element, 'q' to quit: ");
        scanf(" %c", &userInput);
    }
    
    return 0;
    
}

List *createNewElement(List *next, char charInsert) {
    List *newData = malloc(sizeof(List));
    
    newData->data = charInsert;
    newData->next = next;
    return newData;
}

void insertToQueue(List **Q, char charInsert) {
    List *newInput;
    
    if((*Q) == NULL) {
        newInput = createNewElement(NULL, charInsert);
        newInput->next = newInput;
        (*Q) = newInput;  
          
    } else {
        newInput = createNewElement((*Q)->next, charInsert); 
        newInput->next = (*Q)->next; 
        (*Q)->next = newInput; 
        (*Q) = newInput;  
        
    }
}

void removeFromQueue(List **Q) {
    List *temp;
    char charRemove;

    if((*Q) == NULL) {
        printf("Nothing to remove. Queue is empty\n");

    } else if((*Q)->next == (*Q)) {
        charRemove = (*Q)->data;
        (*Q) = NULL;
        printf("The character removed: '%c'\n", charRemove);

    } else {
        temp = (*Q)->next;
        charRemove = (*Q)->next->data;
        (*Q)->next = (*Q)->next->next;
        printf("The character removed: '%c'\n", charRemove);
        free(temp);

    }
}