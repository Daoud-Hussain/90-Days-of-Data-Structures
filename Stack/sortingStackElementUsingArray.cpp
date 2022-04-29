#include <iostream>
using namespace std;

struct Stack
{
    int top;
    int size;
    int *arr;

    Stack(int s){
       int top = -1;
        int size = s;
        int *arr = new int[size]; 
    }

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

void sortingStackUsingArray(Stack current, int myArray[]){
    int i = 0;
    int max = 0;
    //Pushing all the elements of stack in the array
    while(!current.isEmpty()){
        myArray[i] = current.pop();
    }

    while(!current.isFull()){
        //Finding the maximum element of the array
        for(int i = 0; i < 10; i++){
            if(myArray[i] > max){
                max = myArray[i];
            }
        }
        current.push(max);
    }
}

int main(){
    Stack currentStack(10);
    int myArray[10];
}