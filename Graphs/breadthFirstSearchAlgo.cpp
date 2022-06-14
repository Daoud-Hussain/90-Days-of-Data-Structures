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




};

int main()
{   

    Queue myQueue;
    int node;
    int i = 0;
    int visited[7] = {0,0,0,0,0,0,0};

    //Representing graph with adjacency matrix
    int graphArray[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };
    cout<<i<<" ";   
    visited[i] = 1;
    myQueue.enQueue(i);

    while(!myQueue.isEmpty()){
        node = myQueue.deQueue();
        for(int j = 0; j < 7; j++){
            if(graphArray[node][j] == 1 && visited[j] == 0){
                cout<<j<<" ";   
                visited[j] = 1;
                myQueue.enQueue(j);

            }
        }

    } 




}