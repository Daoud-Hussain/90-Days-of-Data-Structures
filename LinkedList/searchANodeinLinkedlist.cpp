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

//Searching a node of linkedlist
void searchANode(int givenData){
    Node *temp = new Node();
    temp = first;

    //Traversing until we get the last node
    int index = 1;
    while(temp != NULL){
        if(temp->data == givenData){
            cout<<temp->data <<" is found in the list which is "<<index <<" node.";
        }
            index++;
        temp = temp->next;
    }
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

    cout<<endl;
    searchANode(30);


}