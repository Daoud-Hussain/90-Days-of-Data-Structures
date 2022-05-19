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


//Method to add a node before a specific node
void insertNodeBeforeLocation(int givenData, int locationData){
    Node* temp = first;
    Node* curr = new Node();
    Node* prev = new Node();

    //Traversing until we get the specific/desired node
    while(temp->data != locationData){
        prev = temp;
        temp = temp->next;
    }

    //Linking the desired node in the linkedlist
    curr->data = givenData;
    curr->next = prev->next;
    prev->next = curr;

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


    traverseNodes(first);
    cout<<endl;
    insertNodeBeforeLocation(30, 40);
    traverseNodes(first);


}