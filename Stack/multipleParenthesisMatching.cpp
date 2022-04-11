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

    void multipleParenthesisMatching(string exp)
    {
        int flag = true;
        for (int i = 0; i < exp.length(); i++)
        {
            if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[')
            {
                push(arr[i]);
            }
            else if (arr[i] == ')' || arr[i] == '}' || arr[i] == ']')
            {
                if (!isEmpty())
                {
                    pop();
                }
                else
                {
                    cout<<"Mn yahaan hoon, Ap kidar hoo";
                    flag = false;
                    break;
                }
            }
        }

        if (isEmpty())
        {
            if (!flag)
            {
                cout << "Parenthesis are not balanced!!";
            }
            cout << "Parenthesis are balanced!!";
        }
        else
        {
            cout << "Parenthesis are not balanced!!";
        }
    }
};

int main()
{
    stack *myStack = new stack();
    string expression = "3[2*{4+(40/8}]";
    myStack->multipleParenthesisMatching(expression);
}