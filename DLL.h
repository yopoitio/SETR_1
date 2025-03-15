/** 
 * @file DLL.h
 * @brief Implementation of a Doubly Linked List (DLL) library.
 *
 * This module provides the implementation of a doubly linked list 
 * with functionalities for inserting, removing, searching, and restoring nodes. 
 * The list maintains a set of nodes ordered by key and allows an efficient 
 * navigation and manipulation of the elements.
 * 
 * The list structure consists of nodes containing a key (`key`), 
 * a data array (`data`), and pointers to the previous and next nodes.
 *
 * @author 107465 Rafaek Almeida
 * @author 107838 Afonso Vaz
 * @date March 14, 2025
 * @bug No known bugs.
 * @version 1.0
 */

#ifndef DLL_H
#define DLL_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define DATA_SIZE 20    ///< Maximum size of data stored in a node.
#define TRASH_SIZE 5    ///< Reserved space for removed elements.
/**
 * @struct Node
 * @brief Structure representing a node in the doubly linked list.
 *
 * Each node contains a unique key (`key`), a data array (`data`), 
 * and pointers to the previous (`prev`) and next (`next`) nodes.
 */
struct Node {
    uint16_t key;           ///< Unique identifier key for the node.
    char data[DATA_SIZE];   ///< Data stored in the node.
    struct Node* prev;      ///< Pointer to the previous node.
    struct Node* next;      ///< Pointer to the next node.
};

struct Node* MyDLLInit(uint16_t size);

/**
 * @brief Inserts a new node into the doubly linked list.
 * @param dll Pointer to the list.
 * @param newKey Key of the new node.
 * @param data Data to be stored in the node.
 * @param size Maximum number of nodes in the list.
 */
void MyDLLInsert(struct Node *dll, uint16_t newKey, char* data, uint16_t size);

void MyDLLRemove(struct Node *dll, uint16_t key, uint16_t size);
char *MyDLLFind(struct Node *dll, uint16_t key, uint16_t size);

/**
 * @brief Finds the next node in the doubly linked list.
 * @param dll Pointer to the list.
 * @param key Key of the current node.
 * @return Pointer to the data of the next node, or NULL if not found.
 */
char *MyDLLFindNext(struct Node *dll, uint16_t key);

/**
 * @brief Finds the previous node in the doubly linked list.
 * @param dll Pointer to the list.
 * @param key Key of the current node.
 * @return Pointer to the data of the previous node, or NULL if not found.
 */
char *MyDLLFindPrevious(struct Node *dll, uint16_t key);

/**
 * @brief Prints the contents of the doubly linked list.
 * @param dll Pointer to the list.
 * @param size Maximum number of nodes in the list.
 */
void MyDLLPrint(struct Node *dll, uint16_t size);


void MyDLLRestore(struct Node *dll, uint16_t key, uint16_t size);

#endif // DLL_H