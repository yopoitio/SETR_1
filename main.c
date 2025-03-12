#include "DLL.h"
#define SIZE 20

int main() {
    char *return_msg;
    struct Node *dll = MyDLLInit(SIZE);

    return_msg = MyDLLFind(dll, 2, SIZE);
    if(return_msg==NULL) {
        printf("Key not found\n");
    }
    else {
        printf("Key found with data: %s\n", return_msg);
    }

    MyDLLInsert(dll, 1, "Hello", SIZE);

    MyDLLInsert(dll, 3, "!", SIZE);

    MyDLLInsert(dll, 2, "World", SIZE);

    MyDLLRemove(dll, 2, SIZE);

    MyDLLInsert(dll, 2, "Goodbye", SIZE);

    MyDLLPrint(dll, SIZE);

    MyDLLRemove(dll, 2, SIZE);
    MyDLLInsert(dll, 2, "Hi", SIZE);
    MyDLLRemove(dll, 2, SIZE);
    MyDLLRestore(dll, 2, SIZE);

    return_msg = MyDLLFind(dll, 2, SIZE);
    if(return_msg==NULL) {
        printf("Key not found\n");
    }
    else {
        printf("Key found with data: %s\n", return_msg);
    }
    MyDLLPrint(dll, SIZE);
    return 0;
}