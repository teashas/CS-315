#include <stdio.h>
#include <stdlib.h>
typedef struct BTN {
  char key;
  int frequency;
  struct BTN* left;
  struct BTN* right;
} BTN;
#define MAXSIZE 16
typedef struct Heap {
  BTN* heap[MAXSIZE];
  int size;
} Heap; 

BTN* getNewNode(char data, int frequency);
void insertHeap(char key, Heap* heapPtr);
BTN* removeHeap(Heap* heapPtr);
void bubble(Heap* heapPtr);
void sift(Heap* heapPtr);
void inOrder(BTN *ptr);
void preOrder(BTN *ptr);
BTN* createTree(Heap* heapPtr);

int main(void) {
  BTN *root = NULL;
  Heap newHeap;
  newHeap.size = 0;
  char newKey;
  printf("Enter a character (enter a '$' to stop entering characters): ");
  scanf(" %c", &newKey);
  while (newKey != '$'){
    insertHeap(newKey, &newHeap);
    printf("\nEnter a character (enter a '$' to stop entering characters): ");
    scanf(" %c", &newKey);
  }
  root = createTree(&newHeap);
  printf("\n\nThe nodes of the Huffman tree pre-Order are: \n");
  preOrder(root);
  printf("\n\nThe nodes in in-Order are: \n");
  inOrder(root);
  printf("\n");
  return 0;
}

BTN* getNewNode(char data, int frequency) {
  struct BTN* newNode = (BTN*)malloc(sizeof(BTN));
  newNode->key = data;
  newNode->frequency = frequency;
  newNode->right = NULL;
  newNode->left = NULL;
  return newNode;
}

void insertHeap(char key, Heap* heapPtr) {
  struct BTN *tempPtr;
  int frequency = 0;
  
  printf("Enter '%c's frequency: ", key);
  scanf(" %d", &frequency);
  tempPtr = getNewNode(key, frequency);
  heapPtr->size++;
  heapPtr->heap[heapPtr->size] = tempPtr;
  if (heapPtr->size > 1) {
    bubble(heapPtr);
  }
}
  
void bubble(Heap* heapPtr) {
  struct BTN *swapPtr;
  int i = heapPtr->size;
  int parent = i / 2;
  int done = 0;
  while (done != 1) {
    if (parent != 0) {
      if (heapPtr->heap[i]->frequency < heapPtr->heap[parent]->frequency) {
        swapPtr = heapPtr->heap[i];
        heapPtr->heap[i] = heapPtr->heap[parent];
        heapPtr->heap[parent] = swapPtr;
        i = parent;
        parent = i / 2;
      }
      else
        done = 1;
    }
    else
      done = 1;
  }
}

void sift(Heap* heapPtr) {
  struct BTN* swapPtr;
  int i = 1;
  int c1 = 2;
  int c2 = 3;
  int c = 0;
  int nodesLeft = heapPtr->size - 1; 
  int done = 0;
  
  while (done != 1) {
    if ((nodesLeft == 0) || (nodesLeft == -1)) {
      done = 1;
    } else if (nodesLeft == 1) {
      c = c1;
      if (heapPtr->heap[i]->frequency > heapPtr->heap[c]->frequency) {
        swapPtr = heapPtr->heap[i];
        heapPtr->heap[i] = heapPtr->heap[c];
        heapPtr->heap[c] = swapPtr;
        done = 1;
      } else {
        done = 1;
      }
  } else if (nodesLeft == 2) {
    if (heapPtr->heap[c1]->frequency < heapPtr->heap[c2]->frequency) {
      c = c1;
    } else {
      c = c2;
    }
    nodesLeft--;
    if (heapPtr->heap[i]->frequency > heapPtr->heap[c]->frequency) {
      swapPtr = heapPtr->heap[i];
      heapPtr->heap[i] = heapPtr->heap[c];
      heapPtr->heap[c] = swapPtr;
      i = c;
      c = c / 2;
    } else {
      done = 1;
    }
  } else {
    if (heapPtr->heap[c1]->frequency < heapPtr->heap[c2]->frequency) {
      c = c1;
    } else {
      c = c2;
    }
    nodesLeft--; 
    if (heapPtr->heap[i]->frequency > heapPtr->heap[c]->frequency) {
      swapPtr = heapPtr->heap[i];
      heapPtr->heap[i] = heapPtr->heap[c];
      heapPtr->heap[c] = swapPtr;
      i = c;
      c1 = i * 2;
      c2 = c1 + 1;
      nodesLeft--; 
    } else {
      done = 1;
    }
  }
  }
}

void inOrder(BTN* ptr) {
  if (ptr != NULL) {
    inOrder(ptr->left);
    printf(" %c %d\n", ptr->key, ptr->frequency);
    inOrder(ptr->right);
  }
}

void preOrder(BTN* ptr) {
  if (ptr != NULL) {
    printf(" %c %d\n", ptr->key, ptr->frequency);
    preOrder(ptr->left);
    preOrder(ptr->right);
  }
}

BTN* createTree(Heap* heapPtr) {
  int frequency = 0;
  
  while (heapPtr->size != 1) {
    BTN* remove = removeHeap(heapPtr);
    BTN* Remove = removeHeap(heapPtr);
    frequency = remove->frequency + Remove->frequency;
    BTN* newNode = getNewNode('-', frequency);
    newNode->left = remove;
    newNode->right = Remove;
    heapPtr->size++;
    heapPtr->heap[heapPtr->size] = newNode;
    if (heapPtr->size > 1) {
      bubble(heapPtr);
    }
  }
    BTN* root = heapPtr->heap[1];
    return root;
}

BTN* removeHeap(Heap* heapPtr) {
  BTN* remove = heapPtr->heap[1];
  heapPtr->heap[1] = heapPtr->heap[heapPtr->size];
  heapPtr->size--;
  sift(heapPtr);
  return remove;
}