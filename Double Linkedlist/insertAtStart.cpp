#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};
Node* first;
Node* last;

void insertAtStart(int nodeData){
    Node* curr = new Node();

    //Checking empty condition
    if(first == NULL && last == NULL){
        curr->data = nodeData;
        curr->prev = NULL;
        curr->next = NULL;
        first = curr;
        last = curr;
    }
    else{
        curr->data = nodeData;
        curr->next = first;
        curr->prev = NULL;
        first->prev = curr;
        first = curr;
    }

}

//Travesing/Printing nodes of linkedlist
void traverseNodes(Node* givenFirstNode){
    while(givenFirstNode != NULL){
        cout<<givenFirstNode->data<<" ";
        givenFirstNode = givenFirstNode->next;
    }
}


int main(){
    insertAtStart(50);
    insertAtStart(40);
    insertAtStart(30);
    insertAtStart(20);
    insertAtStart(10);
    traverseNodes(first);
}