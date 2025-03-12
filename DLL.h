#ifndef DLL_H
#define DLL_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define DATA_SIZE 20
#define TRASH_SIZE 5

struct Node {
    uint16_t key;
    char data[DATA_SIZE];
    struct Node* prev;
    struct Node* next;
};

struct Node* MyDLLInit(uint16_t size);
void MyDLLInsert(struct Node *dll, uint16_t newKey, char* data, uint16_t size);
void MyDLLRemove(struct Node *dll, uint16_t key, uint16_t size);
char *MyDLLFind(struct Node *dll, uint16_t key, uint16_t size);
void MyDLLFindNext();
char *MyDLLFindPrevious(struct Node *dll, uint16_t key);
void MyDLLPrint(struct Node *dll, uint16_t size);
void MyDLLRestore(struct Node *dll, uint16_t key, uint16_t size);

#endif // DLL_H