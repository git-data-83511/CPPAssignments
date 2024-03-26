/*Q1. Create a class Date with data memebrs day,month and year.
Cretae a class Person with data members name,address and birthdate. The birthdate shoud be of
type Date.
Cretae a class Employee with data members id, sal, dept and joining date. The joining date should
be of type date.
Employee class should be inherited from Person.
Implement following classes. Test all functionalities in main().
(Note - Perform the Association and Inheritance in the above case.)*/

#include<iostream>
using namespace std;

class Date 
{
    private :
    int day;
    int month;
    int year;
     
    public :
    Date(): day(1),month(1),year(2024)
        {
            
        }   
    void acceptDate()
    {
        //cout << "ENTER DATE : " << endl;
        cout << "DAY - ";
        cin >> day;
        cout << "MONTH - ";
        cin >> month;
        cout << "YEAR - ";
        cin >> year;
    }
    void displayDate()
    {
        cout << day << "/" << month << "/" << year << endl;
        
    }
};

class Person
{
    private :
    string name; 
    string address;
    Date birthDate; // Association -> Composition

    public:
    Person()
    {
        name = "";
        address = "";
    }
     virtual void acceptData() // late binding
    {
        cout << "----------ENTER PERSON DETAILS----------"<< endl;
        cout << "ENTER NAME : ";
        cin >> name ;
        cout << "ENTER ADDRESS : ";
        cin >> address;
        cout << "ENTER BIRTH DATE : " << endl;
        birthDate.acceptDate();
    }
    virtual void displayData() // late binding
    {
        cout << "----------PERSON DETAILS----------" << endl;
        cout << "NAME : " << name << endl;
        cout << "ADDRESS : " << address << endl;
        cout << "BIRTH DATE : " ;
        birthDate.displayDate();
    }

};

class Employee : public Person // Single Inheritance
{
    private :
    int id;
    float salary;
    string deptname;
    Date doj; // Association -> Composition

    public :
    Employee()
    {
        id = 0;
        salary = 0;
        deptname = "";
    }

    void acceptData()
    {
        Person :: acceptData();
        cout << "----------ENTER EMPLOYEE DETAILS----------" << endl;
        cout << "ENTER EMPLYEE ID : ";
        cin >> id;
        cout << "ENTER SALARY : ";
        cin >> salary;
        cout << "ENTER DEPARTMENT NAME : ";
        cin >> deptname;
        cout << "ENTER DATE OF JOINING : " << endl;
        doj.acceptDate();
        
    }
    void displayData()
    {
        Person :: displayData();
        cout << "----------EMPLOYEE DETAILS----------" << endl;
        cout << "EMPLOYEE ID : " << id << endl;
        cout << "SALARY : " << salary << endl;
        cout << "DEPARTMENT NAME : " << deptname << endl;
        cout << "DATE OF JOINING : ";
        doj.displayDate();
    }
};

int main()
{
    Person p;
    p.acceptData();
    p.displayData();
    Employee e;
    e.acceptData();
    e.displayData();
    Person *ptr = new Employee(); 
    ptr ->acceptData();
    ptr ->displayData();
}