#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* first;
Node* last;

//Travesing/Printing nodes of linkedlist
void traverseNodes(){
    Node* temp = first;
    while(temp->next != first){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    if(temp->next == first){
        cout<<temp->data<<" ";

    }
}

//Inserting a node at the start of linkedlist
Node* insertAtEnd(int value){
    if(first == NULL && last == NULL){
        Node* curr = new Node();
        curr->data = value;
        curr->next = NULL;
        first = curr;
        last = curr;
    }
    else{
        Node* curr = new Node();
        curr->data = value;
        curr->next = first;
        last->next = curr;
        last = curr;
    }
}

/* Function to sort the list */

 

int main(){
    insertAtEnd(20);
    insertAtEnd(80);
    insertAtEnd(50);
    insertAtEnd(10);
    insertAtEnd(40);
    insertAtEnd(30);
    insertAtEnd(60);
    insertAtEnd(70);

    traverseNodes();
    // sortTheLinkedlist(first);
    traverseNodes();
}