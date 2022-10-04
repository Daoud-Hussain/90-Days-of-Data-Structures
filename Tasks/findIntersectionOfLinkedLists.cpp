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
        tailFirst = curr;
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
        tailSecond = curr;

    }
}

void findIntersection(){
    Node *temp1 = headFirst;
    Node *temp2 = headSecond;
    while(temp1 != NULL){
        while(temp2 != NULL){
            if(temp1->data == temp2->data){
                cout<<temp1->data<<" ";
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
        temp2 = headSecond;
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


    traverseNodes(headFirst);
    cout<<endl;
    traverseNodes(headSecond);
    cout<<endl<<"Intersected nodes: "<<endl;
    findIntersection();

}