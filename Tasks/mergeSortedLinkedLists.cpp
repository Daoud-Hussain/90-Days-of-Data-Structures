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


Node *finalHead = NULL;
Node *finalTail = NULL;


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

void mergeLists(){
        if(headFirst == NULL)return;
        if(headSecond == NULL) return;

        if(headFirst->data < headSecond->data){
            finalHead = headFirst;
            headFirst = headFirst->next;
        }
        else{
            finalHead = headSecond;
            headSecond = headSecond->next;
        }
        finalTail = finalHead;
        while(headFirst && headSecond){
            if(headFirst->data < headSecond->data){
                finalTail->next = headFirst;
                headFirst = headFirst->next;
            }
            else{
                finalTail->next = headSecond;
                headSecond = headSecond->next;
            }
            finalTail = finalTail->next;
        }
        if(headFirst != NULL){
            finalTail->next = headFirst;
        }
        else{
            finalTail->next = headSecond;
        }
        headFirst = finalHead;
    }
int main(){

    insertInFirst(10);
    insertInFirst(35);
    insertInFirst(20);
    insertInFirst(40);
    insertInFirst(25);

    insertInSecond(15);
    insertInSecond(35);
    insertInSecond(30);
    insertInSecond(45);

    cout<<"First linkedlist: "<<endl;
    traverseNodes(headFirst);
    cout<<endl<<"Second linkedlist: "<<endl;
    traverseNodes(headSecond);
    cout<<endl<<"Final Linkedlist: "<<endl;
    mergeLists();
    traverseNodes(finalHead);

}