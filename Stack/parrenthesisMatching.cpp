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
        for (int i = 0; i < data.length(); i++)
        {
            if (data[i] == '(')
            {
                push('(');
            }
            else if (data[i] == ')')
            {   
                //Checking if the stack is empty or not
                if (!isEmpty())
                {   
                    //If Empty then pop the ')'
                    pop();
                }
                else
                {   
                    //If not empty then end the program as it found ')' without any '('
                    flag = false;
                    break;
                }
            }
            else{
                //Loop going on!!
            }
        }

        if (flag)
        {
            cout << "Parenthesis are  matching!!";
        }
        else
        {
            cout << "Parenthesis are not matching!!";
        }
    }

};

int main()
{
    stack *myStack = new stack();
    string expression = "3*23*(1*(5-1))-2";
    myStack->parenthesisMatched(expression);
   
}