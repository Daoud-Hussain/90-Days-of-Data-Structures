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
            cout << arr[t] << " " << endl;
            t--;
        }
    }
};

void sortByStack(Stack s1, Stack s2){
    int min = 2147483647;
    int poppedValue = 0;


    //Popping all values from initial stack (s1)
    //and pushing into the final stack (s2) and finding minimum number
    while (!s1.isEmpty()){
        poppedValue = s1.pop();
        if(poppedValue < min){
            min = poppedValue;
        }
        s2.push(poppedValue);
    }

    while(!s2.isEmpty()){
        poppedValue = s2.pop();
        if(poppedValue == min){
            continue;
        }
        else{
            s1.push(poppedValue);
        }
    }

    //Pushing the smallest value to the top
    s1.push(min);
   
}

int main()
{
    Stack stack1;
    Stack stack2;
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);
    stack1.push(40);
    stack1.push(50);
}