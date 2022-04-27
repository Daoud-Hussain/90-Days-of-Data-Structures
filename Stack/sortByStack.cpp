/*
Problem Statement:
Sort the array in such a way that the minimum element in the stack will be on top. You can't use Array for this
rather you can use another stack to implement
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

    void pop()
    {

        if (isEmpty())
        {
            cout << "Stack UnderFlow";
        }
        else
        {
            int value = arr[top];
            top--;
            cout << "Popped Value is: " << value;
        }
    }
    void display()
    {
        int t = top;
        while (t != -1)
        {
            cout << arr[t] << " " << endl;
            t--;
        }
    }
};

void sortByStack()
{
}

int main()
{
    Stack myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);

    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
}