/*Q1. Write a menu driven program to calculate volume of the box(length * width * height).
Provide parameterless, parameterized(with 3 parameters) and single paramaterized constructor.
Create the local objects in respective case and call the function to caluclate area.
Menu options ->
1. Calculate Volume with default values
2. Calculate Volume with length,breadth and height with same value
3. Calculate Volume with different length,breadth and height values.
*/

#include<iostream>
using namespace std;

class Box
{
    private :
    float length;
    float breadth;
    float height;
    float v;

    public :

    Box()
    {
        length = 5;
        breadth = 3;
        height = 6;
    }
    
    Box(float length,float breadth,float height)
    {
        this-> length = length;
        this-> breadth = breadth;
        this -> height = height;
    }
    Box(float value)
    {
        length = value;
        breadth = value;
        height = value;
    }
     void volume()
     {
        v = length*breadth*height;
        cout<<"VOLUME OF A BOX = "<< v << endl;
     }
};

int main()
{
    Box b1;
    b1.volume();
    Box b2(8,7,6) ;
    b2.volume();
    Box b3(5);
    b3.volume();
}