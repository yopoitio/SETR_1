/**
 * @file main.c
 * @brief Test suite for the Doubly Linked List (DLL) implementation.
 *
 * This file contains a series of tests to validate the functionality 
 * of the Doubly Linked List (DLL) implementation defined in DLL.h.
 * The tests include insertion, removal, search, and restoration of nodes.
 *
 * @author 107465 Rafaek Almeida
 * @author 107838 Afonso Vaz
 * @date March 14, 2025
 * @bug No known bugs.
 * @version 1.0
 */

#include "DLL.h"
#define SIZE 20

char *return_msg;
struct Node *dll;

/**
 * @brief Test function for inserting and removing elements in the Doubly Linked List.
 * 
 * This function tests the MyDLLInsert and MyDLLRemove functions. It performs various operations 
 * including edge cases by inserting the kye 0.
 * 
 * @note This function assumes that the global variables 'dll' and 'SIZE' are properly initialized.
 *
 * @return void This function does not return a value.
 */
void test_insert_and_remove() {
    printf("\n-----------------------------------------------\n");
    printf("      Testing MyDLLInsert and MyDLLRemove\n");
    printf("-----------------------------------------------\n");
    MyDLLInsert(dll, 1, "Hello", SIZE);
    MyDLLInsert(dll, 3, "!", SIZE);
    MyDLLInsert(dll, 2, "World", SIZE);
    MyDLLPrint(dll, SIZE);
    MyDLLRemove(dll, 2, SIZE);
    MyDLLPrint(dll, SIZE);
    MyDLLInsert(dll, 2, "Goodbye", SIZE);
    MyDLLPrint(dll, SIZE);
    MyDLLInsert(dll, 4, "World", SIZE);
    MyDLLPrint(dll, SIZE);
    MyDLLRemove(dll, 4, SIZE);
    MyDLLPrint(dll, SIZE);
    MyDLLRemove(dll, 4, SIZE);

    MyDLLInsert(dll, 0, "Try key 0", SIZE);
}

/**
 * @brief Test function for the MyDLLFind operation in the Doubly Linked List.
 *
 * This function tests the MyDLLFind function. It searches for a key in the
 * list and another one not present in the DLL. Return's the data when present
 * and NUll otherwise.
 *
 * @note This function assumes that the global variables 'dll', 'return_msg',
 *       and 'SIZE' are properly initialized.
 *
 * @return void This function does not return a value.
 */
void test_find() {
    printf("\n-----------------------\n");
    printf("   Testing MyDLLFind\n");
    printf("-----------------------\n");
    return_msg = MyDLLFind(dll, 2, SIZE);
    if (return_msg == NULL) {
        printf("Key not found\n");
    }
    else {
        printf("Key found with data: %s\n", return_msg);
    }

    return_msg = MyDLLFind(dll, 4, SIZE);
    if (return_msg == NULL) {
        printf("Key not found\n");
    }
    else {
        printf("Key found with data: %s\n", return_msg);
    }
}

/**
 * @brief Test function for MyDLLFindPrevious and MyDLLFindNext operations.
 * 
 * This function tests the MyDLLFindPrevious and MyDLLFindNext functions. It 
 * prints the current state of the list and then performs a series of tests to 
 * find previous and next elements for various keys in the list.
 *
 * @note This function assumes that the global variables 'dll', 'return_msg',
 *       and 'SIZE' are properly initialized.
 *
 * @return void This function does not return a value.
 */
void test_find_previous_and_next() {
    printf("\n----------------------------------------------------\n");
    printf("   Testing MyDLLFindPrevious and MyDLLFindNext\n");
    printf("----------------------------------------------------\n");
    MyDLLPrint(dll, SIZE);

    return_msg = MyDLLFindPrevious(dll, 2);
    if (return_msg != NULL) printf("Previous element data of element %d: %s\n", 2, return_msg);

    return_msg = MyDLLFindPrevious(dll, 1);
    if (return_msg != NULL) printf("Previous element data of element %d: %s\n", 4, return_msg);

    return_msg = MyDLLFindPrevious(dll, 4);
    if (return_msg != NULL) printf("Previous element data of element %d: %s\n", 4, return_msg);

    return_msg = MyDLLFindNext(dll, 3);
    if (return_msg != NULL) printf("Next element data of element %d: %s\n", 3, return_msg);

    return_msg = MyDLLFindNext(dll, 1);
    if (return_msg != NULL) printf("Next element data of element %d: %s\n", 1, return_msg);

    return_msg = MyDLLFindNext(dll, 4);
    if (return_msg != NULL) printf("Next element data of element %d: %s\n", 3, return_msg);
}

/**
 * @brief Test function for MyDLLRestore and MyDLLInsert operations.
 * 
 * This function tests the MyDLLRestore and MyDLLInsert functions. it performs
 * some insertions and removals to test the restore and insert operations.
 * The function also test edge cases by inserting the same key twice and restoring
 * multiple elements.
 *
 * @note This function assumes that the global variables 'dll' and 'SIZE'
 *       are properly initialized.
 *
 * @return void This function does not return a value.
 */
