#include <iostream>
using namespace std;

struct Queue{
    int front;
    int rear;
    int size;
    string *arr;

    Queue(){
        size = 10;
        front = -1;
        rear = -1;
        arr = new string[size];

    }


    bool isFull(){
        if((front = 0) && (rear = size-1)){
            return true;
        }
        return false;
    }




    bool isEmpty(){
        if(rear == -1){
            return true;
        }
        return false;
    }


    void EnqueuFromFront(string data){
        if(isFull()){
            cout<<"Queue OverFlow";
        }
        else if(isEmpty()){
            front = rear = 0;
            arr[front] = data;
        }
        else{
            front++;
            arr[front] = data;
        }
    }


    void EnqueuFromRear(string data){
        if(isFull()){
            cout<<"Queue OverFlow";
        }
        else if(isEmpty()){
            front = rear = 0;
            arr[front] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
    }


    string DequeueFromFront(){
        if(isEmpty()){
            cout<<"No Element to dequeue"<<endl;
        }
        else{
            string value = arr[front];
            front++;
        }
    }


    string DequeueFromRear(){
        if(isEmpty()){
            cout<<"No Element to dequeue"<<endl;
        }
        else{
            string value = arr[rear];
            rear++;
        }
    }

};

int main(){


}