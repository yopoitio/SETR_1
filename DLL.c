#include "DLL.h"

/** 
 * @file DLL.c
 * @brief Implementation of a Doubly Linked List (DLL) module.
 *
 * This module provides an implementation of a doubly linked list 
 * with functionalities like insert, remove, search, and restore node. 
 * The list contains a set of nodes ordered by their key, allowing an efficient 
 * way of navigation and manipulation the elements.
 * 
 * The list data structure consists of nodes that contains a key (`key`), 
 * a data array (`data`), and pointers to the previous and next node.
 *
 * @author 107465 Rafael Almeida
 * @author 107838 Afonso Vaz
 * @date March 14, 2025
 * @bug No known bugs.
 * @version 1.0
 */

struct Node *trashbin;
uint8_t index_ = 0;

struct Node* MyDLLInit(uint16_t size) {
    struct Node *dll = (struct Node*) malloc(sizeof(struct Node)*size);
    trashbin = (struct Node*) malloc(sizeof(struct Node)*TRASH_SIZE);

    for (int i = 0; i < size; i++) {
        dll[i].key = 0;
        dll[i].prev = NULL;
        dll[i].next = NULL;
        for(int j = 0;j < DATA_SIZE; j++) {
            dll[i].data[j] = '\0';
        }
    }
    printf("DLL initialized with size %d\n", size);
    return dll;
}

void MyDLLInsert(struct Node *dll, uint16_t newKey, char* data, uint16_t size) {
    if (newKey == 0) {
        printf("Key cannot be zero!\n");
        return;
    }
    
    for (int i = 0; i < size; i++) {
        if (dll[i].key == newKey) {
            printf("Key already exists! Element not added.\n");
            return;
        }
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

    dll[position].prev = NULL;
    dll[position].next = NULL;

    int smallestKey = size;
    int smallestIndex = 0;
    for (int i = 0; i < size; i++) {
        if (dll[i].key != 0 && dll[i].key < smallestKey) {
            smallestKey = dll[i].key;
            smallestIndex = i;
        }
    }

    struct Node* current = dll;
    struct Node* previous = NULL;
    struct Node* end = NULL;
    while (current != NULL) {
        if (current->next == NULL) end = current;
        current = current->next;
    }

    if (smallestKey > newKey) {
        dll[position].prev = NULL;
        if (smallestIndex > position) {
            dll[position].next = &dll[smallestIndex];
            dll[smallestIndex].prev = &dll[position];
        }
    } else if ((smallestKey < newKey) && (end->key > newKey)) {
        for (int i = 0; i < size; i++) {
            if (dll[i].key != 0 && dll[i].key > newKey) {
                if (previous != NULL) dll[position].prev = previous;
                dll[position].next = &dll[i];
                dll[i].prev = &dll[position];
                previous->next = &dll[position];
                break;
            }
            if (dll[i].key != 0) previous = &dll[i];
        }
    } else {
        dll[position].prev = end;
        dll[position].next = NULL;
        end->next = &dll[position];
    }

    dll[position].key = newKey;
    strcpy(dll[position].data, data);
    printf("Element added with key %d\n", newKey);
}


void MyDLLRemove(struct Node *dll, uint16_t key, uint16_t size) {
    for (int i = 0; i < size; i++) {
        if (dll[i].key == key) {
            bool found = false;
            for (int j = 0; j < TRASH_SIZE; j++) {
                if (trashbin[j].key == dll[i].key) {
                    trashbin[j] = dll[i];
                    found = true;
                    break;
                }
            }
            if (!found) {
                trashbin[index_] = dll[i];
                index_ = (index_ + 1) % TRASH_SIZE;
            }

            if (dll[i].prev == NULL) {
                if (dll[i].next != NULL) {
                    dll[i].next->prev = NULL;
                    dll[i].next = NULL;
                }
            } else {
                dll[i].prev->next = dll[i].next;
            }

            if (dll[i].next == NULL) {
                if (dll[i].prev != NULL)
                    dll[i].prev->next = NULL;
            } else {
                dll[i].next->prev = dll[i].prev;
            }

            dll[i].key = 0;
            for (int j = 0; j < DATA_SIZE; j++) {
                dll[i].data[j] = '\0';
            }
            printf("Element removed with key %d\n", key);
            dll[i].prev = NULL;
            dll[i].next = NULL;
            return;
        }
    }
    printf("Key %d not found\n", key);
    return;
}

char *MyDLLFind(struct Node *dll, uint16_t key, uint16_t size) {
    for (int i=0; i < size; i++) {
        if (dll[i].key == key) {
            return dll[i].data;
        }
    }
    return NULL;
}

char* MyDLLFindNext(struct Node *dll, uint16_t key) {
    struct Node *current = dll;
    while (current != NULL) {
        if (current->next == NULL) {
            printf("Error: The last element does not have a next one\n");
            return NULL;
        }
        if (current->key == key) {
            return current->next->data;
        }
        current = current->next;
    }
    printf("Error: The element with the given key was not found\n");
    return NULL;
}

char* MyDLLFindPrevious(struct Node *dll, uint16_t key) {
    struct Node *current = dll;
    while (current != NULL) {
        if (current == dll && current->key == key) {
            printf("Error: The first element does not have a previous one\n");
            return NULL;
        }
        if (current->key == key) {
            return current->prev->data;
        }
        current = current->next;
    }
    printf("Error: The element with the given key was not found\n");
    return NULL;
}

void MyDLLPrint(struct Node *dll, uint16_t size) {
    struct Node *current = dll;
    uint16_t smallerkey = UINT16_MAX;

    for (int i = 0; i < size; i++) {
        if (dll[i].key != 0 && dll[i].key < smallerkey) {
            smallerkey = dll[i].key;
            current = &dll[i];
        } 
    }

    if (smallerkey == UINT16_MAX) {
        printf("DLL Empty\n\n");
        return;
    }

    printf("DLL: ");

    while (current != NULL) {
        printf("%d: '%s' -> ", current->key, current->data);
        current = current->next;
    }
    
    printf("NULL\n\n");
}

void MyDLLRestore(struct Node *dll, uint16_t key, uint16_t size) {
    for (int i=0; i < TRASH_SIZE; i++) {
        if (trashbin[i].key == key) {
            for (int j=0; j < size; j++) {
                if (trashbin[i].key == dll[j].key) {
                    dll[j].key = trashbin[i].key;
                    strcpy(dll[j].data, trashbin[i].data);
                    printf("Restored: Element added with key %d\n", key);
                    return;
                }
            }

            printf("Restored: ");
            MyDLLInsert(dll, trashbin[i].key, trashbin[i].data, size);
            return;
        }
    }
    printf("Key %d not found in trashbin\n", key);
}