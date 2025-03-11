#include "DLL.h"

struct Node* MyDLLInit(uint16_t size) {
    struct Node *dll = (struct Node*) malloc(sizeof(struct Node)*size);

    for(int i=0;i<size;i++) {
        dll[i].key = 0;
        dll[i].prev = NULL;
        dll[i].next = NULL;
        for(int j=0;j<8;j++) {
            dll[i].data[j] = '\0';
        }
    }
    printf("DLL initialized with size %d\n", size);

    return dll;
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

int MyDLLRemove(struct Node *dll, uint16_t key, int size) {
    for(int i=0;i<size;i++) {
        if(dll[i].key == key) {
            if(dll[i].prev != NULL) {
                dll[i].prev->next = dll[i].next;
            }
            if(dll[i].next != NULL) {
                dll[i].next->prev = dll[i].prev;
            }
            dll[i].key = 0;
            for(int j=0;j<8;j++) {
                dll[i].data[j] = '\0';
            }
            printf("Key %d removed\n", key);
            return 0;
        }
    }
    printf("Key %d not found\n", key);
    return -1;
}

void MyDLLFind() {

}

void MyDLLFindNext(){

}

void MyDLLFindPrevious(){

}