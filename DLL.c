#include "DLL.h"

void MyDLLInit() {

}

int MyDLLInsert(struct Node *dll, uint16_t newKey, char* data, uint16_t size) {
    for (int i = 0; i < size; i++) {
        if (dll[i].key == 0) {
            dll[i].key = newKey;
            for (int j = 0; j < 8 && data[j] != '\0'; j++) {
                dll[i].data[j] = data[j];
            }
            dll[i].prev = NULL;
            dll[i].next = NULL;

            struct Node *current = dll;
            while (current != NULL) {
                if ((current->key > newKey && (current->next == NULL || current->next->key <= newKey)) 
                    || (current->key == newKey)) {
                    dll[i].next = current->next;
                    dll[i].prev = current;
                    if (current->next != NULL) {
                        current->next->prev = &dll[i];
                    }
                    current->next = &dll[i];
                    return 0;
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