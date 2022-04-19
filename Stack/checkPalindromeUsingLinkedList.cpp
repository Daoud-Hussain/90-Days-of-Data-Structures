#include <iostream>
using namespace std;

struct stack
{
    char data;
    stack *next = NULL;
};
stack *top = NULL;
// Method to check whether the stack is full or not
bool isFull()
{
    stack *curr = new stack();
    if (curr == NULL)
    {
        return true;
    }
    return false;
}

// Method to check whether the stack is empty or not
bool isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    return false;
}

// Method to push a value in the stack
void push(char p)
{
    stack *newStack = new stack();
    if (isFull())
    {
        cout << " Stack OverFlow" << endl;
    }
    else
    {
        newStack->data = p;
        newStack->next = top;
        top = newStack;
    }
}

// Method to pop a value from the stack
char pop()
{
    if (isEmpty())
    {
        cout << "Stack UnderFlow!!";
    }
    else
    {
        char poppedValue = top->data;
        top = top->next;
        return poppedValue;

    }
}

// Method to display values of the stack
void display()
{
    stack *temp;
    if (isEmpty())
    {
        cout << "Stack is empty";
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

// Method to check whether the string the string is palindrome or not
void checkPalindrome(string exp)
{   
    string popped = "";
    for (int i = 0; i < exp.length(); i++)
    {
        popped += pop();
    }

    int count = 0;
    for (int i = 0; i < exp.length(); i++)
    {
        if(popped[i] != exp[i]){
            count++;
        }
    }

    //Checking whether string is palindrome or not
    if(count != 0){
        cout<<exp<<" is not a palimdrome";
    }
    else{
        cout<<exp<<" is a palimdrome";

    }

}

int main()
{
    string myString = "noon";
    for (int i = 0; i < myString.length(); i++)
    {
        push(myString[i]);
    }
   checkPalindrome(myString);
}