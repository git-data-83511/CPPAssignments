#include <iostream>
using namespace std;

class Date
{
    private :
    int day;
    int month;
    int year;

    public :
    void initDate()
    {
        day = 29;
        month = 01;
        year = 2001;
    }
    void printDateOnConsole()
    {
        cout << "DAY - " << day << endl;
        cout << "MONTH - " << month << endl;
        cout << "YEAR - " << year << endl;
    }
    void acceptDateFromConsole()
    {
        cout << "ENTER DAY - ";
        cin >> day;
        cout << "ENTER MONTH - ";
        cin >> month;
        cout << "ENTER YEAR - ";
        cin >> year;
    }
    bool isLeapYear()
    {
        if(year%4==0 && year != 100 || year % 400 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    int choice;
    Date d;
     do
    {
        cout << "0. EXIT" << endl;
        cout << "1. SET INITIAL DATE" << endl;
        cout << "2. ENTER DATE" << endl;
        cout << "3. DISPLAY DATE" << endl;
        cout << "4. CHECK WHETHER LEAP YEAR OR NOT" << endl;
        cout << "ENTER YOUR CHOICE" << endl;
        cin >> choice;

        switch(choice)
        {
            case 0:
                cout << "THANK YOU FOR USING OUT APP......" << endl;
                break;

            case 1:
                d.initDate();
                break;
            
            case 2:
                d.acceptDateFromConsole();
                break;

            case 3:
                d.printDateOnConsole();
                break;

            case 4:
                if(d.isLeapYear())
                {
                    cout << "LEAP YEAR.." << endl;
                }
                else
                {
                    cout << "NOT A LEAP YEAR.." << endl;
                }
                break;

            default:
                cout << "WRONG CHOICE ......" << endl;
                break;

        }
    }while(choice != 0);
}
