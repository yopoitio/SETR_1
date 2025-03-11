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

void MyDLLInit();
void MyDLLInsert();
void MyDLLRemove();
void MyDLLFind();
void MyDLLFindNext();
void MyDLLFindPrevious();

#endif // DLL_H