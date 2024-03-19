#include<iostream>
using namespace std;

class Student
{
    private:
        int rollno;
        string name;
        float marks;

    public:
    void initStudent()
    {
        rollno = 1;
        name = "Gunesh";
        marks = 80;
    }
    void printStudentOnConsole()
    {
        cout << "Roll No. - " << rollno << endl;
        cout << "Name - " << name << endl;
        cout << "Marks - " << marks << endl;
    }
    void acceptStudentFromConsole()
    {
        cout << "ENTER ROLL NO. - ";
        cin >> rollno ;
        cout << "ENTER NAME - ";
        cin >> name ;
        cout << "ENTER MARKS - ";
        cin >> marks ;
    }
};

int main()
{
    int choice;
    Student s1;
    do
    {
        cout << "0. EXIT" << endl;
        cout << "1. SET DEFAULT STUDENT DETAILS" << endl;
        cout << "2. DISPLAY STUDENT DETAILS" << endl;
        cout << "3. ENTER STUDENT DETAILS" << endl;
        cin >> choice;
        switch(choice)
        {
            case 0:
                cout << "THANK YOU FOR USING OUR APP ......." << endl;
                break;
            
            case 1:
                s1.initStudent();
                break;
            
            case 2:
                s1.printStudentOnConsole();
                break;

            case 3:
                s1.acceptStudentFromConsole();
                break;

            default:
                cout << "WRONG CHOICE....." << endl;
                break;

        }
    }while(choice !=0);

}