#include <iostream>
using namespace std;

struct Queue
{
    int front = -1;
    int rear = -1;
    int size = 10;
    string *arr = new string[size];

    void EnqueueFromFront(string data)
    {
        if ((front == 0 && rear == size - 1) || (front == rear + 1))
        {
            cout<<("Queue Overflow");
        }
        else if ((front == -1) && (rear == -1))
        {
            front = rear = 0;
            arr[front] = data;
        }
        else if (front == 0)
        {
            front = size - 1;
            arr[front] = data;
        }
        else
        {
            front = front - 1;
            arr[front] = data;
        }
    }

    void EnqueueFromRear(string data)
    {
        if ((front == 0 && rear == size - 1) || (front == rear + 1))
        {
            cout<<("Queue Overflow");
        }
        else if ((front == -1) && (rear == -1))
        {
            rear = 0;
            arr[rear] = data;
        }
        else if (rear == size - 1)
        {
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }


    void DequeueFromFront()
    {
        string value;
        if ((front == -1) && (rear == -1))
        {
            cout<<("You have not ordered anything. Order First!!")<<endl;
        }
        else if (front == rear)
        {
            cout<<"Your "<<arr[front]<<" is ready" <<endl;
            front = -1;
            rear = -1;
        }
        else if (front == (size - 1))
        {
            cout<<"Your "<<arr[front]<<" is ready" <<endl;
            front = 0;
        }
        else
        {
            cout<<"Your "<<arr[front]<<" is ready" <<endl;
            front = front + 1;
        }
    }
    
    
    void DequeueFromRear()
    {
        if ((front == -1) && (rear == -1))
        {
            cout<<("You have not ordered anything. Order First!!")<<endl;
        }
        else if (front == rear)
        {
            cout<<"Your "<<arr[rear]<<" is ready" <<endl;
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            cout<<"Your "<<arr[rear]<<" is ready" <<endl;
            rear = size - 1;
        }
        else
        {
            cout<<"Your "<<arr[rear]<<" is ready" <<endl;
            rear = rear - 1;
        }
    }
};

int main(){
    int choice;
    string order;
    Queue myQueue;
    bool flag = true;
    while(flag){
        cout<<"Enter 1 to place order from front: "<<endl;
        cout<<"Enter 2 to place order from rear: "<<endl;
        cout<<"Enter 3 to get order from front: "<<endl;
        cout<<"Enter 4 to get order from front: "<<endl;
        cout<<"Enter 5 to exit: "<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                cout<<"Enter your order to place: ";
                cin>>order;
                myQueue.EnqueueFromFront(order);
                break;
            case 2:
                cout<<"Enter your order to place: ";
                cin>>order;
                myQueue.EnqueueFromRear(order);
                break;
            case 3:
                myQueue.DequeueFromFront();
                break;
            case 4:
                myQueue.DequeueFromRear();
                break;
            case 5:
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
