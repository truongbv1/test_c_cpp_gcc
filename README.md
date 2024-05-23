```
test_c_cpp_gcc
├── file_c.c
├── file_cpp.cpp
├── file_cpp.h
├── file.h
└── main.c
===> how to build
```
1. auto
```
make
./mix_c_cpp_gcc
or
./mix_c_cpp_g++
```

2. manual
```
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
```