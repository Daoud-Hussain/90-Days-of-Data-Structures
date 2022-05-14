#include <iostream>
using namespace std;

struct Queue{
    int size = 10;
    int front = -1;
    int rear = -1;
    int *arr = new int[size];


    bool isFull(){
        if((front == 0) && (rear = size -1) || (rear = front - 1)){
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if((front == -1) && (rear = -1)){
            return true;
        }
        return false;
    }

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

void sortQueueByArray(Queue tempQueue, int tempArray[]){
    int count = 0;
    while(tempQueue.front != -1 && tempQueue.rear != - 1){
        int dequeuedValue =  tempQueue.arr[tempQueue.front];
        tempQueue.front++;
        tempArray[count] = dequeuedValue;
        count++;
    }

    while(!tempQueue.isFull()){
        int max = 0;
        int indexOfMaxNumber = 0;
        for(int i = 0; i < 10; i++){
            if(max < tempArray[i]){
                max = tempArray[i];
                indexOfMaxNumber = i;
            }
        }
        tempQueue.enqueue(max);
        tempArray[indexOfMaxNumber] = 0;
    }



}


int main(){
    Queue myQueue;
    myQueue.enqueue(10);
    myQueue.enqueue(40);
    myQueue.enqueue(30);
    myQueue.enqueue(50);
    myQueue.enqueue(80);
    myQueue.enqueue(60);
    myQueue.enqueue(20);

    int myArray[10];
    sortQueueByArray(myQueue ,myArray);

}