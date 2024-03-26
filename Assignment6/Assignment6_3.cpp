/*Q3. Implement following classes. Test all functionalities in main() of each created class. Note that
employee is inherited into manager and salesman.*/

#include<iostream>
using namespace std;

 class Employee 
 {
    private :
    int id;
    double salary;

    public:
    Employee()
    {
        id = 0;
        salary = 0;
    }

    Employee(int id, double salary)
    {
        this -> id = id;
        this -> salary = salary;
    }

    void setId(int id)
    {
        this -> id = id;
    }
    int getId()
    {
        return id;
    }

    void setSalary(double salary)
    {
        this -> salary = salary;
    }
    double getsalary()
    {
        return salary;
    }

    virtual void accept() //late binding
    {
        cout << "ENTER EMPLOYEE ID : ";
        cin >> id ;
        cout << "ENTER SALARY : ";
        cin >> salary;
    }

    virtual void display() // late binding
    {
        cout << "EMPLOYEE ID - " << id << endl;
        cout << "SALARAY - " << salary << endl;
    }
    ~ Employee()
    {

    }
 };

 class Manager : virtual public Employee 
 {
    private :
    double bonus;

    protected :
    void acceptManager()
    {
        cout << "ENTER BONUS AMMOUNT : ";
        cin >> bonus;
    }
    void displayManager()
    {
        cout << "BONUS AMOUNT - " << bonus << endl;
    }
    public :
    Manager()
    {
        bonus = 0;
    }

    Manager(int id, double salary, double bonus) : Employee(id,salary)
    {
        this -> bonus = bonus ;
    }

    void setBonus(double bonus)
    {
        this -> bonus = bonus;
    }
    double getBonus()
    {
        return bonus;
    }

    void accept()
    {
        cout << "----------ENTER MANAGER DETAILS----------" << endl;
        Employee :: accept();
        acceptManager();
    }

    void display()
    {
        cout << "----------MANAGER DETAILS----------" << endl;
        Employee :: display();
        displayManager();
    }
    ~ Manager()
    {

    }
 };

 class Salesman : virtual public Employee 
 {
    private :
    double commision;

    protected :
    void acceptSalesman()
    {
        cout << "ENTER COMMISION AMMOUNT : ";
        cin >> commision;
    }
    void displaySalesman()
    {
        cout << "COMMISION AMOUNT - " << commision << endl;
    }
    public :
    Salesman()
    {
        commision = 0;
    }

    Salesman(int id, double salary, double commision) 
    {
        this -> commision = commision ;
        this -> setId(id);
        this -> setSalary(salary);
    }

    void setCommision(double commision)
    {
        this -> commision = commision;
    }
    double getCommision()
    {
        return commision;
    }

    void accept()
    {
        cout << "----------ENTER SALESMAN DETAILS----------" << endl;
        Employee :: accept();
        acceptSalesman();
    }

    void display()
    {
        cout << "----------SALESMAN DETAILS----------" << endl;
        Employee :: display();
        displaySalesman();
    }
    ~Salesman()
    {

    }
 };

 class SalesManager : public Manager, public Salesman //multiple inheritance
 {
    public :
    SalesManager()
    {

    }

    SalesManager(int id, double salary, double bonus, double commision) : Manager(id,salary,bonus) , Salesman(id,salary,commision)
    {

    }

    void accept()
    {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }
    ~SalesManager()
    {

    }
 };

int main()
{
    SalesManager s;
    s.accept();
    s.display();
}