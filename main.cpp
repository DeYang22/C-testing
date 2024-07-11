#include <iostream>
#include <string>
#include <vector>// Notice: when using a vector, we need to include like this.
//Topic: Dynamic Array
struct Vertex
{
    float x,y,z;
};

std::ostream& operator <<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x<<","<< vertex.y<<","<<vertex.z;
    return stream;
};

int main(){
    std::vector<Vertex> vertices; // Create an dynamic array here which indicates there's no size of the array.
    vertices.push_back({1,2,3});
    vertices.push_back({4,5,6});// Add different element in this array.
    
    for (int i=0; i<vertices.size();i++)
        std::cout<< vertices[i]<<std::endl;//print out each element from the array, notice the size of this vertices is two.
   
    vertices.erase(vertices.begin()+1);// Try to remove the second element in vertices which is {4,5,6}
    for (int i=0; i<vertices.size();i++)
        std::cout<< vertices[i]<<std::endl;// We can see from the console, we only print out {1,2,3}here.
       
    std::cin.get();

};
 
 
