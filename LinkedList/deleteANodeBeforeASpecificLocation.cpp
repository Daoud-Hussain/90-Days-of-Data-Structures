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
 
//Deleting node from the start of linkedlist
void deleteBeforeASpecificLocation(int nodeData){
    Node* prev = new Node();
    Node* curr = new Node();
    Node* temp = first;

    while(temp->data != nodeData && prev->data != nodeData){
        prev->next = curr;
        curr->next = temp;
        temp = temp->next;
    }

    prev->next = temp;
    curr->next = NULL;
    delete curr;

}


int main(){

    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtEnd(60);
    insertAtEnd(70);

    cout<<"Before"<<endl;
    traverseNodes(first);

    deleteBeforeASpecificLocation(60);
    cout<<"\nAfter"<<endl;
    traverseNodes(first);


}