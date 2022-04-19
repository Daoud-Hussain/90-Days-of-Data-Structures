#include <iostream>
using namespace std;

struct stack{
    int top;
    int size;
    int *arr;
    int *revArr;
    int revTop;


    stack(){
        top = -1;
        size = 10;
        arr = new int[size];
        revArr = new int[size];
        revTop = -1;
    }

    bool isFull(){
        if(top == size-1){
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }

    void push(int value){
        if(isFull()){
            cout<<value<<" cannot be pushed as stack is already full!";
        }
        else{
            top++;
            arr[top] = value;        
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack UnderFlow!!";
        }
        else{
            int value = arr[top];
            top--;
            revTop++;
            revArr[revTop] = value;
            
        }
    }

    void display(){
        int t = top;
        for(int i=t; i != -1; i--){
            cout<<arr[t]<<" ";
            t--;
        }

        cout<<endl;
        int rt = revTop;
        while(rt != -1){
            cout<<revArr[rt]<<" ";
            rt--;

        }


    }



};




int main(){
    stack myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);

    myStack.display();
    cout<<"\n";
    myStack.pop();
    myStack.pop();

    myStack.display();
}