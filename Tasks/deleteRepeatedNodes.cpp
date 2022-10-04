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
 
void deleteRepeatedNodes(){
    Node* temp = first;
    Node* prev = new Node();
    while(temp != NULL){
        prev = temp;
        temp = temp->next;
        Node* deleted = new Node();

        if(prev->data == temp->data){
            deleted = temp;
            prev->next = deleted->next;
            deleted->next = NULL;
            temp = temp->next;
            delete deleted;
        }
    }
}

int main(){
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtEnd(60);

    cout<<"Before: "<<endl;
    traverseNodes(first);
    cout<<endl<<"After: "<<endl;
    deleteRepeatedNodes();
    traverseNodes(first);

}