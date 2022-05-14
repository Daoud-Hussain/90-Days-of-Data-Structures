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
            cout << "Stack OverFLow" << endl;
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
            cout << "Stack UnderFLow" << endl;
        }
        else
        {
            int value = arr[top];
            top--;
        }
    }

    void display()
    {
        int t = top;
        while (!isEmpty())
        {
            cout << arr[t] << " ";
            t--;
        }
    }
};

int main()
{

    
}