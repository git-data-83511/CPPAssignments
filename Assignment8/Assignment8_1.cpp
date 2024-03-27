#include<iostream>
using namespace std;
 
 enum EAccountType
 {
    Saving = 1,
    Current,
    Dmat
 };

class inSufficientFundException
{
    private :
    int accno;
    double currentBalance;
    double withdrawAmount;

    public :
    inSufficientFundException(int accno, double currentBalance, double withdrawAmount)
    {
        this -> accno = accno;
        this -> currentBalance = currentBalance;
        this -> withdrawAmount = withdrawAmount;
    }

    void display()
    {
        cout << endl;
        cout << "----------INSUFFICIENT BALANCE----------" << endl;
        cout << "ACCOUNT NUMBER : " << accno << endl;
        cout << "CURRENT BALANCE : " << currentBalance << endl;
        cout << "WITHDRAWAL AMOUNT : " << withdrawAmount << endl;
    }
    ~inSufficientFundException()
    {

    }
};

class Account
{
    private :
    int accno;
    EAccountType acctype;
    double balance;

    public :
    Account()
    {
        this -> accno = 0;
        this ->acctype = EAccountType(1);
        this -> balance = 0;
    }
    Account(int accno, EAccountType acctype, double balance)
    {
        this -> accno = accno;
        this -> acctype = acctype;
        this -> balance = balance;
    }
    
    void accept()
    {
        int n;
        cout << "ENTER ACCOUNT NUMBER : ";
        cin >> accno;
        cout << "-----ACCOUNT TYPE-----" << endl;
        cout << "1. SAVING" << endl;
        cout << "2. CURRENT" << endl;
        cout << "3. DMAT" << endl;
        cout << "ENTER YOUR CHOICE : ";
        cin >> n;
        acctype = EAccountType(n);
        cout << "ENTER BALANCE : ";
        cin >> balance;

    }
    void display()
    {
        cout << "----------BANK ACCOUNT DETAILS----------" << endl;
        cout << "ACCOUNT NUMBER : " << accno << endl;
        if(acctype == EAccountType(1))
        {
            cout << "ACCOUNT TYPE : SAVINGS" << endl;
        }
          if(acctype == EAccountType(2))
        {
            cout << "ACCOUNT TYPE : CURRENT" << endl;
        }
          if(acctype == EAccountType(3))
        {
            cout << "ACCOUNT TYPE : DMAT" << endl;
        }
        cout << "BALANCE : " << balance << endl;
    }

    void deposit(double amount)
    {
        balance = balance + amount;
        cout << "CURRENT BALANCE : " << balance << endl;
    }
    void withdraw(double amount)
    {
        if(balance-amount<0)
        {
            throw inSufficientFundException(getAccno(),getBalance(),amount);
        }
        else
        {
            cout << "CURRENT BALANCE : " << balance << endl;
            balance = balance - amount;
            cout << "AFTER WITHDRAWAL BALANCE : " << balance << endl;
        }
    }

    int getAccno()
    {
        return accno;
    }
    int getBalance()
    {
        return balance;
    }
    ~Account()
    {

    }

};

int main()
{
    Account *arr[5];
    int choice;
    int index = 0;

    do
    {
        cout << "0. EXIT" << endl;
        cout << "1. ENTER ACCOUNT DETAILS" << endl;
        cout << "2. DISPLAY ACOUNT DETAILS" << endl;
        cout << "3. DEPOSIT AMOUNT" << endl;
        cout << "4. WITHDRAW AMOUNT" << endl;
        cout << "ENTER YOUR CHOICE : ";
        cin >> choice;
        switch(choice)
        {
            case 0:
                cout << "THANK YOU......" << endl;
                break;

            case 1:
                if (index<5)
                {
                    arr[index]=new Account();
                    arr[index]->accept();
                    index++;
                    cout << "ACOUNT DETAILS ADDED" << endl;
                }
                break;

            case 2:
                {
                     for (int i = 0; i < index; i++)
                    {
                        arr[i]->display();
                        
                    }
                }

            case 3:
                {
                    int no;
                    double amount;

                    try
                    {
                        cout<<"ENTER ACCOUNT NUMBER : "<<endl;
                        cin>>no;
                        int flag=1;
                        for (int i = 0; i < index; i++)
                        {
                            if (no==arr[i]->getAccno())
                            {
                                flag=0;
                            }
                
                        }
                        if (flag==1)
                        {
                            throw 2.5;
                        }
        
                        try
                        {
                            cout<<"ENTER AMOUNT : ";
                            cin>>amount;

                            if (amount<=0)
                            {
                                throw 1;
                            }

                            for (int i = 0; i < index; i++)
                            {
                                if (no==arr[i]->getAccno())
                                {
                                    arr[i]->deposit(amount);

                                }
                                break;
                                
                            }
                    


                        }
                        catch(int)
                        {
                            cout<<"DEPOSIT FAILED"<<endl;
                            cout<<"AMMOUNT CAN NOT BE NEGATIVE.." << endl;
                        }
            
           


                    }
        
                    catch(double)
                    {
                        cout<<"ENTER VALID ACCOUNT NUMBER...." << endl;
                    }
                }
                break;
            
            case 4:
                {
                    int no;
                    double amount;
                    try
                    {
                        cout<<"ENTER ACCOUNT NUMBER : " << endl;
                        cin>>no;
                        int flag=1;
                        for (int i = 0; i < index; i++)
                        {
                            if (no==arr[i]->getAccno())
                            {
                                flag=0;
                            }
                
                        }
                        if (flag==1)
                        {
                            throw 2.5;
                        }

                        cout<<"ENTER AMOUNT : ";
                        cin>>amount;

                        try
                        {

                            for (int i = 0; i < index; i++)
                            {
                                if (no==arr[i]->getAccno())
                                {
                                    arr[i]->withdraw(amount);
                                }
                        
                            }
                        }
                        catch(inSufficientFundException e)
                        {
                            e.display();
                        }
                    }
                    catch(double)
                    {
                        cout<<"ENTER VALID ACCOUNT NUMBER...."<<endl;
                    }
                    break;
                }
        default:
            cout<<"WRONG CHOICE...."<<endl;
            break;

        }
    }while(choice !=0);

    return 0;
}

