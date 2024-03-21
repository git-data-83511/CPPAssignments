/*Q2. Write a class for Time and provide the functionality
Time()
Time(int h,int m,int s)
getHour()
getMinute()
getSeconds()
printTime()
setHour()
setMinute()
setSeconds()
Allocate the memory for the the object dynamically and test the functunalities using time ptr.*/

#include <iostream>
using namespace std;

class Time
{
private:
    int h;
    int m;
    int s;

public:
    Time()
    {
        h = 0;
        m = 0;
        s = 0;
    }

    Time(int h, int m, int s)
    {
        this->h = h;
        this->m = m;
        this->s = s;
    }

    void setH(int h)
    {
        this->h = h;
    }
    int getH()
    {
        return h;
    }

    void setM(int m)
    {
        this->m = m;
    }
    int getM()
    {
        return m;
    }

    void setS(int s)
    {
        this->s = s;
    }
    int getS()
    {
        return s;
    }

    void printTime()
    {
        cout << "TIME - " << h << ":" << m << ":" << s << endl;
    }
};

int main()
{
    Time *ptr1 = new Time();
    Time *ptr2 = new Time(11, 30, 22);

    ptr2->printTime();

    delete ptr1;
    delete ptr2;

    ptr1 = NULL;
    ptr2 = NULL;
}