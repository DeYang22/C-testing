#include <iostream>
#include <string>
#include <memory>// for unique_ptr
//Topic:Smart Pointers
// Way to automaticlly store the data on heap and delete outside the scope.
// No need to use "new" and "delete".
// Third: weak_ptr: used with shared_ptr, will not count by using it.
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
    {std::weak_ptr<Entity> e0;// can be used to check whether the class is still alive or died.
        {std::shared_ptr<Entity> sharedentity=std::make_shared<Entity>();
            e0=sharedentity;
        }// by using the weak_ptr, the class will be detroyed after the first scope.
    }
    std::cin.get();
        
};
 
 
