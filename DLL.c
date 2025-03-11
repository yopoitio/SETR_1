#include "DLL.h"

void MyDLLInit() {

}

int MyDLLInsert(struct Node *dll, uint16_t newKey, char* data, uint16_t size) {
    for (int i = 0; i < size; i++) {
        if (dll[i].key != 0) {
            dll[i].key = newKey;
            dll[i].prev = -1;
            dll[i].next = -1;
        
            struct Node *current = dll;
            while (current->next != NULL)  {
                if ((current->key > newKey && current->next->key <= newKey) || (current->key == newKey)) {
                    current->next->prev = i;
                    current->prev->next = current
                }
                current = current->next;
            }
        }
    }

    printf("Array is full\n");
    return -1;
}

void MyDLLRemove() {

}

void MyDLLFind() {

}

void MyDLLFindNext(){

}

void MyDLLFindPrevious(){

}