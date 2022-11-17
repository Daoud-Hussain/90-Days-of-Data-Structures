#include <iostream>
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

//Remove mth value node with nth occurance
void removeNth(int m, int n){
    Node* temp = first;
    int count = 0;
    while(temp->next != NULL){
        //Finding the mth value node
        if(temp->data == m){
            count++;
            //finding the nth occurance
            if(count == n){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp; 
            }
        }
        temp = temp->next;

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


int main(){
    insertAtEnd(10);
    insertAtEnd(12);
    insertAtEnd(20);
    insertAtEnd(28);
    insertAtEnd(12);
    insertAtEnd(40);
    cout << "Before" << endl;
    traverseNodes();
    cout << endl;
    removeNth(12, 2);
    cout << "After" << endl;
    traverseNodes();
}