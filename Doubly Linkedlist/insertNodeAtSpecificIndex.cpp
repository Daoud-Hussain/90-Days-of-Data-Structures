#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};
Node *first;
Node *last;

// Creating a linkedlist using insertAtEnd
void insertAtEnd(int nodeData)
{
    Node *curr = new Node();

    // Checking empty condition
    if (first == NULL && last == NULL)
    {
        curr->data = nodeData;
        curr->prev = NULL;
        curr->next = NULL;
        first = curr;
        last = curr;
    }
    else
    {
        curr->data = nodeData;
        curr->next = NULL;
        curr->prev = last;
        last->next = curr;
        last = curr;
    }
}

void insertAtSpecificIndex(int nodeData, int index)
{
    int i = 1;
    Node *target = new Node();
    Node *temp = first;

    // Traversing till the last node
    while (temp != last)
    {
        if (i == index)
        {
            target->data = nodeData;
            target->next = temp;
            target->prev = temp->prev;
            temp->prev->next = target;
            temp->prev = target;
            break;
        }
        i++;
        temp = temp->next;
    }
}

// Travesing/Printing nodes of linkedlist
void traverseNodes()
{
    Node *givenFirstNode = first;
    while (givenFirstNode != NULL)
    {
        cout << givenFirstNode->data << " ";
        givenFirstNode = givenFirstNode->next;
    }
}

int main()
{
    // Creating a linkedlist using insertAtEnd()
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);
    cout << "Before" << endl;
    traverseNodes();
    cout << endl;
    insertAtSpecificIndex(35, 4);
    cout << "After" << endl;
    traverseNodes();
}