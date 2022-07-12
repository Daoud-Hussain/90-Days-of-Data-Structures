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
            cout << "Stack UnderFlow \n";
        }
        else
        {
            int value = arr[top];
            top--;
        }
    }


    void parenthesisMatched(string data)
    {
        bool flag = true;
        char temp ;
        for (int i = 0; i < data.length(); i++)
        {   
            temp = arr[top];
            if (isEmpty())
            {
                push(arr[i]);
                temp = arr[top];
            }
            else if ((temp=='('&& data[i]==')')  ||  (temp =='{' && data[i]=='}')  ||  (temp =='[' && data[i]==']'))
            {   
                pop();
                flag = false;
            }
            else{
                //Loop going on!!
                if((arr[i] == '(') || (arr[i] == '{') || (arr[i] == '[')){
                    push(arr[i]);
                }
            }
        }

        if (!flag)
        {
            cout << "Parenthesis are not balanced!!";
        }
        else{
            if(isEmpty()){
                cout << "Parenthesis are balanced!!";
            }
            else{
                cout << "Parenthesis are Not balanced!!";

            }
        }
    }
};

int main()
{
    stack *myStack = new stack();
    string expression = "{()}[]";
    myStack->parenthesisMatched(expression);
}