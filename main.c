#include "DLL.h"
#define SIZE 20

char *return_msg;
struct Node *dll;

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
}

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
int main() {
    dll = MyDLLInit(SIZE);

    test_insert_and_remove();

    test_find();

    test_find_previous_and_next();

    test_restore_and_insert();

    test_find_after_restore();

    test_insert_and_init();

    return 0;
}