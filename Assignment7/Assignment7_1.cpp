/*Q1. Provide menu driven code for the functionalities:
1. Accept Employee
2. Display the count of all employees with respect to designation
3. Display All Managers
4. Display All Salesman
5. Display All SalesManagers*/

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
    int choice1,choice2;
    int index=0;
    int m_count = 0;
    int s_count = 0;
    int sm_count = 0;
    Employee *arr[5];
    do
    {
        cout << "0. EXIT" << endl;
        cout << "1. ACCEPT EMPLOYEE" << endl;
        cout << "2. COUNT OF EMPLOYEES" << endl;
        cout << "3. DISPLAY MANAGERS LIST" << endl;
        cout << "4. DISPLAY SALESMANS LIST" << endl;
        cout << "5. DISPLAY SALESMANAGERS LIST" << endl;
        cout << "ENTER YOUR CHOICE : ";
        cin >> choice1;

        switch(choice1)
        {
            case 1:
                    {
                        cout << "-----EMPLOYEE DESIGNATIONS-----" << endl;
                        cout << "1. ACCEPT MANAGER" << endl;
                        cout << "2. ACCEPT SALESMAN" << endl;
                        cout << "3. ACCEPT SALESMANAGER" << endl;
                        cout << "ENTER YOUR CHOICE : ";
                        cin >> choice2;
                        switch (choice2)
                        {
                            case 1:
                                if(index<5)
                                {
                                    arr[index] = new Manager();
                                            arr[index] ->accept();
                                            index++;
                                            cout << "EMPLOYEE DETAILS ADDED" << endl;
                                }
                                else
                                {
                                    cout << "NO EMPLOYEE VACANCIES" << endl;
                                }
                                break;

                            case 2:
                                if(index<5)
                                {
                                    arr[index] = new Salesman();
                                            arr[index] ->accept();
                                            index++;
                                            cout << "EMPLOYEE DETAILS ADDED" << endl;
                                }
                                else
                                {
                                    cout << "NO EMPLOYEE VACANCIES" << endl;
                                }
                                break;

                        
                            case 3:
                                if(index<5)
                                {
                                    arr[index] = new SalesManager();
                                            arr[index] ->accept();
                                            index++;
                                            cout << "EMPLOYEE DETAILS ADDED" << endl;
                                }
                                else
                                {
                                    cout << "NO EMPLOYEE VACANCIES" << endl;
                                }
                                break;

                        }
                    }
                    break;

            case 2:
                {
                    for(int i=0; i < index ; i++)
                    {
                        if(typeid(*arr[i]).name()==typeid(Manager).name())
                        {
                            m_count++;
                        }
                        if(typeid(*arr[i]).name()==typeid(Salesman).name())
                        {
                            s_count++;
                        }
                        if(typeid(*arr[i]).name()==typeid(SalesManager).name())
                        {
                            sm_count++;
                        }
                    }

                    cout << "NUMBER OF MANAGERS : " << m_count << endl;
                    cout << "NUMBER OF SALESMAN : " << s_count << endl;
                    cout << "NUMBER OF SALESMANAGER : " << sm_count << endl;
                }
                break;

            case 3:
                {
                    cout << "----------MANAGERS LIST----------" << endl;
                    int count = 0;

                    for(int i = 0; i < index; i++)
                    {
                        if(typeid(*arr[i])==typeid(Manager))
                        {
                            arr[i] ->display();
                            count++;
                        }

                    }
                    if(count == 0)
                    {
                        cout << "THERE ARE NO MANAGERS IN THE COMPANY" << endl;
                    }

                }
                break;

            case 4:
                {
                    cout << "----------SALESMAN LIST----------" << endl;
                    int count = 0;

                    for(int i = 0; i < index; i++)
                    {
                        if(typeid(*arr[i])==typeid(Salesman))
                        {
                            arr[i] ->display();
                            count++;
                        }

                    }
                    if(count == 0)
                    {
                        cout << "THERE ARE NO SALESMEN IN THE COMPANY" << endl;
                    }

                }
                break;

            case 5:
                {
                    cout << "----------SALESMANAGER LIST----------" << endl;
                    int count = 0;

                    for(int i = 0; i < index; i++)
                    {
                        if(typeid(*arr[i])==typeid(SalesManager))
                        {
                            arr[i] ->display();
                            count++;
                        }

                    }
                    if(count == 0)
                    {
                        cout << "THERE ARE NO SALESMANAGER IN THE COMPANY" << endl;
                    }

                }
                break;

            default:
                cout << "WRONG CHOICE......" << endl;   

        }

    }while(choice1 != 0);
    for(int i=0; i<index; i++)
    {
        delete arr[i];
        arr[i] = NULL;
    }

}