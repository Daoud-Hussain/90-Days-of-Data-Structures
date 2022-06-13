#include<iostream>
using namespace std;


struct Queue{
    int front = -1;
    int rear = -1;
    int size = 10;
    int* arr = new int[size];


    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        }
        return false;
    }

    bool isFull(){
        if(rear == size - 1){
            return true;
        }
        return false;
    }

    void enQueue(int data){
        if(isFull()){
            cout<<"Queue Overflow"<<endl;
        }
        else if(isEmpty()){
            front++;
            rear++;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
    }

    int deQueue(){
        if(isEmpty()){
            cout<<"Queue UnderFLow"<<endl;
        }
        else{
            int value = arr[front];
            front++;
            return value;
        }
    }
    

    void display(){
        int fr = front;
        while(fr != rear){
            cout<<arr[fr]<<" ";
            fr++;
        }
        if(fr == rear){
            cout<<arr[fr]<<" ";
        }
    }




};

int main()
{
    Queue myQueue;
    myQueue.enQueue(10);
    myQueue.enQueue(20);
    myQueue.enQueue(30);
    myQueue.enQueue(40);
    myQueue.enQueue(50);
    myQueue.enQueue(70);
    myQueue.enQueue(80);

    cout<<"Before"<<endl;
    myQueue.display();
    cout<<endl;
    cout<<"After"<<endl;
    myQueue.deQueue();
    myQueue.deQueue();
    myQueue.display();




}