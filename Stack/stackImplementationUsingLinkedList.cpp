#include <iostream>
using namespace std;

struct stack
{
    int data;
    stack *next;
};

bool isFull()
{
    stack *curr = new stack();
    if (curr == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty(stack ptr, int top)
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

// Method to push a value
struct stack *push(struct stack *top, int val)
{
    if (isFull())
    {
        cout << val << " cannot be pushed as stack is already full";
    }
    else
    {
        struct stack *ptr = new stack();
        ptr->data = val;
        ptr->next = top;
        top = ptr;
        return top;
    }
}

// Method to display Values
void printNodes(stack *top)
{

    while (top != NULL)
    {
        cout << "Element is: " << top->data << " ";
        top = top->next;
    }
}

int main()
{
    stack *top = NULL;
    push(top, 12);
    push(top, 24);
    printNodes(top);
}