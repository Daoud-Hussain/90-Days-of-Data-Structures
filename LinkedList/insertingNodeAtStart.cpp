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

//Inserting a node at the start of linkedlist
Node* insertAtStart(int value){
    Node* temp = new Node();
    temp->data = value;
    temp->next = first;
    first = temp;
    return temp;
}


int main(){
    Node* firstNode = new Node();
    firstNode->data = 20;
    firstNode->next = NULL;
    first = firstNode;


    Node* secondNode = new Node();
    secondNode->data = 30;
    secondNode->next = NULL;
    firstNode->next = secondNode;

    Node* thirdNode = new Node();
    thirdNode->data = 40;
    thirdNode->next = NULL;
    secondNode->next = thirdNode;

    Node* fourthNode = new Node();
    fourthNode->data = 50;
    thirdNode->next = fourthNode;
    fourthNode->next = NULL;
    last = fourthNode;

    cout<<"Before: "<<endl;
    traverseNodes(first);
    cout<<endl;

    insertAtStart(10);
    cout<<"After: "<<endl;
    traverseNodes(first);

}