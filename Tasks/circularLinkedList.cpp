#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* first;
Node* last;

Node* firstEven;
Node* lastEven;

Node* firstOdd;
Node* lastOdd;

//Travesing/Printing nodes of linkedlist
void traverseNodes(Node* givenNode){
    Node* temp = givenNode;
    while(temp->next != givenNode){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    if(temp->next == givenNode){
        cout<<temp->data<<" ";
    }
}

//Inserting a node at the start of linkedlist
Node* insertInFinal(int value){
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

Node* insertAtEven(int value){
    if(firstEven == NULL && lastEven == NULL){
        Node* curr = new Node();
        curr->data = value;
        curr->next = NULL;
        firstEven = curr;
        lastEven = curr;
    }
    else{
        Node* curr = new Node();
        curr->data = value;
        curr->next = firstEven;
        lastEven->next = curr;
        lastEven = curr;
    }
}

Node* insertAtOdd(int value){
    if(firstOdd == NULL && lastOdd == NULL){
        Node* curr = new Node();
        curr->data = value;
        curr->next = NULL;
        firstOdd = curr;
        lastOdd = curr;
    }
    else{
        Node* curr = new Node();
        curr->data = value;
        curr->next = firstOdd;
        lastOdd->next = curr;
        lastOdd = curr;
    }
}

void deleteNode(Node* givenHead, Node* givenPrev){
    // if(givenHead == first){ }
    givenPrev->next = givenHead->next;
    givenHead->next = NULL;
    delete givenHead;
}

void createNewLinkedlistFromEvenOdd(){
    int EvenMin = 1000, OddMin = 1000;
    
    Node* curr1 = firstEven;
    Node* curr2 = firstOdd;
    while(curr1->next != firstEven && curr2->next != firstOdd){
        Node* prev1 = lastEven;
        Node* prev2 = lastOdd;
        Node* temp1 = firstEven;
        Node* temp2 = firstOdd;

        Node* deletedNode1;
        Node* deletedPrev1;
        Node* deletedNode2;
        Node* deletedPrev2;

        while(temp1->next != firstEven && temp2->next != firstOdd){
            
            if(EvenMin > temp1->data){
                EvenMin = temp1->data;
                deletedPrev1 = prev1;
                deletedNode1 = temp1;
            }
            if(OddMin > temp2->data){
                OddMin = temp2->data;
                deletedPrev2 = prev2;
                deletedNode2 = temp2;

            }
            prev1 = temp1;
            temp1 = temp1->next;
            prev2 = temp2;
            temp2 = temp2->next;

        }
        //Inserting minimum values to the new linkedlist
        insertInFinal(EvenMin);
        insertInFinal(OddMin);    

        //Deleting minimum value nodes - that has been inserted in new linkedlist
        deleteNode(deletedNode1, deletedPrev1);
        deleteNode(deletedNode2, deletedPrev2);

        //Moving to the next node in the linkedlist
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
}

int main(){
    insertAtOdd(35);
    insertAtOdd(15);
    insertAtOdd(25);
    insertAtOdd(45);


    insertAtEven(40);
    insertAtEven(10);
    insertAtEven(20);
    insertAtEven(50);


    traverseNodes(firstEven);
    cout<<endl;
    traverseNodes(firstOdd);
    
    createNewLinkedlistFromEvenOdd();
    cout<<endl;
    traverseNodes(first);
}