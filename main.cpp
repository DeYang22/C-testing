#include <iostream>
#include <string>
#include <memory>// for unique_ptr
//Topic:Smart Pointers
// Way to automaticlly store the data on heap and delete outside the scope.
// No need to use "new" and "delete".
// First: unique_ptr:  scope pointer, when the pointer is out of the scope, it will be deleted automatically. Can't be copied or shared.
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

int main(){
    {
        std::unique_ptr<Entity> entity=std::make_unique<Entity>();// By debuging, we can see that the class entitiy is destroyed out of the scope.
    }
    std::cin.get();
        
};
 
 
