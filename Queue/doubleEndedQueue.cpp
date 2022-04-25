#include <iostream>
using namespace std;

struct Queue{
    int front = -1;
    int rear = -1;
    int size = 10;
    int *arr = new int[size];


    //Method to check whether the queue is full or not
    bool isFull(){
        if(( (front == 0) && (rear = size-1))&&(front = rear+1)){
            return true;
        }
        return false;

    }

    //Method to check whether the queue is empty or not
    bool isEmpty(){
        if(rear = -1){
            return true;
        }
        return false; 
    }


    //Method to add an element from the rear
    



};
int main(){

}