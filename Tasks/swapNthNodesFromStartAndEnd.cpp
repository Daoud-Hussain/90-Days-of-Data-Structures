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
 
void swapNthNodesFromStartAndEnd(int n){
    int countFromStart = 1;
    int countFromEnd = 1;
    Node* swappedStart = NULL;
    Node* prevSwappedStart = NULL;
    Node* swappedEnd = NULL;
    Node* prevSwappedEnd = NULL;
    Node* end = last;
    Node* prev = NULL;
    while(end != first){
        Node* curr = first;
        while(curr != end){
            //Finding nth node from start
            if(end == last && countFromStart == n){
                prevSwappedStart = prev;
                swappedStart = curr;
            }
            prev = curr;
            curr = curr->next;
            countFromStart++;
        }
        end = prev;
        //Finding nth node from end
        if(countFromEnd == n){
                prevSwappedEnd = prev;
                swappedEnd = curr;
            }
        countFromEnd++;
    }


    //Swapping two nodes
    prevSwappedStart->next = swappedEnd;
    Node* tempStart = swappedStart->next;
    Node* tempEnd = swappedEnd->next;
    swappedStart->next = swappedEnd->next;
    swappedEnd->next = tempStart;
    swappedStart->next = tempEnd;
    tempStart->next = swappedStart;
    
}

int main(){
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);

    cout<<"Before: "<<endl;
    traverseNodes(first);
    cout<<endl<<"After: "<<endl;
    swapNthNodesFromStartAndEnd(2);
    traverseNodes(first);

}