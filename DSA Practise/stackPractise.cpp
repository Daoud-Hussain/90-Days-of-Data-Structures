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
    Stack myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    myStack.push(60);
    myStack.push(70);
    myStack.push(80);
    myStack.push(90);
    myStack.push(100);

    cout << "BEfore reversing: " << endl;
    myStack.display();
    cout << endl;

    // myStack.pop();
    // myStack.pop();
    // myStack.pop();
    // myStack.display();

    int myArray[10];
    // cout << "After reversing: " << endl;
    reverseStackUsingArray(myStack, myArray);
    myStack.display();
    // for (int i = 10; i != 0; i--)
    // {
    //     cout << myArray[i] << " ";
    // }
}