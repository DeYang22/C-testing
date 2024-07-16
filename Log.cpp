#include "main.hpp"
#include <iostream>
//In this file, we define all the member functions in head file.
Time::Time()
{
    hour=minutes=0;
}
Time::Time(int h, int m)
{
    hour=h;
    minutes=m;
}
void Time::Addmin(int m)
{
    minutes+=m;
    hour+=minutes/60;
    minutes%=60;
}
void Time::Addhr(int h)
{
    hour+=h;
}
void Time::Reset(int h, int m)
{
    hour=h;
    minutes=m;
}

Time Time::operator+(const Time&t) const
//New:"+" overloading
{
    Time sum;
    sum.minutes=minutes+t.minutes;
    sum.hour=hour+t.hour+sum.minutes/60;
    sum.minutes%=60; // calulate the mod of minutes
    return sum;
}
void Time::Show() const
{
    std::cout<<hour<<"hours"<<minutes<<"mintues";
}
