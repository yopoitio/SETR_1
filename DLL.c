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
    bool isEmpty = true;
    for (int i = 0; i < size; i++) {
        if (dll[i].key != 0) {
            isEmpty = false;
            break;
        }
    }

    if (dll[0].key == 0 && isEmpty) {
        dll[0].key = newKey;
        strcpy(dll[0].data, data);
        dll[0].prev = NULL;
        dll[0].next = NULL;
        printf("Element added with key %d\n", newKey);
        return 0;
    }

    int position = -1;
    for (int i = 0; i < size; i++) {
        if (dll[i].key == 0) {
            position = i;
            break;
        }
    }

    if (position == -1) {
        printf("Array is full!\n");
        return -1;
    }

    dll[position].key = newKey;
    strcpy(dll[position].data, data);
    dll[position].prev = NULL;
    dll[position].next = NULL;

    struct Node *current = &dll[0];
    struct Node *previous = NULL;

    while (current != NULL) {
        if (current->key > newKey) {
            break;
        }
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        dll[position].next = current;
        if (current != NULL) {
            current->prev = &dll[position];
        }
        return 0;
    }

    dll[position].prev = previous;
    dll[position].next = current;
    if (previous != NULL) {
        previous->next = &dll[position];
    }
    if (current != NULL) {
        current->prev = &dll[position];
    }

    printf("Element added with key %d\n", newKey);
    return 0;
}


int MyDLLRemove(struct Node *dll, uint16_t key, uint16_t size) {
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
            printf("Element removed with key %d\n", key);
            return 0;
        }
    }
    printf("Key %d not found\n", key);
    return -1;
}

char *MyDLLFind(struct Node *dll, uint16_t key, uint16_t size) {
    for(int i=0;i<size;i++) {
        if(dll[i].key == key) {
            return dll[i].data;
        }
    }
    return NULL;
}

void MyDLLFindNext(){

}

char* MyDLLFindPrevious(struct Node *dll, uint16_t key) {
    struct Node *current = dll;
    while (current->next!= NULL) {
        if (current->key == key) {
            return current->prev->data;
        }
        current = current->next;
    }
    printf("Error: The previous element was not found.\n");
    return "";
}

void MyDLLPrint(struct Node *dll, uint16_t size) {
    struct Node *current = dll;
    uint16_t smallerkey = UINT16_MAX;

    for(int i=0;i<size;i++) {
        if(dll[i].key!= 0 && dll[i].key < smallerkey) {
            smallerkey = dll[i].key;
            current=&dll[i];
        } 
    }

    if(smallerkey==UINT16_MAX) {
        printf("DLL Empty\n\n");
        return;
    }

    printf("DLL: ");

    while (current != NULL) {
        printf("%d:%s -> ", current->key, current->data);
        current = current->next;
    }
    
    printf("NULL\n\n");
}