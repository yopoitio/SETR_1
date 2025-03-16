/** 
 * @file DLL.h
 * @brief Implementation of a Doubly Linked List (DLL) library.
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
 * Each node contains an unique key (`key`), a data array (`data`), 
 * and pointers to the previous (`prev`) and next (`next`) nodes.
 */
struct Node {
    uint16_t key;           ///< Unique identifier key for the node.
    char data[DATA_SIZE];   ///< Data stored in the node.
    struct Node* prev;      ///< Pointer to the previous node.
    struct Node* next;      ///< Pointer to the next node.
};

/**
 * @brief Initializes a new Doubly Linked List (DLL) with a specified size.
 *
 * This function creates a new DLL and a trashbin for deleted elements. It initializes
 * all nodes in the DLL with default values.
 *
 * @param size The number of nodes to allocate for the DLL.
 * 
 * @return struct Node* A pointer to the first node of the newly created DLL.
 */
struct Node* MyDLLInit(uint16_t size);

/**
 * @brief Inserts a new node into the doubly linked list.
 * 
 * This function inserts a new node into the doubly linked list in the right
 * position based on the key value. If the list is full or in case of any error, 
 * the new node is not added.
 * The insertion of a new node is made with the objective of maintaining the order
 * of the elements by their keys with the right linked pointers.
 * 
 * @param dll Pointer to the first element of the doubly linked list.
 * @param newKey Key of the new node to be added.
 * @param data Data to be saved in the node.
 * @param size The total number of elements in the doubly linked list.
 * 
 * @return void This function does not return a value.
 */
void MyDLLInsert(struct Node *dll, uint16_t newKey, char* data, uint16_t size);

/** @brief Deletes an entry from the dll and saves it in the trashbin. 
 *
 * In a given doubly linked list, this operation looks for an element with the given key, 
 * deletes it from the list and places it in the trashbin for possible restoration. 
 * In case the element is located, it adjusts the links of the adjacent nodes and clears
 * the data of the deleted node. 
 *
 * @param dll Pointer to the first element of the doubly linked list.
 * @param key The key value to search for in the list.
 * @param size The total number of elements in the doubly linked list.
 *
 * @return void This function does not return a value.
 */
void MyDLLRemove(struct Node *dll, uint16_t key, uint16_t size);

/** @brief Looks for a particular element in the doubly linked list by a specific key.
 *
 * This function searches through the doubly linked list seeking an element 
 * with the specific key. It retrieves the associated data if the element 
 * is present, otherwise, it returns NULL.
 *
 * @param dll Pointer to the first element of the doubly linked list.
 * @param key The value to be searched for in the list.
 * @param size The total number of elements in the doubly linked List.
 * 
 * @return char* Pointer to the found element data, or NULL if doesn't exist.
 */
char *MyDLLFind(struct Node *dll, uint16_t key, uint16_t size);

/**
 * @brief Finds the next node in the doubly linked list.
 * 
 * This function searches for the node with the given key and, if found,
 * returns the data of the next node. If the node is not found, it returns NULL.
 * 
 * @param dll Pointer to the first element of the doubly linked list.
 * @param key Key of the current node.
 * 
 * @return char* Pointer to the data of the next node, or NULL if doesn't exist.
 */
char *MyDLLFindNext(struct Node *dll, uint16_t key);

/**
 * @brief Finds the previous node in the doubly linked list.
 * 
 * This function searches for the node with the given key and, if found, it
 * returns the data of the previous node. If the node is not found, it returns NULL.
 * 
 * @param dll Pointer to the first element of the doubly linked list.
 * @param key Key of the current node.
 * 
 * @return char* Pointer to the data of the previous node, or NULL if doesn't exist.
 */
char *MyDLLFindPrevious(struct Node *dll, uint16_t key);

/**
 * @brief Prints the contents of the doubly linked list.
 * 
 * This function prints the doubly linked list node by node, in order of their keys.
 * 
 * @param dll Pointer to the first element of the doubly linked list.
 * @param size The total number of elements in the doubly linked list.
 * 
 * @return void This function does not return a value.
 */
void MyDLLPrint(struct Node *dll, uint16_t size);

/** @brief Retrieves a deleted item from the trashbin and adds it to the doubly linked list.
 *
 * This function looks for the element with given key in the trashbin.
 * If it does exist, updates a record with the same key in the DLL, or else adds a new 
 * record by utilizing the data in the trashbin. In case the doubly linked list is filled, 
 * the elemente is not placed.
 *
 * @param dll Pointer to the first element of the doubly linked list.
 * @param key The key of the element to be restored.
 * @param size The size of the doubly linked list.
 *
 * @return void This function does not return a value.
 */
void MyDLLRestore(struct Node *dll, uint16_t key, uint16_t size);

#endif // DLL_H