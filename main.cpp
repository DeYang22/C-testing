#include <iostream>
#include <string>
class Entity{
private:
    int m_age;
    std::string m_name;
public:
    Entity(const std::string&name)
    :m_name(name),m_age(-1){}
    Entity(int age)
    :m_name("Unknown"),m_age(age){}
};

int main(){
    Entity a("DEDE");
    Entity b(25);
    std::cin.get();
    
    
};
 

