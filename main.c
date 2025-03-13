#include "DLL.h"
#define SIZE 20

int main() {
    char *return_msg;
    struct Node *dll = MyDLLInit(SIZE);

    printf("\n-----------------------------------\n");
    printf("\tTesting MyDLLFind\n");
    printf("-----------------------------------\n");
    return_msg = MyDLLFind(dll, 2, SIZE);
    if (return_msg == NULL) {
        printf("Key not found\n");
    }
    else {
        printf("Key found with data: %s\n", return_msg);
    }

    printf("\n-----------------------------------------------\n");
    printf("      Testing MyDLLInsert and MyDLLRemove\n");
    printf("-----------------------------------------------\n");
    MyDLLInsert(dll, 1, "Hello", SIZE);

    MyDLLInsert(dll, 3, "!", SIZE);

    MyDLLInsert(dll, 2, "World", SIZE);

    MyDLLRemove(dll, 2, SIZE);

    MyDLLInsert(dll, 2, "Goodbye", SIZE);

    MyDLLPrint(dll, SIZE);

    printf("----------------------------------------------------\n");
    printf("   Testing MyDLLFindPrevious and MyDLLFindNext\n");
    printf("----------------------------------------------------\n");
    return_msg = MyDLLFindPrevious(dll, 2);
    if (return_msg != NULL) printf("Previous element data of element %d: %s\n", 2, return_msg);

    return_msg = MyDLLFindNext(dll, 3);
    if (return_msg != NULL) printf("Next element data of element %d: %s\n", 3, return_msg);

    return_msg = MyDLLFindPrevious(dll, 4);
    if (return_msg != NULL) printf("Previous element data of element %d: %s\n", 4, return_msg);

    return_msg = MyDLLFindNext(dll, 1);
    if (return_msg != NULL) printf("Next element data of element %d: %s\n", 1, return_msg);

    printf("\n-----------------------------\n");
    printf("   Testing MyDLLRestone\n");
    printf("-----------------------------\n");
    MyDLLRemove(dll, 2, SIZE);
    MyDLLInsert(dll, 2, "Hi", SIZE);
    MyDLLInsert(dll, 2, "Trying a key twice", SIZE);
    MyDLLRemove(dll, 2, SIZE);
    MyDLLRestore(dll, 2, SIZE);

    printf("\n------------------------------------------\n");
    printf("   Testing MyDLLFind after MyDLLRestore\n");
    printf("------------------------------------------\n");
    return_msg = MyDLLFind(dll, 2, SIZE);
    if (return_msg == NULL) {
        printf("Key not found\n");
    }
    else {
        printf("Key found with data: %s\n", return_msg);
    }
    MyDLLPrint(dll, SIZE);

    return 0;
}