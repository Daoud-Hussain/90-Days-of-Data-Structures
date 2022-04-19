#include <iostream>
#include <cmath>
using namespace std;

struct stack
{
    int top;
    int size;
    char *arr;

    stack(int s)
    {
        top = -1;
        size = s;
        arr = new char[size];
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

    void push(char value)
    {
        if (isFull())
        {
            cout << "Stack OverFlow";
        }
        else
        {
            top++;
            arr[top] = value;
        }
    }

    char pop()
    {

        if (isEmpty())
        {
            cout << "Stack UnderFlow";
        }
        else
        {
            char value = arr[top];
            top--;
            return value;
        }
    }

    int evaluatePostfixExpression(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] > '0' && str[i] < '9')
            {
                // We are subtracting 0 to convert string character to integer
                push(str[i] - '0');
            }
            else
            {
                int op2 = pop();
                int op1 = pop();

                switch (str[i])
                {
                    case '+':
                    {
                        push(op1 + op2);
                        break;
                    }
                    case '-':
                    {
                        push(op1 - op2);
                        break;
                    }
                    case '*':
                    {
                        push(op1 * op2);
                        break;
                    }
                    case '/':
                    {
                        push(op1 / op2);
                        break;
                    }
                    case '^':{
                        push(pow(op1, op2));
                        break;
                    }
                }
            }
        }
        return arr[top];

    }
};

int main()
{
    stack myStack(10);
    cout<<myStack.evaluatePostfixExpression("46+2/5*7+");
}
