/*Q1. Implement following classes. Test all functionalities in main().
Create a class Date with data memebrs day,month and year.
Cretae a class Person with data members name,address and birthdate. The birthdate shoud be of
type date.
Cretae a class Employee with data members id, sal, dept and joining date. The joining date should
be of type date.*/

#include<iostream>
using namespace std;

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date(): day(1),month(1),year(2024)
        {
            
        }   

        void acceptDate(){
            cout<<"Enter Day: ";
            cin>>day;
            cout<<"Enter Month: ";
            cin>>month;
            cout<<"Enter year: ";
            cin>>year;

        }
        void displayDate(){
            cout<<day<<"-"<<month<<"-"<<year<<endl;
        }
};  

class Person{
    private:
        string name;
        string address;
        Date *birDate;
    public:
        Person()
        {
            name = "";
            address = ""; 
            birDate = new Date;
        }    
        
        void acceptPerson(){
            cout<<"Enter the Person Name: ";
            cin>>name;
            cout<<"Enter Address :";
            cin>>address;
            cout<<"Enter Birth Date - "<<endl;
            birDate->acceptDate();
        }
        
        void displayPerson(){
            cout<<"The Details of the Person are: "<<endl;
            cout<<"Name : "<<name<<endl;
            cout<<"Address : "<<address<<endl;
            cout<<"BirthDate : ";
            birDate->displayDate();
        }

        ~Person(){
            delete birDate;
            birDate = NULL;
        }

};

class Employee{
    private:
        const int id;
        double sal;
        string dept;
        Date *joinDate;
        static int generateEmpId;

    public:
    Employee():id(++generateEmpId)
    {
        sal = 10000;
        dept = "";
        joinDate = new Date;
    }

    void acceptEmployee(){
        cout<<"Enter Salary: ";
        cin>>sal;
        cout<<"Enter Department : ";
        cin>>dept;
        cout<<"Enter the Joining Date - "<<endl;
        joinDate->acceptDate();

    }

    void diplayEmployee(){
        cout<<"The Employee Details are: "<<endl;
        cout<<"Employee Id - "<<id<<endl;
        cout<<"Salary - "<<sal<<endl;
        cout<<"Department - "<<dept<<endl;
        cout<<"The Joining Date -";
        joinDate->displayDate();

    }

    ~Employee(){
        delete joinDate;
        joinDate = NULL;
    }

};

int Employee::generateEmpId = 0;

enum eMenu
{
    EXIT,
    ACCEPT_PERSON,
    DISPLAY_PERSON,
    ACCEPT_EMPLOYEE,
    DISPLAY_EMPLOYEE


};

int main(){
    Person p;
    Employee e;
    Employee e1;
    int choice;
    do{
        cout<<"0. Exit"<<endl;
        cout<<"1. To Enter Person details"<<endl;
        cout<<"2. To Display Person Details"<<endl;
        cout<<"3. To Enter Employee Details"<<endl;
        cout<<"4. To Display Employee Details"<<endl;   
        cin>>choice;

        switch(choice){
            case EXIT: 
                    cout<<"Thank You For Using Our Application!!"<<endl;
                    break;

            case ACCEPT_PERSON: 
                    p.acceptPerson();
                    break;

            case DISPLAY_PERSON: 
                    p.displayPerson();
                    break;

            case ACCEPT_EMPLOYEE:  
                    e.acceptEmployee();
                    break;

            case DISPLAY_EMPLOYEE: 
                    e.diplayEmployee();
                    break;
        }
    } while(choice!=EXIT);
}