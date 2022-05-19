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
    Node* curr = new Node();
    curr->data = value;
    curr->next = NULL;
    last->next = curr;
    last = curr;
}
 


int main(){
    Node* firstNode = new Node();
    firstNode->data = 10;
    firstNode->next = NULL;
    first = firstNode;


    Node* secondNode = new Node();
    secondNode->data = 20;
    secondNode->next = NULL;
    firstNode->next = secondNode;

    Node* thirdNode = new Node();
    thirdNode->data = 30;
    thirdNode->next = NULL;
    secondNode->next = thirdNode;

    Node* fourthNode = new Node();
    fourthNode->data = 40;
    thirdNode->next = fourthNode;
    fourthNode->next = NULL;
    last = fourthNode;

    cout<<"Before: "<<endl;
    traverseNodes(first);
    cout<<endl;

    insertAtEnd(50);
    insertAtEnd(60);
    cout<<"After: "<<endl;
    traverseNodes(first);

}