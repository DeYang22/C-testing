#include "main.hpp"
using namespace std;// This means we don't need to use this std before function.
//Topic:Operator Overloading
//Defination: Allow us to overload the operator to enhance the readibility and functionality of our code

class Complex{
private:
    double real, image;
public:
    Complex(double r=0.0, double i =0.0)
    : real(r), image(i){} //Initialize the variables with r and i seperately.
    
    // Part 1 Overloading the binary operator (+)
    Complex operator+(const Complex &other) const
    {
        return Complex(real+other.real,image+other.image);
    }// Other usually represent another object of class, usefully in overloading process.
   
    // Part 2 Overloading the uniary operator(-)
    Complex operator-() const
    {
        return Complex(-real,-image);
    }
    
    //Part 3 Overloading the Comparison operator(==)
    bool operator==(Complex &other)const
    {
        return  (real==other.real && image==other.image);
    }//&& means "and".
    
    //Part 4 Overlaoding the Stream  Insertion and Extraction Operators
    friend std::ostream&operator <<(std::ostream& out,const Complex &other);

    friend std::istream& operator>>(std::istream&in, const Complex &other);
    
    void display()
    {
        cout<<"("<<real<<","<<image<<")"<<endl;
    }
    
};

std::ostream&operator <<(std::ostream& out,const Complex &other)
{
        out<<other.real<<","<<other.image<< endl;
        return out;
}

std::istream& operator>>(std::istream& in, const Complex &other){
    cout<<"Enter the real part";
    in >> other.real;
    cout<<"Enter the imaginary part";
    in>>other.image;
    return in;
    }



int main()
{
    Complex c1(1.1,2.2), c2(3.3,4.4);
    Complex c3=c1+c2;
    Complex c4=-c1;
    if (c1==c2){
        cout<<"c1 equals to c2"<<endl;
    }else{
            cout<<"c1 not equals to c2"<<endl;
        }
    c3.display();
    c4.display();
    
cin.get();
}

