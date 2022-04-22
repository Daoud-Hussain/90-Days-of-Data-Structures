#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    int front = -1;
    int rear = -1;
    int size = 10;
    int *arr = new int[size];


    //Function to add an element in the queue
    void enQueue(int value)
    {
        if (front == -1 && rear == -1)
        {
            arr[front] = value;
            rear++;
        }
        else
        {
            rear++;
            arr[rear] = value;
        }
    }


    //Function to remove an element from the queue
    int deQueue()
{
    if (!isEmpty())
    {
       int value = arr[front];
       front++;
       return value;
    }
}

    //Funtion to check whether the queue is empty or not
    int isEmpty(){
        if (front == -1 && rear == -1){
            return 1;
        }
        return 0;
    }


    //Funtion to check whether the queue is FULL or not
    int isFull(){
        if (front == 0 && rear == size - 1)
        {
            return 1;
        }
        return 0;
    }
};


int main()
{
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.deQueue();
    q.deQueue();
    q.deQueue();
    

    return 0;
}