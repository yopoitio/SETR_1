#include "DLL.h"
#define SIZE 20

int main() {
    struct Node *dll = MyDLLInit(SIZE);
    int err = MyDLLInsert(dll, 1, "Hello", SIZE);
    printf("%d\n", err);
    err = MyDLLInsert(dll, 3, "!", SIZE);
    printf("%d\n", err);
    err = MyDLLInsert(dll, 2, "World", SIZE);
    printf("%d\n", err);
    err = MyDLLRemove(dll, 2, SIZE);
    printf("%d\n", err);
    return 0;
}