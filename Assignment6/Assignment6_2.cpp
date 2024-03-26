/*Q2. A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class
holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books.
Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program
should be menu driven and should not cause memory leakage.
Hint - Create class Product and inherit into Book and Tape. Also create array like Product* arr[3]*/

#include<iostream>
using namespace std;

class Products
{
    private :
    int id;
    string title;
    double price;

    public :

    Products()
    {
        id = 0;
        title = "";
        price = 0;
    }
    virtual void accept() // late binding
    {
        cout << "ENTER ID : ";
        cin >> id;
        cout << "ENTER TITLE : ";
        cin >> title;
        cout << "ENTER PRICE : ";
        cin >> price;
    }

    virtual void display() // late binding
    {
        cout << "ID : " << id << endl;
        cout << "TITLE : " << title << endl;
        cout << "PRICE : " << price << endl;
    }

    void setPrice(double price) 
    {
        this -> price = price;
    }  
    int getPrice()
    {
        return price;
    }  

};

class Book : public Products
{
    private:
    string author;

    public :
    void accept()
    {
        cout << "----------ENTER BOOK DETAILS----------" << endl;
        Products :: accept();
        cout << "ENTER AUTHOR NAME : ";
        cin >> author;
        setPrice(getPrice() - (getPrice()*0.10)); //set price as per discount
    }
    void display()
    {
        cout << "----------BOOK DETAILS----------" << endl;
        Products :: display();
        cout << "AUTHOR NAME : " << author << endl;
    }
};

class Tapes : public Products
{
    private :
    string artist;

    public:
    void accept()
    {
        cout << "----------ENTER TAPE DETAILS----------" << endl;
        Products :: accept();
        cout << "ENTER ARTIST NAME : ";
        cin >> artist;
        setPrice(getPrice()-(getPrice()*0.05)); //set price as per discount
    }
    void display()
    {
        cout << "----------TAPE DETAILS----------" << endl;
        Products :: display();
        cout << "ARTIST NAME : " << artist << endl;
    }

};
int main()
{
    int choice1 ;
    int choice2;
    
   // Products *ptr2 = new Tapes();
    Products *arr[3];
    
    
    do
    {
        cout << "0.EXIT" << endl;
        cout << "1.ADD PRODUCT" << endl;
        cout << "2.DISPLAY PRODUCT DETAILS" << endl;
        cout << "3.BILL" << endl;
        cout << "ENTER YOUR CHOICE : ";
        cin >> choice1;
        switch(choice1)
        {
            case 0:
                cout << "THANK YOU FOR SHOPPING" << endl;
                break;
            
            case 1:
                cout << "-----------PRODUCTS-----------" << endl;
                cout << "1. BOOK" << endl;
                cout << "2. TAPE" << endl;
                cout << "ENTER PRODUCT : ";
                cin >> choice2;
                switch(choice2)
                {
                    case 1:
                    {
                        Products *ptr = new Book();
                       
                        for(int i=0; i<=3; i++)
                        {
                            if(i<3)
                            {
                            if(arr[i] == NULL)
                            { 
                                ptr ->accept();
                                arr[i] = ptr;
                                cout << "PRODUCT ADDED TO YOUR CART" << endl;
                                break;
                            }
                            }
                            else
                            {
                                cout << "YOUR PURCHASE LIMIT EXCEED.." << endl;
                            }
                            
                            
                        }

                        break;
                    }
                    case 2:
                    {
                        Products *ptr = new Tapes();
                        
                        for(int i=0; i<3; i++)
                        {
                            if(i<3)
                            {
                            if(arr[i] == NULL)
                            {
                                ptr ->accept();
                                arr[i] = ptr;
                                cout << "PRODUCT ADDED TO YOUR CART" << endl;
                                break;
                            }
                            }
                            else
                            {
                                cout << "YOUR PURCHASE LIMIT EXCEED.." << endl;
                            }
                        }
                        break;
                    }  
                    default:
                        cout << "WRONG CHOICE.." << "endl";
                        break;  
                } 
                break;

            case 2:
                for(int i=0; i<3; i++)
                {
                    arr[i]->display();
                }
                break;

            case 3:
            {
                double totalprice = 0;
                for(int i=0; i<3; i++)
                {
                    totalprice = totalprice + arr[i]->getPrice();
                }
                cout << "TOTAL AMOUNT : " << totalprice << endl;
                break;
            }
            default:
                cout << "WRONG CHOICE......." << endl;
                break;

        }
    } while(choice1 != 0);
for(int i=0; i<3;i++)
{
    delete arr[i];
    arr[i] = NULL;
}
}