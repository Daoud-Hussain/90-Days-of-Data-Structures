#include <iostream>
using namespace std;

struct Queue{
    int size = 10;
    int front = -1;
    int rear = -1;
    int *arr = new int[size];


    // bool isFull(){
    //     if((front == 0) && (rear = size -1)){
    //         return true;
    //     }
    //     return false;
    // }

    // bool isEmpty(){
    //     if((front == -1) && (rear = -1)){
    //         return true;
    //     }
    //     return false;
    // }

    void enqueue(int value){
        if((front == -1) && (rear = -1)){
            front++;
            rear++;
            arr[rear] = value;
        }
        else{
            rear++;
            arr[rear] = value;
        }

    }

    int dequeue(){
        if((front == -1) && (rear == -1)){
            cout<<"Queue is Empty"<<endl;
        }
        else{
            int dequeueValue = arr[front];
            front++;
            return dequeueValue;
        }
    }


};




int main(){
    Queue myQueue;
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(40);
    myQueue.enqueue(50);
    myQueue.enqueue(60);
    myQueue.enqueue(69);


    cout<<myQueue.dequeue()<<" ";
    cout<<myQueue.dequeue()<<" ";
    cout<<myQueue.dequeue()<<" ";
}