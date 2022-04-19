#include <iostream>
using namespace std;

struct stack{
    char data;
    stack* next = NULL;

};
stack* top = NULL;
// Method to check whether the stack is full or not
    bool isFull(){
        stack* curr = new stack();
        if(curr == NULL){
            return true;
        }
        return false;
    }


// Method to check whether the stack is empty or not
    bool isEmpty(){
        if(top == NULL){
            return true;
        }
        return false;
    }
    
// Method to push a value in the stack
    void push(char p)
    {   
        stack* newStack = new stack();
        if (isFull())
        {
            cout << " Stack OverFlow" << endl;
        }
        else
        {
            newStack->data = p;
            newStack->next = top;
            top = newStack;
        }
    }

// Method to pop a value from the stack
    void pop(){
        if(isEmpty()){
            cout<<"Stack UnderFlow!!";
        }
        else{
            top = top->next;
            
        }
    }

// Method to display values of the stack
    void display(){
        stack* temp;
        if(isEmpty()){
            cout<<"Stack is empty";
        }
        else{
            temp = top;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
        

    }


  
int main(){
    
    display();
    
}