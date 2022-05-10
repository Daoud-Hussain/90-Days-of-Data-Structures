/*
Problem Statement:
Reverse a Given stack without using an additional array.
You can use additional stacks to implement.
*/

#include <iostream>
using namespace std;

struct Stack
{
    int top = -1;
    int size = 10;
    int *arr = new int[size];

    bool isFull()
    {
        if (top == size - 1)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack UnderFLow!!" << endl;
        }
        else
        {
            top++;
            arr[top] = value;
        }
    }

    int pop()
    {

        if (isEmpty())
        {
            cout << "Stack UnderFlow";
            return -1;
        }
        else
        {
            int value = arr[top];
            top--;
            return value;
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
};

void reverseStackUsingStack(Stack s1, Stack s2, Stack s3)
{

    // Popping elements from the stack until the stack gets empty
    // and storing the elements in the other stack one by one.
    while (!s1.isEmpty())
    {   
        int popped = s1.pop();
        s2.push(popped);
    }

    // Pushing all the stack elements in the third stack.
    while (!s2.isEmpty())
    {
        int popped1 = s2.pop();
        s3.push(popped1);
    }

    //Pushing all the stack elements in the original stack with reversed elements.
    while(!s3.isEmpty()){
        int popped2 = s3.pop();
        s1.push(popped2);
    }

}

int main()
{
    // Making a stack manually and pushing values
    Stack stack1;
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);
    stack1.push(40);
    stack1.push(50);
    stack1.push(60);
    stack1.push(70);
    stack1.push(80);
    stack1.push(90);
    stack1.push(100);
    
    cout << "Stack before reversing is: " << endl;
    stack1.display();
    cout << endl;
    cout << endl;

    // Declaring another empty stack
    Stack stack2;
    Stack stack3;

    reverseStackUsingStack(stack1, stack2, stack3);
    cout << "Stack after reversing is: " << endl;
    stack1.display();


}