#define BST_H

#include <stdio.h>
#include <stdlib.h>

struct BTN {
	char data; 
	char string[11];
	struct BTN* left; 
	struct BTN* right; 
};


struct stack {
	struct BTN* tree; 
	struct stack* next; 
};

struct BTN* newNode();
int insert(struct BTN** node, char value, char string[]);
void push(struct BTN** temp, struct stack** top);
struct BTN* pop(struct stack** top);
int inOrder(struct BTN** node);
void preOrder(struct BTN** node);
int find(struct BTN** temp, char value);

int main() {
	struct BTN* root = NULL;
	while (1) {
		char userSelection, val;
		char string[11];
		printf("Enter choice (lower case is also acceptable) --- (I)nsert, (F)ind, (Q)uit: ");
		scanf(" %c", &userSelection);
		userSelection = toupper(userSelection);
		printf("\n");

		switch (userSelection)	{
		case 'I':
			printf("Enter new node's key value: ");
			scanf(" %c", &val);
			val = toupper(val);
			getchar(); 
			printf("\nEnter string of up to 10 characters for '%c's data: ", val);
			scanf("%s", string);
			fgets(string, sizeof(string), stdin);
			insert(&root, val, string);
			preOrder(&root);
      inOrder(&root);
      printf("\n\n");
			break;
		case 'F':
			printf("Enter the search key: ");
			scanf(" %c", &val);
			val = toupper(val);
			find(&root, val);
			break;
		case 'Q':
			return 0;
			break;
		default:
			break;
		}
	}
}

struct BTN* newNode() {
	struct BTN* temp = (struct BTN*)malloc(sizeof(struct BTN));
	temp->left = temp->right = NULL;
	return temp;
}

int insert(struct BTN** node, char value, char string[]) {
	if (*node == NULL) {
		struct BTN* temp = newNode();
		temp->data = value;
		int i;
		for (i = 0; string[i-1] != '\0'; i++)
			temp->string[i] = string[i];
		printf("string is %s\n", temp->string);
		*node = temp;
		return 0;
	}

	struct BTN* temp = *node;
	while (1)
		if (value <= temp->data) {
			if (temp->left == NULL) {
				temp->left = newNode();
				temp->left->data = value;
				int i;
				for (i = 0; string[i - 1] != '\0'; i++)
					temp->left->string[i] = string[i];
				return 0;
			} else
				temp = temp->left;
		}
		else if (value > temp->data) {
			if (temp->right == NULL) {
				temp->right = newNode();
				temp->right->data = value;
				int i;
				for (i = 0; string[i - 1] != '\0'; i++)
					temp->right->string[i] = string[i];
				return 0;
			}
			else
				temp = temp->right;
		}
}

void push(struct BTN** tempTrvPtr, struct stack** top) {
	struct stack* push = (struct stack*)malloc(sizeof(struct stack));
	push->tree = *tempTrvPtr;
	push->next = *top;
	*top = push;
}

struct BTN* pop(struct stack** top) {
	struct stack* tempTop;
	struct BTN* tempBTN;

	tempTop = *top;
	tempBTN = tempTop->tree;
	*top = tempTop->next;
	free(tempTop);
	return tempBTN;
}


int inOrder(struct BTN** node) {
	struct BTN* trvPtr = *node;
	struct stack* stack = NULL;
	printf("\nInorder traversal is: ");
	while (1) {
		if (trvPtr != NULL) {
			push(&trvPtr, &stack);
			trvPtr = trvPtr->left;
		} else {
			if (stack != NULL) {
				trvPtr = pop(&stack);
				printf("%c ", trvPtr->data);
				trvPtr = trvPtr->right;
			}
			else
				return 0;
		}
	}
}


void preOrder(struct BTN** root) {
	struct BTN* trvPtr = *root;
	struct stack* stack = NULL;
	int done = 0;
	printf("\nPre-order traversal is: ");
	while (!done) {
		while (trvPtr != NULL) {
			printf("%c ", trvPtr->data);
			if (trvPtr->left != NULL) {
				push(&trvPtr, &stack);
				trvPtr = trvPtr->left;
			} else
				trvPtr = trvPtr->right;
		}
		if (stack != NULL) {
			trvPtr = pop(&stack);
			trvPtr = trvPtr->right;
		} else
			done = 1;
	}
}

int find(struct BTN** search, char value) {
	struct BTN* find = (struct BTN*)malloc(sizeof(struct BTN));
	find = *search;
	printf("\n");
	while (1) {
		if (find->data == value) {
			printf("Found the string '%s' there \n\n", find->string);
			return 0;
		} else if (value < find->data) {
			if (find->left == NULL) {
				printf("'%c' is not in the tree\n\n", value);
				return 0;
			} else
				find = find->left;
		} else {
			if (find->right == NULL)	{
				printf("'%c' is not in the tree\n\n", value);
				return 0;
			} else
				find = find->right;
		}
   }
}