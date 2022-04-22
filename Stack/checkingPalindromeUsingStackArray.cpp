#include <iostream>
using namespace std;

struct stack{
    int top;
    int size;
    char *arr;


    stack(){
        top = -1;
        size = 10;
        arr = new char[size];
    }

// Method to check whether the stack is full or not
    bool isFull(){
        if(top == size-1){
            return true;
        }
        return false;
    }


// Method to check whether the stack is empty or not
    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }
    
// Method to push a value in the stack
    void push(char exp)
    {
        if (isFull())
        {
            cout << " Stack OverFlow" << endl;
        }
        else
        {
            arr[++top] = exp;
        }
    }

// Method to pop a value from the stack
    char pop(){
        if(isEmpty()){
            cout<<"Stack UnderFlow!!";
        }
        else{
            int value = arr[top];
            top--;
            return value;
            
        }
    }

// Method to display values of the stack
    void display(){
        int t = top;
        for(int i=t; i != -1; i--){
            cout<<arr[t];
            t--;
        }

    }

// Method to check whether the string the string is palindrome or not
    void checkPalindrome(string exp){
        int i = 0;
        while(i != exp.length()){
            push(exp[i]);
            i++;
        }
        int count = 0;
        int t = 0;
        string popped = "";

        while(!isEmpty()){
            popped += pop();
        }

        for(int i=0; i<popped.length(); i++){
            if(arr[i] != popped[i]){
                count++;
            }

        }
        if(count != 0){
            cout<<"Not a Palindrome!!";
        }
        else{
            cout<<"A Palindrome!!";
        }
    }
    

};




int main(){
    stack myStack;
    string expression = "noon";
    myStack.checkPalindrome(expression);

    
}