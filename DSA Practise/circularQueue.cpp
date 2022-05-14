#include <iostream>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;

    Queue()
    {
        size = 10;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    bool isFull()
    {
        if((rear+1)%size == front){
            return true;
        }
        return false;
        
    }

    bool isEmpty()
    {
        if(rear == -1){
            return true;        
        }
        return false;
    }


    void Enqueue(int data)
    {
        if(isFull()){
            cout<<"Queue OverFlow"<<endl;
        }
        else if(isEmpty()){
            front = rear = 0;
            arr[rear] = data;
            rear = (rear + 1) % size;
        }
        else{
            arr[rear] = data;
            rear = (rear + 1) % size;
        }
    }

    int Dequeue()
    {
        if(isEmpty()){
            cout<<"Queue UnderFlow"<<endl;
        }
        else {
            int value = arr[front];
            front = (front + 1)% size;
            return value;
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
                cout << arr[f] << " ";
                f = (f + 1) % size;
            }
        }
    }
};



int main(){
    Queue myQueue;
    myQueue.Enqueue(10);
    myQueue.Enqueue(20);
    myQueue.Enqueue(30);
    myQueue.Enqueue(40);
    myQueue.Enqueue(50);
    myQueue.Enqueue(60);
    myQueue.Enqueue(70);

    myQueue.display();
    cout<<endl;

    myQueue.Dequeue();
    myQueue.Dequeue();
    myQueue.Dequeue();
    myQueue.display();


}