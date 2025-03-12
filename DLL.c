#include "DLL.h"

struct Node *trashbin;
uint8_t index_ = 0;

struct Node* MyDLLInit(uint16_t size) {
    struct Node *dll = (struct Node*) malloc(sizeof(struct Node)*size);
    trashbin = (struct Node*) malloc(sizeof(struct Node)*TRASH_SIZE);

    for(int i=0;i<size;i++) {
        dll[i].key = 0;
        dll[i].prev = NULL;
        dll[i].next = NULL;
        for(int j=0;j<DATA_SIZE;j++) {
            dll[i].data[j] = '\0';
        }
    }
    printf("DLL initialized with size %d\n", size);
    return dll;
}

void MyDLLInsert(struct Node *dll, uint16_t newKey, char* data, uint16_t size) {
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
        return;
    }

    int position = -1;
    for (int i = 0; i < size; i++) {
        if (dll[i].key == 0) {
            position = i;
            break;
        }
    }

    if (position == -1) {
        printf("DLL is full! Couldn't insert the element!\n");
        return;
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
        return;
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
    return;
}


void MyDLLRemove(struct Node *dll, uint16_t key, uint16_t size) {
    for(int i=0;i<size;i++) {
        if(dll[i].key == key) {
            bool found = false;
            for(int j=0;j<TRASH_SIZE;j++) {
                if(trashbin[j].key == dll[i].key) {
                    trashbin[j] = dll[i];
                    found = true;
                    break;
                }
            }
            if(!found)
                trashbin[index_++ % 5] = dll[i];
                

            if(dll[i].prev == NULL) 
                dll[i].next->prev = NULL;
            else
                dll[i].next->prev = dll[i].prev;

            if(dll[i].next == NULL)
                dll[i].prev->next = NULL;
            else
                dll[i].prev->next = dll[i].next;


            dll[i].key = 0;
            for(int j=0;j<DATA_SIZE;j++) {
                dll[i].data[j] = '\0';
            }
            printf("Element removed with key %d\n", key);
            return;
        }
    }
    printf("Key %d not found\n", key);
    return;
}

char *MyDLLFind(struct Node *dll, uint16_t key, uint16_t size) {
    for(int i=0;i<size;i++) {
        if(dll[i].key == key) {
            return dll[i].data;
        }
    }
    return NULL;
}

char* MyDLLFindNext(struct Node *dll, uint16_t key) {
    struct Node *current = dll;
    while (current != NULL) {
        if (current->next == NULL) {
            printf("Error: The last element does not have a next one.\n");
            return "";
        }
        if (current->key == key) {
            return current->next->data;
        }
        current = current->next;
    }
    printf("Error: The element with the given key was not found.\n");
    return "";
}

char* MyDLLFindPrevious(struct Node *dll, uint16_t key) {
    struct Node *current = dll;
    while (current != NULL) {
        if (current == dll) {
            printf("Error: The first element does not have a previous one.\n");
            return "";
        }
        if (current->key == key) {
            return current->prev->data;
        }
        current = current->next;
    }
    printf("Error: The element with the given key was not found.\n");
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

void MyDLLRestore(struct Node *dll, uint16_t key, uint16_t size) {
    for(int i=0;i<TRASH_SIZE;i++) {
        if(trashbin[i].key == key) {
            for(int j=0;j<size;j++) {
                if(trashbin[i].key == dll[j].key) {
                    dll[j].key = trashbin[i].key;
                    strcpy(dll[j].data, trashbin[i].data);
                    printf("Element added with key %d\n", key);
                    return;
                }
            }

            MyDLLInsert(dll, trashbin[i].key, trashbin[i].data, size);
            return;
        }
    }
    printf("Key %d not found in trashbin\n", key);
}