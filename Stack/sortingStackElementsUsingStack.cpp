/*
Problem Statement:
Sort the Stack in such a way that the minimum element in the stack will be on top and maximum on bottom.
You can't use Array for this rather you can use another stack to implement.
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
            cout << arr[t] << " " ;
            t--;
        }
    }
};

void sortStackUsingStack(Stack s1, Stack s2, Stack s3){
    int max = 0;
    int popped = 0;
    while(!s1.isEmpty()){
        popped = s1.pop();
        if(popped > max){
            max = popped;
        }
        s2.pop();
        s2.push(popped);
    }
    s3.push(max);
    while(!s2.isEmpty()){
        popped = s1.pop();
        if(popped > max){
            max = popped;
        }
        s2.push(popped);
    }
    
}

int main(){

}