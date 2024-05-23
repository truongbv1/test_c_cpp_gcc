// file.cpp
#include "file.h"


#include "file_cpp.h"
#include <iostream>

extern "C" {
    void my_cpp_function(){
        std::cout << "Hello from C++" << std::endl;
    }

    // test class
    void* create_class_test(){
        Test *test = new Test();
        return (void*)test;
    }

    void* create_class_test_by_name(char* name){
        Test *test = new Test(std::string(name));
        return (void*)test;
    }

    void* create_class_test_by_name_id(char* name, int id){
        Test *test = new Test(std::string(name), id);
        return (void*)test;
    }

    void free_class_test(void* class_ptr){
        Test* ptr = (Test*)class_ptr;
        // ptr->~Test(); //or delete ptr;
        delete ptr;
    }

    void set_id_test(void* class_ptr, int id){
        Test* ptr = (Test*)class_ptr;
        // ptr->id = id;
        ptr->setid(id);
    }

    void print_id_test(void* class_ptr){
        Test* ptr = (Test*)class_ptr;
        ptr->printid();
    }

    void print_name_test(void* class_ptr){
        Test* ptr = (Test*)class_ptr;
        ptr->printname();
    }
}

Test::Test(){
    this->name = "default";
    this->id = 0;
    std::cout << "init class" << std::endl;
}

Test::Test(std::string name){
    this->name = name;
    this->id = 0;
    std::cout << "init class" << std::endl;
}

Test::Test(std::string name, int id){
    this->name = name;
    this->id = id;
    std::cout << "init class" << std::endl;
}

Test::~Test(){
    std::cout << "free class" << std::endl;
}

void Test::setid(int id){
    this->id = id;
}

void Test::printname(){ 
    std::cout <<"Name is: "<< this->name <<"\n";
} 