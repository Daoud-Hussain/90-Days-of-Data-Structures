#include <iostream>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    string *arrOrder;
    int *arrAge;

    Queue()
    {
        size = 10;
        front = -1;
        rear = -1;
        arrOrder = new string[size];
        arrAge = new int[size];
    }

    bool isFull()
    {
        if ((rear + 1) & size == front)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (rear == -1)
        {
            return true;
        }
        return false;
    }

    void Enqueue(string data, int age)
    {
        if (isFull())
        {
            cout << "Queue OverFlow" << endl;
        }
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
            arrOrder[rear] = data;
            arrAge[rear] = age;
            rear = (rear + 1) % size;
        }
        else
        {
            arrOrder[rear] = data;
            arrAge[rear] = age;
            rear = (rear + 1) % size;
        }
    }

    string Dequeue()
    {
        if (!isEmpty() && front != rear)
        {   
            int fr = front;
            int  max = 1000;
            int maxAgeIndex;
            while (fr != rear)
            {
                if(arrAge[fr] > max){
                    max = arrAge[fr];
                    maxAgeIndex = fr;

                }
                fr = (fr+1)%size;
            }
            
            string value = arrOrder[maxAgeIndex];
            int age = arrAge[max];
            max = (front + 1) % size;
            cout<<"Your "<< value << " is ready according to your age ie, "<< age<<endl;
            return value;
        }
        else{
            front = rear = -1;
            cout<<"You have not ordered anything! Order First"<<endl;
        }
    }

    void display()
    {
        if (front == rear)
        {
            cout << "Empty Queue";
        }
        else
        {
            int f = front;
            while (f != rear)
            {
                cout << arrOrder[f] << " ";
                f = (f + 1) % size;
            }
        }
    }
};

int main()
{   
    int choice;
    string yourOrder;
    int yourAge;
    Queue myQueue;
    bool flag = true;
    while(flag){
        cout<<"Enter 1 to place order: "<<endl;
        cout<<"Enter 2 to get order: "<<endl;
        cout<<"Enter 3 to exit: "<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                cout<<"Enter your age: ";
                cin>>yourAge;
                cout<<"Enter your order to place: ";
                cin>>yourOrder;
                myQueue.Enqueue(yourOrder, yourAge);
                break;
            case 2:
                myQueue.Dequeue();
                break;
            case 3:
                cout<<"Exit"<<endl;
                flag = false;
                break;
            default: 
                cout<<"Invalid input"<<endl;
                break;
        }
        cout<<endl;

    }

}