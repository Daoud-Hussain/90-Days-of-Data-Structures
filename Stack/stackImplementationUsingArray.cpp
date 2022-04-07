#include <iostream>
using namespace std;

struct stack{
    int top;
    int size;
    int *arr;



    //Argument - Constructor
    stack(){
    top = -1;
    size = 5;
    arr = new int[size];
    }

    void display(){
        int t =top;
        while(t != -1){
            cout<<arr[t]<<" ";
            t--;
        }
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
            cout<<"Stack OverFlow";
        }
        else{
            top++;
            arr[top] = value;
        }
    }

    void pop(){

        if(isEmpty()){
            cout<<"Stack UnderFlow";
        }
        else{
            int value = arr[top];
            top--;
            cout<<"Popped Value is: "<<value;
        }
        

    }



};


int main(){

    stack myStack;
    myStack.push(45);
    myStack.push(35);
    myStack.push(25);
    myStack.push(15);
    myStack.push(05);

    myStack.display(); 
    cout<<endl;
    myStack.pop();
    cout<<endl;
    myStack.display(); 

    myStack.pop();
    cout<<endl;
    myStack.display();

    myStack.pop();
    cout<<endl;
    myStack.display();



}