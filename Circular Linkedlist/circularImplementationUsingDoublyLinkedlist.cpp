#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};
Node* first;
Node* last;

void insertNode(int nodeData){
    Node* curr = new Node();

    //Checking empty condition
    if(first == NULL && last == NULL){
        curr->data = nodeData;
        curr->prev = NULL;
        curr->next = first;
        first = curr;
        last = curr;
    }
    else{
        curr->data = nodeData;
        curr->next = first;
        curr->prev = last;
        last->next = curr;
        last = curr;
    }

}

//Travesing/Printing nodes of linkedlist
void traverseNodes(){
    Node* temp = first;
    while(temp->next != first){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    if(temp->next == first){
        cout<<temp->data<<" ";

    }
}


int main(){
    insertNode(10);
    insertNode(20);
    insertNode(30);
    insertNode(40);
    insertNode(50);
    traverseNodes();
}