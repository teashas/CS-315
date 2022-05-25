#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList {
    int value;
    struct linkedList* next;
}linkedList;

void List(int validValue);
void traverse();
void deletion();

linkedList *first = NULL, *tempVal, *sorting;
int input = 0;

int main() {
  int validValue;
  List(validValue);
  deletion();
 
  return 0;
}

void List(int data){
    int input = 0;
    tempVal=malloc(sizeof(linkedList));
   
    printf("Enter an integer: ");
    scanf("%d", &input);
    
    if(input==0) {
      printf("Your list is empty.\n");
      exit(0); 
    }
    
    while(input!=0) {
        (tempVal->value=input);
        
        if(first==NULL || first->value >= tempVal->value) {
            (tempVal->next)=first;
            first=tempVal;     
        } else {  
            sorting=first;
            
            while(sorting->next != NULL && sorting->next->value < tempVal->value) {
                sorting=sorting->next;   
            }
            tempVal->next=sorting->next;
            sorting->next=tempVal;
            
        }  
        tempVal=malloc(sizeof(linkedList));
        printf("Enter an integer: ");
        scanf("%d", &input);
    }
}

void deletion() {

    printf("OK, here's your list in numeric order: ");
    linkedList *traverse = first;
    
    while((traverse->next) != NULL) {
        printf("%d -> ", traverse->value);
        traverse = (traverse->next);
    }
      
    printf("%d\n", (traverse->value));

    linkedList *Delete;
    printf("What do you want to delete? ");
    scanf("%d", &input);
    while(input != 0) {
    
        if (first == NULL) {
            printf("Can’t delete %d from an empty list.\n", input);
        } else if ((first->value) == input) {
        
            if(first->next == NULL) {
                break;
            }
            first = (first->next);
        } else {
            Delete = first;
            
            while ((Delete->next != NULL) && ((Delete->next->value) !=  input)) {
                Delete = (Delete->next);
            }
            
            if (Delete->next == NULL) {
                printf("Can't delete, %d isn't in the list\n", input);
            } else {
                ((Delete->next) = (Delete->next)->next);
                
            }
        }
       printf("OK, here's your list in numeric order: ");
       traverse=first;
        
        while(traverse->next != NULL) {
            printf("%d -> ", traverse->value);
            traverse = (traverse->next);
        }  
        printf("%d\n", (traverse->value));
        printf("What do you want to delete? ");
        scanf("%d", &input);
    }
       
    printf("Bye.\n");  
}