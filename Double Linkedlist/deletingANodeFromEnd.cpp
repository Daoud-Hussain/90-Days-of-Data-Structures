#include<iostream>
using namespace std;


struct Node{
    int data;
    Node* prev;
    Node* next;
};
Node* first;
Node* last;

void insertAtEnd(int nodeData){
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
        curr->next = NULL;
        curr->prev = last;
        last->next = curr;
        last = curr;
    }

}

//Travesing/Printing nodes of linkedlist
void traverseNodes(){
    Node* givenFirstNode = first;
    while(givenFirstNode != NULL){
        cout<<givenFirstNode->data<<" ";
        givenFirstNode = givenFirstNode->next;
    }
}

void deleteANodeFromEnd(){
    Node* temp = first;
    Node* prev = new Node();
    
    while(temp != last){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    temp->prev = NULL;
    last = prev;
    delete temp;
}

int main()
{
    insertAtEnd(10);   
    insertAtEnd(20);   
    insertAtEnd(30);   
    insertAtEnd(40);   
    insertAtEnd(50); 


    cout<<"Before: "<<endl;
    traverseNodes();

    deleteANodeFromEnd();
    cout<<endl<<"After: "<<endl;
    traverseNodes();

}