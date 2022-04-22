#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    int front = -1;
    int rear = -1;
    int size = 10;
    int *arr = new int[size];


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

    int isEmpty(){
        if (front == -1 && rear == -1){
            return 1;
        }
        return 0;
    }

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
    q.enQueue(50);
    

    return 0;
}