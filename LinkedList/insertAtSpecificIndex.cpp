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

//Method to insert a node at a specific index (given by user)
void insertAtSpecificLocation(int givenData, int givenIndex){
    Node* temp = first;
    Node* curr = new Node();
    int index = 0;
    
    while(index != givenIndex - 1){
        temp = temp->next;
        index++;
    }
        curr->data = givenData;
        curr->next = temp->next;
        temp->next = curr;

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
    thirdNode->data = 40;
    thirdNode->next = NULL;
    secondNode->next = thirdNode;

    Node* fourthNode = new Node();
    fourthNode->data = 50;
    thirdNode->next = fourthNode;
    fourthNode->next = NULL;
    last = fourthNode;


    Node* fifthNode = new Node();
    fifthNode->data = 60;
    fourthNode->next = fifthNode;
    fourthNode->next = NULL;
    last = fifthNode;

    traverseNodes(first);
    cout<<endl;
    insertAtSpecificLocation(30, 2);
    traverseNodes(first);



}