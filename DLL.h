#ifndef DLL_H
#define DLL_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    uint16_t key;
    char data[8];
    struct Node* prev;
    struct Node* next;
};

struct Node* MyDLLInit(uint16_t size);
int MyDLLInsert(struct Node *dll, uint16_t newKey, char* data, uint16_t size);
int MyDLLRemove(struct Node *dll, uint16_t key, int size);
char *MyDLLFind(struct Node *dll, uint16_t key);
void MyDLLFindNext();
char *MyDLLFindPrevious(struct Node *dll, uint16_t key);
void MyDLLPrint(struct Node *dll, int size);

#endif // DLL_H