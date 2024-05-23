// main.c
#include <stdio.h>
#include "file.h"

int main() {
    printf("Calling C++ function from C:\n");
    my_cpp_function();
    printf("Calling C function from C:\n");
    my_c_function();

    void* cls_1 = create_class_test();
    void* cls_2 = create_class_test_by_name("DEMO");
    void* cls_3 = create_class_test_by_name_id("EXAMPLE", 20);

    print_id_test(cls_1);
    print_id_test(cls_2);
    print_id_test(cls_3);

    set_id_test(cls_1, 10);
    set_id_test(cls_2, 30);
    set_id_test(cls_3, 50);

    print_name_test(cls_1);
    print_id_test(cls_1);
    print_name_test(cls_2);
    print_id_test(cls_2);
    print_name_test(cls_3);
    print_id_test(cls_3);


    free_class_test(cls_1);
    free_class_test(cls_2);
    free_class_test(cls_3);

    return 0;
}

/*
.
├── file_c.c
├── file_cpp.cpp
├── file_cpp.h
├── file.h
└── main.c
===> how to build

// build obj c++
gcc -c file_cpp.cpp -o file_cpp.o -lstdc++

// build obj c
gcc -c file_c.c -o file_c.o

// build obj main with c
gcc -c main.c -o main.o

// build target gcc
gcc main.o file_c.o file_cpp.o -o mix_c_cpp_gcc -lstdc++
./mix_c_cpp_gcc

// build target with g++
g++ main.o file_c.o file_cpp.o -o mix_c_cpp_g++
./mix_c_cpp_g++

*/