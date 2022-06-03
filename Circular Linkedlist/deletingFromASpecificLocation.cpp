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

//Deleting node from the a specific location of linkedlist
void deleteANodeFromASpecificLocation(int givenNode){
    Node* temp = first;
    Node* prev = new Node();
    
    while(temp->data != givenNode){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    temp->next = NULL;
    delete temp;
}   


int main(){
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);


    cout<<"Before deleting: "<<endl;
    traverseNodes();

    deleteANodeFromASpecificLocation(30);
    cout<<endl<<"After deleting: "<<endl;
    traverseNodes();
}