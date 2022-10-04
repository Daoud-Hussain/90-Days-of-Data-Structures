#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* headFirst = NULL;
Node* tailFirst = NULL;

Node* headSecond = NULL;
Node* tailSecond = NULL;

//Travesing/Printing nodes of linkedlist
void traverseNodes(Node* givenFirstNode){
    while(givenFirstNode != NULL){
        cout<<givenFirstNode->data<<" ";
        givenFirstNode = givenFirstNode->next;
    }
}

void insertInFirst(int value){
    if(tailFirst == NULL){   
        Node* curr = new Node();
        curr->data = value;
        curr->next = NULL;
        headFirst = curr;
        tailFirst = curr;
    }else{
        Node* curr = new Node();
        curr->data = value;
        curr->next = NULL;
        tailFirst->next = curr;
    }
}

void insertInSecond(int value){
    if(tailSecond == NULL){   
        Node* curr = new Node();
        curr->data = value;
        curr->next = NULL;
        headSecond = curr;
        tailSecond = curr;
    }else{
        Node* curr = new Node();
        curr->data = value;
        curr->next = NULL;
        tailSecond->next = curr;
    }
}


int main(){

    insertInFirst(10);
    insertInFirst(20);
    insertInFirst(25);
    insertInFirst(35);
    insertInFirst(40);

    insertInSecond(15);
    insertInSecond(25);
    insertInSecond(30);
    insertInSecond(35);
    insertInSecond(45);



//     cout<<"Before: "<<endl;
//     traverseNodes(first);
//     splitEvenAndOdd();
//     cout<<endl<<"After: "<<endl;
//     traverseNodes(firstEven);
//     cout<<endl;
//     traverseNodes(firstOdd);
// }
    traverseNodes(headFirst);
    cout<<endl;
    traverseNodes(headSecond);
}