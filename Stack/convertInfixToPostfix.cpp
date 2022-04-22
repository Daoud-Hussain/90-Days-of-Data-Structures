#include <iostream>
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

    void push(int value)
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

    
    int precedence(char op)
    {
        if (op == '^')
        {
            return 3;
        }
        else if (op == '*' || op == '/')
        {
            return 2;
        }
        else if (op == '+' || op == '-')
        {
            return 1;
        }
        else{
            return -1;
        }
    }


    string infixToPostfix(string str){

        string result= "";
        for(int i=0; i< str.length(); i++){
            if((str[i] >= 'a' && str[i] <= 'z') ||(str[i] >= 'A' && str[i] <= 'Z') ){
                result += str[i];
            }
            else if(str[i] == '('){
                push('(');
            }
            else if(str[i] == ')'){
                while(!isEmpty() && arr[top] != '('){
                    result += arr[top];
                    //popping every elements from the stack until we get '('
                    pop();
                }
                //popping '(' from the stack after finding
                pop();
            }
            else{
                while(!isEmpty() && precedence(arr[top]) > precedence(str[i])){
                    result += arr[top];
                    pop();
                }
                push(str[i]);
            }
        }

        while(!isEmpty()){
            result += arr[top];
            pop();
        }
        return result;
    }
};




int main()
{   
    stack myStack(20);
    cout<< myStack.infixToPostfix("(a-b/c)*(a/k-l)");
    
    
}