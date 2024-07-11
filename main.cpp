#include <iostream>
#include <string>
//Topic: Copying and copy constructor
class String{
private:
    char* m_Buffer;
    unsigned int m_size;
public:
    String(const char* string)
    {
        m_size=strlen(string); // strlen function used to get the length of the string.
        m_Buffer=new char[m_size+1];// because we should add an 0 to indicate the string is over.
        memcpy(m_Buffer, string, m_size); // put every charecter in string to m_buffer.
        m_Buffer[m_size]=0;// set 0 to the last chareater of the string.
    }
    friend std::ostream& operator<< (std::ostream& stream, const String& string);// because we want  to access m_Buffer and it is private, which means only itself and its friend can access it, so we make it as a friend.
    String(const String& other)//Try to construct a new m_Buffer with differnt memory address. Without this, because m_Buffer is actually a pointer, we will set two value with the same pointer and the program will fail.
    :m_size(other.m_size)
    {
        m_Buffer=new char[m_size+1];
        memcpy(m_Buffer, other.m_Buffer, m_size+1);
    }
    ~String()
    {
        delete[] m_Buffer;
    }
    char& operator [](unsigned int index)
    {
        return m_Buffer[index];
    }
};

std::ostream& operator<< (std::ostream& stream, const String& string){
    stream << string.m_Buffer;
    return stream;
};// this is actually a operator overloading here for "<<" operator. and check more details on notes.
 
int main(){
    String string="DEDE";
    String second=string;
    
    second[2]='A';
    
    std::cout<< string<< std::endl;
    std::cout<< second<< std::endl;
    std::cin.get();
// By running the program, we can see we only print out the string without any other thing.
};
 
 
