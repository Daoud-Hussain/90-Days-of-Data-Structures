#include <iostream>
using namespace std;

struct stu
{
    int data;
    stu *next = NULL;
};

struct stu *first = new stu();
struct stu *last = new stu();

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

void swapNumbers(int val1, int val2)
{   
    stu* p = first;
    int temp;
    while (p != NULL)
    {
        if(p->data == val1){
            temp = p->data;
            p->data = val2;
            val2 = temp;
        }
        cout<<p->data<<" ";
        p = p->next;
    }
}

//Swap Program
void swapNumbers(int val1, int val2){
    stu* p = first;
    stu* q = first;
    while(p!=NULL){
        if(p->data==val1){
            
        }

        p = p->next;
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
    stu *node1 = new stu();
    node1->data = 20;
    node1->next = NULL;
    first = node1;

    stu *node2 = new stu();
    node2->data = 30;
    node2->next = NULL;
    node1->next = node2;

    stu *node3 = new stu();
    node3->data = 40;
    node3->next = NULL;
    node2->next = node3;

    stu *node4 = new stu();
    node4->data = 50;
    node4->next = NULL;
    node3->next = node4;

    stu *node5 = new stu();
    node5->data = 60;
    node5->next = NULL;
    node4->next = node5;

    printNodes(first);
    // stu* kk = findMid();

    // stu *revFirst = reverseNodes(first);
    // cout << endl;
    // printNodes(revFirst);
    // cout << endl;

    cout<<endl;
    swapNumbers(30, 50);
    //printNodes(first);
}