#include "DLL.h"
#define SIZE 20

int main() {
    int err;
    char *return_msg;
    struct Node *dll = MyDLLInit(SIZE);

    return_msg = MyDLLFind(dll, 2, SIZE);
    if(return_msg==NULL) {
        printf("Key not found\n");
    }
    else {
        printf("Key found with data: %s\n", return_msg);
    }

    err = MyDLLInsert(dll, 1, "Hello", SIZE);
    if(err==-1) {
        printf("Error found at MyDLLInsert\n");
    }

    err = MyDLLInsert(dll, 3, "!", SIZE);
    if(err==-1) {
        printf("Error found at MyDLLInsert\n");
    }

    err = MyDLLInsert(dll, 2, "World", SIZE);
    if(err==-1) {
        printf("Error found at MyDLLInsert\n");
    }

    err = MyDLLRemove(dll, 2, SIZE);
    if(err==-1) {
        printf("Error found at MyDLLRemove\n");
    }

    err = MyDLLInsert(dll, 2, "Goodbye", SIZE);
    if(err==-1) {
        printf("Error found at MyDLLInsert\n");
    }

    MyDLLPrint(dll, SIZE);

    return_msg = MyDLLFind(dll, 2, SIZE);
    if(return_msg==NULL) {
        printf("Key not found\n");
    }
    else {
        printf("Key found with data: %s\n", return_msg);
    }
    return 0;
}