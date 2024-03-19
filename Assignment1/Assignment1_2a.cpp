#include<iostream>
using namespace std;
struct Date
{
    int day;
    int month;
    int year;
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

    void initDate(struct Date* ptrDate)
    {
        &(ptrDate->day = 3);
        &(ptrDate->month = 3);
        &(ptrDate->year = 2024);
    }

   
    void acceptDateFromConsole(struct Date* ptrDate)
    {
        cout<<"ENTER DAY - ";
        cin>> ptrDate->day;
        cout<<"ENTER MONTH - ";
        cin>> ptrDate->month ;
        cout<<"ENTER YEAR - ";
        cin>> ptrDate->year ;
    }

     void printDateOnConsole(struct Date* ptrDate)
    {
        cout<<"DAY - "<< ptrDate->day << endl;
        cout<<"MONTH - "<< ptrDate->month << endl;
        cout<<"YEAR - "<< ptrDate->year << endl;
    }

    




int main()
{
    int choice;
    struct Date d1;
    
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
                initDate(&d1);
                break;
            
            case 2:
                acceptDateFromConsole(&d1);
                break;

            case 3:
                printDateOnConsole(&d1);
                break;

            case 4:
                if(d1.isLeapYear())
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
