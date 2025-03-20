set (DLL_SRCS DLL.h DLL.c)

set(LIB_TYPE STATIC)

add_library (DLL_Lib ${LIB_TYPE} ${DLL_SRCS})