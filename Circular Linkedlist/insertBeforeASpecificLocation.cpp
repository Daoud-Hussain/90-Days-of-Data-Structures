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
void insertBeforeASpecificLocation(int value, int location){
    Node* temp = first;
    Node* prev;
    while(temp->next != first){
        if(temp->data == location){
            Node* curr = new Node();
            curr->data = value;
            curr->next = temp;
            prev->next = curr;
        }
        prev = temp;
        temp = temp->next;
    }
    
}


int main(){
    // Creating a linkedlist using insertAtNode()
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(40);
    insertAtEnd(50);

    cout<<"Before: "<<endl;
    traverseNodes();

    //Insert A node before 40 with data 30 
    insertBeforeASpecificLocation(30, 40);
    cout<<endl<<"After: "<<endl;
    traverseNodes();

}