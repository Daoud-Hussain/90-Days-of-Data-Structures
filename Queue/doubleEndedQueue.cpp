#include <iostream>
using namespace std;

struct Queue
{
    int front = -1;
    int rear = -1;
    int size = 10;
    int *arr = new int[size];

    // Method to check whether the queue is full or not
    bool isFull()
    {
        if (((front == 0) && (rear = size - 1)) || (front = rear + 1))
        {
            return true;
        }
        return false;
    }

    // Method to check whether the queue is empty or not
    bool isEmpty()
    {
        if ((front == -1) && (rear == -1))
        {
            return true;
        }
        return false;
    }

    // Method to add an element from the rear
    void EnqueueFromRear(int data)
    {
        if ((front == 0 && rear == size - 1) || (front == rear + 1))
        {
            cout << "No place to enqueu" << endl;
        }
        else if ((front == -1) && (rear == -1))
        {
            front = rear = 0;
            arr[rear] = data;
        }
        else if (rear = size - 1)
        {
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear = rear + 1;
            arr[rear] = data;
        }
    }

    // void EnqueueFromRear(int data)
    // {
    //     if ((front == 0 && rear == size - 1) || (front == rear + 1))
    //     {
    //         cout<<("Queue Overflow");
    //     }
    //     else if ((front == -1) && (rear == -1))
    //     {
    //         front = rear = 0;
    //         arr[rear] = data;
    //     }
    //     else if (rear == size - 1)
    //     {
    //         rear = 0;
    //         arr[rear] = data;
    //     }
    //     else
    //     {
    //         rear++;
    //         arr[rear] = data;
    //     }
    // }

    // Method to delete an element from the rear
    int DequeuFromRear()
    {
        if (( front == -1 && rear == -1))
        {
            cout << "No element to dequeu" << endl;
            return -1;
        }
        else if (rear = 0)
        {
            int value = arr[rear];
            rear = size - 1;
            return value;
        }
        else
        {
            int value = arr[rear];
            rear++;
            return value;
        }
    }
};
int main()
{
    Queue myQueue;
    myQueue.EnqueueFromRear(10);
    myQueue.EnqueueFromRear(20);
    myQueue.EnqueueFromRear(30);
    myQueue.EnqueueFromRear(40);
    myQueue.EnqueueFromRear(50);

    cout<<myQueue.DequeuFromRear()<<" ";
    cout<<myQueue.DequeuFromRear()<<" ";
    cout<<myQueue.DequeuFromRear()<<" ";
}