#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* first;
Node* last;

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

//Inserting a node at the start of linkedlist
Node* insertAtEnd(int value){
    if(first == NULL && last == NULL){
        Node* curr = new Node();
        curr->data = value;
        curr->next = NULL;
        first = curr;
        last = curr;
    }
    else{
        Node* curr = new Node();
        curr->data = value;
        curr->next = first;
        last->next = curr;
        last = curr;
    }
}

//Function to insert a node before a given location
void insertAfterASpecificLocation(int value, int location){
    Node* temp = first;
    while(temp->next != first){
        if(temp->data == location){
            Node* curr = new Node();
            curr->data = value;
            curr->next = temp->next;
            temp->next = curr;
        }
        temp = temp->next;
    }
    
}


int main(){
    // Creating a linkedlist using insertAtNode()
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(50);

    cout<<"Before: "<<endl;
    traverseNodes();

    //Insert A node after 30 with data 40 
    insertAfterASpecificLocation(40, 30);
    cout<<endl<<"After: "<<endl;
    traverseNodes();

}