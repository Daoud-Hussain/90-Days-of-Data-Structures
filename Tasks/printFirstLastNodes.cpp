#include <iostream>
using namespace std;

struct stu
{
    int data;
    stu *next = NULL;
};
stu *first = NULL;
stu *last = NULL;
void insertAtEnd(int data)
{
    stu *curr = new stu();
    if (first == NULL && last == NULL)
    {
        curr->data = data;
        curr->next = NULL;
        first = curr;
        last = curr;
    }
    else if (first == last)
    {
        first->next = curr;
        curr->data = data;
        curr->next = NULL;
        last = curr;
    }
    else
    {
        curr->data = data;
        curr->next = NULL;
        last->next = curr;
        last = curr;
    }
}

void printNodes(stu *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

stu *reverseNodes(stu *p)
{
    if (p == NULL || p->next == NULL)
    {
        return p;
    }
    stu *newFirst = reverseNodes(p->next);
    p->next->next = p;
    p->next = NULL;
    return newFirst;
}

void printFirstLastNodes(stu *q)
{
    stu *p = first;
    while (q != NULL)
    { 
        cout << p->data << " " << q->data<<" ";
        q = q->next;
        p = p->next;
    }
}


struct stu *findMid()
{
    struct stu *p = first;
    struct stu *q = first;
    if (first != NULL)
    {
        while (q && q->next)
        {
            q = q->next->next;
            p = p->next;
        }
    }
    return p;
}


int main()
{
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtEnd(60);
    printNodes(first);
    cout << "\n";
    stu* mid = findMid();   
    stu *tempPtr = reverseNodes(mid);
    // printNodes(tempPtr);
    // cout<<endl;
    printFirstLastNodes(tempPtr);
}