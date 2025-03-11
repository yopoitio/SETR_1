#ifndef DLL_H
#define DLL_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

struct Node {
    uint16_t key;
    char data[8];
    struct Node* prev;
    struct Node* next;
};

struct Node* MyDLLInit(uint16_t size);
void MyDLLInsert();
int MyDLLRemove(struct Node *dll, uint16_t key, int size);
char *MyDLLFind(struct Node *dll, uint16_t key);
void MyDLLFindNext();
void MyDLLFindPrevious();

#endif // DLL_H