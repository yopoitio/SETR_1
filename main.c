#include "DLL.h"

int main() {
    struct Node *dll = MyDLLInit(20);
    MyDLLInsert(dll, 1, "Hello");
    return 0;
}