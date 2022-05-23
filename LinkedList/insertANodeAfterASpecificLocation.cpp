#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

};
Node* first;
Node* last;

void traverse(Node* givenNode){
    while(givenNode != NULL){
        cout<<givenNode->data<<" ";
        givenNode = givenNode->next;
    }
}

// insert after a specific location
Node* insert(int givendata, int givenlocation){
    Node* temp = first;
    Node * curr= new Node();

    while(temp->data!= givenlocation){
        temp = temp->next;
    }
    curr->data = givendata;
    curr->next = temp->next;
    temp->next = curr;
}

int main(){
    Node* firstNode = new Node();
    firstNode->data = 100;
    firstNode->next = NULL;
    first = firstNode;

    Node* secondNode = new  Node();
    secondNode->data = 200;
    secondNode->next = NULL;
    firstNode->next = secondNode;

    Node* thirdNode = new Node();
    thirdNode->data = 300;
    thirdNode->next = NULL;
    secondNode->next = thirdNode;

    Node* fourthNode = new Node();
    fourthNode->data = 500;
    fourthNode->next = NULL;
    thirdNode->next = fourthNode;
    last = fourthNode;

    cout<<"Before"<<endl;

    traverse(first);

    cout<<"\nAfter"<<endl;
    insert(400,300);
    traverse(first);

}