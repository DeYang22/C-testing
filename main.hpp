class Time
{
private:
    int hour;
    int minutes;
public:
    Time();
    Time(int h, int m=0);
    void Addmin(int m);
    void Addhr(int h);
    void Reset(int h=0,int m=0);
    Time operator+(const Time&t)const;// New:"+" overloading
    void Show() const;
    
    
};

