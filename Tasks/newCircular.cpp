#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct cir{
    int data;
    cir* next;
};

cir* tail = NULL;
cir* tail2 = NULL;

void insert(int val)
{
    cir* n = new cir();
    n->data = val;
    n->next = NULL;

    if (tail == NULL)
    {
        n->next = n;
        tail = n;
    }
    else{
        n->next = tail->next;
        tail->next = n;
        tail = n;
    }
}

void insertVal2(int val)
{
    cir* n = new cir();
    n->data = val;
    n->next = NULL;

    if (!tail2)
    {
        n->next = n;
        tail2 = n;
    }
    else{
        n->next = tail2->next;
        tail2->next = n;
        tail2 = n;
    }
}

void display(cir* x)
{
    cir* p = new cir();
    p = x->next;
    do
    {
        cout<<p->data<<' ';
        p = p->next;
    } while (p != x->next);
}

void sort(cir* x)
{
    cir* p = x->next;
    cir* q = new cir();
    do{
        q = p->next;
        while(q != x->next)
        {
            if (q->data > p->data)
            {
                int temp = q->data;
                q->data = p->data;
                p->data = temp;
            }
            q = q->next;
            //cout<<"a";
        }
        p = p->next;
        //cout<<"s";
        // cout<<p->data<<endl;
        // cout<<x->next->data<<endl;
    }while (p != x->next);
}

cir* merge(){

    sort(tail2);
    sort(tail);
    cir* p = new cir();
    cir* q = new cir();
    cir* c = new cir();
    cir* d = new cir();
    p = tail->next;
    q = tail2->next;
    while (q != tail2)
    {
        c = p->next;
        p->next = q;
        d = q->next;
        q->next = c;
        p = c;
        q = d;
    }
    q->next = p->next;
    p->next = q;
    return q;
}

int main(int argc, char const *argv[])
{

    insert(12);
    insert(28);
    insert(18);
    insert(25);
    insert(19);

    insertVal2(5);
    insertVal2(24);
    insertVal2(12);
    insertVal2(6);
    insertVal2(15);

    cir* z = merge();
    display(z);



    return 0;
}