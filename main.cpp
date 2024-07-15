#include "main.hpp"
//Topic: Local Static
using namespace std;// This means we don't need to use this std before function.

// Topic: State the examples of "Static" and "Const"

//Part 1 Use of "Static"
// Section 1.1 Static Local Variables
//Definition: It is declared inside  the function and retains its value between function calls. Its lifetime extends to the end of the program but its scope limits to the function in which it is declared.
void static_local(){
    static int sl;// this indicates we can't access this local variable outside the fucntion "static_local"
    sl++;
    cout<< "Function called"<<endl;
}

//Section 1.2  Static Global Variables
//Definition: It is declared outside any function, typically at the top of the file, and accessiable inside the file which it is declares in.
static int gv=1; // we can access this global variable inside the whole file.

//Section 1.3 Static Member Variables.
// Definition: A static member variable is a variable that belongs to the class rather than any object instance. It is shared among all instances of the class and retains its value across all instances. Static member variables must be defined outside the class definition.

class Member{
public:
    static int member;
    int Example(){return member+1;};
};

int Member::member=0;// The member variables should be initialized outside the class.


//Part 2 Use of "const"
// Definition of "const": Used to declare variables whose values can't be changed after initialization.

// Section 2.1  Constant Variables
//Definition: Ensure the value of the variables unchanged.

//Section 2.2 Constant Pointers and Reference
//Definition: Prevent modification of value pointed to or referenced.

//Section 2.3 Constant Member Function
//Definition:Indicate that the function does not modify the object' s state.

class const_member{
private:
    int mutable value=100;
public:
    int getvalue() const{
    value++; //This line would fail because we are trying to change the value which will also change the class and it is not permitted.
        return value;
    };// In this situation, we put const after the method and it will ensure that the method would not modify the class.Unless we use "mutable";
};

int main(){
    // Part 1 main codes
    static_local();
    gv++;
    cout<<gv<<endl;// we can access the global variable everywhere in this file.
    Member m;
    cout<<m.Example()<<endl;
   
    //Part 2 main codes
   //Section 2.1 Constant Variables;
    const int var=100;
    //var=200; This would fail because the variable is constant which indicates can't be changed.
   
    //Section 2.2 Constant Pointers and Reference
    int another_var=22;
    int const* a=&var;
    const int* b=&var;// Pointer to constant interger.
    //*a=2; or *b=2; would fail
    a=&another_var;// This would succeed because we only change the value a pointed to. Means we let pointer a to point at another value.
    
    int* const c=&another_var;// Constant pointers to interger
    // c=(int*)&var; would fail;
    *c=100;// This would succeed, because instead changing the pointer, we change the value of the pointer c which is fine.
    
    //Section 2.3
    const_member cm;
    cout<<cm.getvalue()<<endl;
    cin.get();
    
}
