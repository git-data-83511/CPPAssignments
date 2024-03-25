/*Q1. Stack is a Last-In-First-Out data structure. Write a Stack class. It implements stack using
Dynamically allocated array. Stack size should be passed in parameterized constructor. If size is not
given, allocate stack of size 5.
Provide member functions like push(), pop(), peek(), isEmpty(), isFull(), and print().*/

#include<iostream>
using namespace std;

class Stack{
    private:
        int index;
        int size;
        int *ptr;

    
    public:

    Stack(int size = 5)
    {
        this->size = size;
        index = -1;
        ptr = new int[size];
    }

    void push(int element)
    {
        if(!isFull())
        {    
            index++;
            ptr[index] = element;
        }    
        else 
            cout<<"Can't push "<<element<<" , Stack Overflowed!!"<<endl;    
    }

    void pop()
    {
        if(!isEmpty())
            {cout<<"The element "<<ptr[index]<<" has been popped out!"<<endl;
            index--;}
        else 
            cout<<"Stack is Empty"<<endl;    
    }    

    void peek()
    {
        if (!isEmpty())
        
            cout<<"The Element at the Top :  "<<ptr[index]<<endl;
        
        else
            cout<<"The Stack is empty, Enter a value to peek!"<<endl;
        
    }

    bool isEmpty()
    {
        return index==-1;
    }

    bool isFull()
    {
        return index == size-1;
    }

    void print()
    { 
        cout << "STACK ELEMETS : " << endl;
        for(int i = 0; i<= index; i++){
            cout<<ptr[i]<<" ";
        }
    }

    ~Stack(){
        delete[] ptr;
        ptr = NULL;
    }

};

int main(){
    int size;
    cout<<"Enter Size: ";
    cin>>size;
    Stack s(size);
    
    int choice;
    do{
        
        cout<<"0. Exit"<<endl;
        cout<<"1. Push Stack Element"<<endl;
        cout<<"2. Pop an Element"<<endl;
        cout<<"3. Peek the Top Element"<<endl;
        cout<<"4. Display the Stack"<<endl;
        cin>>choice;

        switch(choice){
            case 1 :    int element;
                        cout<<"Enter a value: ";
                        cin>>element;
                        s.push(element);
                        break;

            case 2 :    s.pop();
                        break;

            case 3 :    s.peek();
                        break;

            case 4 :    s.print();
                        cout<<endl;
                        break;
        }
        } while(choice!=0);

    return 0;
}