void test_restore_and_insert() {
    printf("\n------------------------------------------\n");
    printf("   Testing MyDLLRestore and MyDLLInsert   \n");
    printf("------------------------------------------\n");
    MyDLLPrint(dll, SIZE);
    MyDLLRemove(dll, 2, SIZE);
    MyDLLPrint(dll, SIZE);
    MyDLLInsert(dll, 2, "Hi", SIZE);
    MyDLLPrint(dll, SIZE);
    MyDLLInsert(dll, 2, "Trying a key twice", SIZE);
    MyDLLRemove(dll, 2, SIZE);
    MyDLLPrint(dll, SIZE);
    MyDLLRestore(dll, 2, SIZE);
    MyDLLPrint(dll, SIZE);

    MyDLLRemove(dll, 1, SIZE);
    MyDLLRemove(dll, 2, SIZE);
    MyDLLRemove(dll, 3, SIZE);
    MyDLLPrint(dll, SIZE);
    MyDLLRestore(dll, 1, SIZE);
    MyDLLRestore(dll, 3, SIZE);
    MyDLLRestore(dll, 2, SIZE);
    MyDLLPrint(dll, SIZE);

    MyDLLInsert(dll, 10, "Try", SIZE);
    MyDLLInsert(dll, 11, "to", SIZE);
    MyDLLInsert(dll, 12, "fill", SIZE);
    MyDLLInsert(dll, 13, "the", SIZE);
    MyDLLInsert(dll, 14, "trashbin", SIZE);
    MyDLLInsert(dll, 15, "!!!", SIZE);
    MyDLLPrint(dll, SIZE);
    for(int i=10; i<=15; i++) {
        MyDLLRemove(dll, i, SIZE);
    }
    MyDLLPrint(dll, SIZE);
    for(int i=10; i<=15; i++) {
        MyDLLRestore(dll, i, SIZE);
    }
    MyDLLPrint(dll, SIZE);

    MyDLLRemove(dll, 2, SIZE);
    MyDLLPrint(dll, SIZE);
    MyDLLInsert(dll, 2, "Hi!!!", SIZE);
    MyDLLPrint(dll, SIZE);
    MyDLLRestore(dll, 2, SIZE);
    MyDLLPrint(dll, SIZE);
}

/**
 * @brief Test function for MyDLLFind operation after using MyDLLRestore.
 * 
 * This function tests the MyDLLRestore after the MyDLLRestore function. It tries to
 * find the key restored in the previous function to see if the restauration process
 * was successful.
 *
 * @note This function assumes that the global variables 'dll', 'return_msg',
 *       and 'SIZE' are properly initialized.
 *
 * @return void This function does not return a value.
 */
void test_find_after_restore() {
    printf("\n------------------------------------------\n");
    printf("   Testing MyDLLFind after MyDLLRestore\n");
    printf("------------------------------------------\n");
    MyDLLPrint(dll, SIZE);
    return_msg = MyDLLFind(dll, 12, SIZE);
    if (return_msg == NULL) {
        printf("Key not found\n");
    }
    else {
        printf("Key found with data: %s\n", return_msg);
    }
}

/**
 * @brief Test function for MyDLLInsert and MyDLLInit operations.
 *
 * This function tests the MyDLLInsert and MyDLLInit functions. it removes
 * all elements off the list and then fills the list totally to test the
 * initialization.
 *
 * @note This function assumes that the global variables 'dll' and 'SIZE'
 *       are properly initialized.
 *
 * @return void This function does not return a value.
 */
void test_insert_and_init() {
    printf("\n------------------------------------------\n");
    printf("   Testing MyDLLInsert and MyDLLInit\n");
    printf("------------------------------------------\n");
    for(int i=1; i<=15; i++) 
        MyDLLRemove(dll, i, SIZE);
    MyDLLPrint(dll, SIZE);

    char *data = malloc(1);

    for(int i=1; i<=SIZE+1; i++) {
        snprintf(data, sizeof(data), "%c", i+64);
        MyDLLInsert(dll, i, data,SIZE);
    }

    MyDLLPrint(dll, SIZE);
}

/**
 * @brief Test function for the MyDLLRestore operation in the Doubly Linked List.
 *
 * This function tests the MyDLLRestore function. It tries to restore a element
 * not present in the list while the list is full.
 *
 * The function uses the following global variables:
 * @param dll A pointer to the Doubly Linked List structure.
 * @param SIZE The maximum size of the Doubly Linked List.
 *
 * @return void This function does not return a value.
 */
void test_restore() {
    printf("\n--------------------------\n");
    printf("   Testing MyDLLRestore\n");
    printf("--------------------------\n");
    MyDLLPrint(dll, SIZE);
    MyDLLRemove(dll, 5, SIZE);
    MyDLLInsert(dll,25,"Test for restore", SIZE);
    MyDLLPrint(dll, SIZE);
    MyDLLRemove(dll, 25, SIZE);
    MyDLLInsert(dll,5,"Element to fill DLL", SIZE);
    MyDLLPrint(dll, SIZE);
    MyDLLRestore(dll, 25, SIZE);
    MyDLLPrint(dll, SIZE);
}

/**
 * @brief Main function to execute all DLL tests.
 *
 * Initializes the DLL and executes all test functions sequentially.
 * Ensures the correctness of DLL operations.
 *
 * @return Always returns 0 if all tests pass.
 */
int main() {
    dll = MyDLLInit(SIZE);

    test_insert_and_remove();

    test_find();

    test_find_previous_and_next();

    test_restore_and_insert();

    test_find_after_restore();

    test_insert_and_init();

    test_restore();

    return 0;
}