/*
Problem Statement:
Reverse a Given stack without using an additional array.
You can use anyother stack to implement.
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

void reverseStackUsingStack(Stack s1, Stack s2)
{

    // Popping elements from the stack until the stack gets empty
    // and storing the elements in the other stack one by one.
    while (!s1.isEmpty())
    {
        int popped = s1.pop();
        s2.push(popped);
    }

    // Storing the array elements back in the original stack.
    while (!s1.isFull())
    {
        int popped = s2.pop();
        s1.push(popped);
    }
}