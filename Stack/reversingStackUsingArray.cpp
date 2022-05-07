/*
Problem Statement:
Reverse a Given stack using an additional array.
You can't use anyother stack to implement.
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

void reverseStackUsingArray(Stack myStack, int tempArray[])
{
    int count = 0;

    // Popping elements from the stack until the stack gets empty
    // and storing the elements in the array.
    while (!myStack.isEmpty())
    {
        int popped = myStack.pop();
        tempArray[count] = popped;
        count++;
    }

    // Storing the array elements back in the stack.
    int i = 0;
    while (!myStack.isFull())
    {
        myStack.push(tempArray[i]);
        i++;
    }
}

int main()
{
    // Making a stack manually and pushing values
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70);
    stack.push(80);
    stack.push(90);
    stack.push(100);
    cout << "Stack before reversing is: " << endl;
    stack.display();
    cout << endl;
    cout << endl;

    // Reversing the stack
    int myArray[10];
    reverseStackUsingArray(stack, myArray);
    cout << "Stack after reversing is: " << endl;
    stack.display();
}