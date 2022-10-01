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
 
void deleteNthNodeFromLast(int n){
    int count = 1;
    Node* end = last;
    Node* prev = NULL;
    while(end != first){
        Node* curr = first;
        while(curr != end){
            prev = curr;
            curr = curr->next;
        }
        end = prev;
        //Deleting the nth node from last
        if(count == n){
            Node* temp = end->next;
            end->next = temp->next;
            delete temp;
        }
        count++;
    }
}

int main(){
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtEnd(60);

    cout<<"Before: "<<endl;
    traverseNodes(first);
    cout<<endl<<"After: "<<endl;
    deleteNthNodeFromLast(3);
    traverseNodes(first);

}