/*Q3. Write a class Address with data members (string building, string street, string city ,int pin)
Implement constructors, getters, setters, accept(), and display() methods.
Test the class functunalities by creating the object of class and calling all the functions.
*/
#include<iostream>
using namespace std;

class Address
{
    private :
    string building;
    string street;
    string city;
    int pin;

    public:
    Address()
    {
        building = "Indumati Nivas";
        street = "Gautam Society";
        city = "Kolhapur";
        pin = 416003;
    }   
    void setBuilding(string building)
    {
        this->building=building;
    }
    string getBuilding()
    {
        return building;
    }
    void setStreet(string street)
    {
        this->street=street;
    }
    string getStreet()
    {
        return street;
    }
    void setCity(string city)
    {
        this->city=city;
    }
    string getCity()
    {
        return city;
    }
    void setPin(int pin)
    {
        this->pin=pin;
    }
    int getPin()
    {
        return pin;
    }

    void accept()
    {
        cout << "ENTER YOUR ADDRESS DETAILS-----" << endl;
        cout << "BUILDING - ";
        cin >> building ;
        cout << "STREET - ";
        cin >> street ;
        cout << "CITY - ";
        cin >> city;
        cout << "PIN - ";
        cin >> pin;
    }
    void display()
    {
        cout << "----------ADDRESS DETAILS----------" << endl;
        cout << "BUILDING - " << building << endl;
        cout << "STREET - " << street << endl;
        cout << "CITY - " << city << endl;
        cout << "PIN - " << pin << endl;
    }

};

int main()
{
    Address a;
    a.accept();
    a.display();

}
