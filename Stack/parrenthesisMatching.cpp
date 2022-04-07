#include <iostream>
using namespace std;

struct stack
{
    int top;
    int size;
    char *arr;

    stack()
    {
        top = -1;
        size = 10;
        arr = new char[size];
    }

    bool isFull()
    {
        if (top == size - 1)
        {
            return true;
        }
        return false;
    }

    // Method to check whether the stack is empty or not
    bool isEmpty()
    {
        if (top == -1)
        {
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

    void display()
    {
        int t = top;
        while (t != -1)
        {
            cout << arr[t] << " ";
            t--;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Value cannot be popped as stack is already empty!!";
        }
        else
        {
            int value = arr[top];
            top--;
        }
    }

    void parenthesisMatched(string data)
    {
        for (int i = 0; i < data.length(); i++)
        {
            if (data[i] == '(')
            {   
                push('(');
            }
            if(data[i] == ')'){
                pop();
            }
        }
    }


    bool parenthesisIsMatching(){
        if(isEmpty()){
            return true;
        }
        return false;
    }
};

int main()
{   
    stack *myStack = new stack();
    string expression = "3*23*)1*(5-1)-2)";
    myStack->parenthesisMatched(expression);
    // for(int i = 0; i<myStack->size; i++){
    //     if(myStack->arr[i] == NULL){
    //         return 
    //     }
    //     else{
    //         cout<<"Parenthesis is not matching";
    //     }
    // }

    if(myStack->parenthesisIsMatching()){
        cout<<"Yes";
    }
    else{
        cout<<"NO";
    }
    
}