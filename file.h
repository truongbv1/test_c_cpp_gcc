// file.h
#ifndef FILE_H
#define FILE_H

#ifdef __cplusplus
extern "C" {
#endif

void my_cpp_function();

void* create_class_test();
void* create_class_test_by_name(char* name);
void* create_class_test_by_name_id(char* name, int id);
void  free_class_test(void* class_ptr);

void set_id_test(void* class_ptr, int id);
void print_id_test(void* class_ptr);
void print_name_test(void* class_ptr);



void my_c_function();


#ifdef __cplusplus
}
#endif

#endif // FILE_H
