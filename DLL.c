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
        if (dll[i].key == 0) {
            dll[i].key = newKey;
            for (int j = 0; j < 8 && data[j] != '\0'; j++) {
                dll[i].data[j] = data[j];
            }
            dll[i].prev = NULL;
            dll[i].next = NULL;

            struct Node *current = dll;
            while (current->next != NULL) {
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

char *MyDLLFind(struct Node *dll, uint16_t key) {
    struct Node *current = dll;
    while (current->next != NULL) {
        if (current->key == key) {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

void MyDLLFindNext(){

}

void MyDLLFindPrevious(){

}

void MyDLLPrint(struct Node *dll, int size) {
    struct Node *current = dll;
    printf("DLL: ");
    while (current->next != NULL) {
        printf("%d:%s -> ", current->key, current->data);
        current = current->next;
    }
    printf("NULL\n");
}