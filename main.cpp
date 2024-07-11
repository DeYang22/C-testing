#include <iostream>
#include <string>
//Topic: Object lifetime
// Stack: the variable get destroyrd as soon as we get out of the scope.
class Entity{
public:
    Entity()
    {
        std::cout<< "Created Entity"<< std::endl;
    };
    ~Entity()// ~ means destroyred the class.
    {
        std::cout<<"Destroyed Entity"<<std::endl;
    };
};

int* CreatArray(){
    int* array=new int[50];// create a variable on heap
    return array;
}

class scopeptr
{
private:
    Entity* m_ptr;
public:
    scopeptr(Entity* ptr):m_ptr(ptr)// initualize the m_ptr;
    {
    }
   ~scopeptr(){
        delete m_ptr; // delete the m_ptr
    }
};

int main(){
    {
        scopeptr e=new Entity() ;
         
        int* a=CreatArray();// we can still access the function outside the scope if we build the array on heap.
    }
    std::cin.get();
        
};
 
 
