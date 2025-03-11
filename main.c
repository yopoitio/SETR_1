#include "DLL.h"
#define SIZE 20

int main() {
    struct Node *dll = MyDLLInit(SIZE);
    MyDLLInsert(dll, 1, "Hello");
    MyDLLInsert(dll, 3, "!");
    MyDLLInsert(dll, 2, "World");
    MyDLLRemove(dll, 2, SIZE);
    return 0;
}