#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* first;
Node* last;

//Travesing/Printing nodes of linkedlist
void traverseNodes(Node* givenFirstNode){
    while(givenFirstNode != NULL){
        cout<<givenFirstNode->data<<" ";
        givenFirstNode = givenFirstNode->next;
    }
}

//Inserting a node at the end of linkedlist
Node* insertAtEnd(int value){
    if(first == NULL && last == NULL){
        Node* curr = new Node();
        curr->data = value;
        curr->next = NULL;
        last = curr;
        first = curr;
    }
    else{
        Node* curr = new Node();
        curr->data = value;
        curr->next = NULL;
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

    cout<<"Before"<<endl;
    traverseNodes(first);

    deleteANodeFromASpecificLocation(40);
    cout<<"\nAfter"<<endl;
    traverseNodes(first);


}