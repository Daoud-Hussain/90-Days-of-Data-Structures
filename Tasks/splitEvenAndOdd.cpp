#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* first;
Node* last;

Node* firstEven;
Node* lastEven;

Node* firstOdd;
Node* lastOdd;
//Travesing/Printing nodes of linkedlist
void traverseNodes(Node* givenFirstNode){
    while(givenFirstNode != NULL){
        cout<<givenFirstNode->data<<" ";
        givenFirstNode = givenFirstNode->next;
    }
}


//Inserting a node at the end of even linkedlist
Node* insertAtEnd(int value){
    if(last == NULL){   
        Node* curr = new Node();
        curr->data = value;
        curr->next = NULL;
        first = curr;
        last = curr;
    }else{
        Node* curr = new Node();
        curr->data = value;
        curr->next = NULL;
        last->next = curr;
        last = curr;
    }

}

//Inserting a node at the end of odd linkedlist
Node* insertInEven(int value){
    if(lastEven == NULL){   
        Node* curr = new Node();
        curr->data = value;
        curr->next = NULL;
        firstEven = curr;
        lastEven = curr;
    }else{
        Node* curr = new Node();
        curr->data = value;
        curr->next = NULL;
        lastEven->next = curr;
        lastEven = curr;
    }

}


Node* insertInOdd(int value){
    if(lastOdd == NULL){   
        Node* curr = new Node();
        curr->data = value;
        curr->next = NULL;
        firstOdd = curr;
        lastOdd = curr;
    }else{
        Node* curr = new Node();
        curr->data = value;
        curr->next = NULL;
        lastOdd->next = curr;
        lastOdd = curr;
    }

}


void splitEvenAndOdd(){
    Node* curr = first;
    while(curr != NULL){
        if(curr->data % 2 == 0){
            // cout<<"Even"<<" ";
            insertInEven(curr->data);
        }
        else{
            insertInOdd(curr->data);
            // cout<<"Odd"<<" ";

        }
        curr = curr->next;
    }

}

int main(){

    insertAtEnd(10);
    insertAtEnd(15);
    insertAtEnd(20);
    insertAtEnd(25);
    insertAtEnd(30);
    insertAtEnd(35);
    insertAtEnd(40);
    insertAtEnd(45);


    cout<<"Before: "<<endl;
    traverseNodes(first);
    splitEvenAndOdd();
    cout<<endl<<"After: "<<endl;
    traverseNodes(firstEven);
    cout<<endl;
    traverseNodes(firstOdd);
}