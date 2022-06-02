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
Node* insertAtStart(int value){
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
        first = curr;
        last->next = curr;
    }
}


int main(){
    insertAtStart(50);
    insertAtStart(40);
    insertAtStart(30);
    insertAtStart(20);
    insertAtStart(10);

    traverseNodes();
}