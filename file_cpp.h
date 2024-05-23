#include <iostream>
#include <string>

class Test { 
public: 
    std::string name; 
    int id; 

    Test();
    Test(std::string name);
    Test(std::string name, int id);
    
    void setid(int id);
    void printname();  
    void printid(){ 
        std::cout <<"id is: "<< id << std::endl; 
    }

    ~Test();
};