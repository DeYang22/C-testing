#include <iostream>
#include <string>
#include <memory>// for unique_ptr
//Topic:Smart Pointers
// Way to automaticlly store the data on heap and delete outside the scope.
// No need to use "new" and "delete".
// Second: shared_ptr: can be shared and copied. also including a counting system which means it will only deleted the class when the shared_ptr count to zero.
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
    {std::shared_ptr<Entity> e0;
        {std::shared_ptr<Entity> sharedentity=std::make_shared<Entity>();
            e0=sharedentity;
        }
    }// Because we reference the shared_ptr twice, the count is two now, so the class will be deleted after this curve brackets. Use debug  to check it.
    std::cin.get();
        
};
 
 
