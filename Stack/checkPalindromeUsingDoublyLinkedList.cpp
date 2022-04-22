#include <iostream>
using namespace std;

struct stack{
    char data;
    stack* prev;
    stack* next;
};
stack* top = NULL;


bool isFull(){
    struct stack* curr;
    if(curr == NULL){
        return true;
    }
    return false;
}


bool isEmpty(){
    if(top == NULL){
        return true;
    }
    return false;
}

void push(stack* temp, char value){
    if(isFull()){
        cout<<value<<" cannot be pushed as stack is already full";
    }
   
    else{
        temp->data = value;
        temp->next = top;
        top->prev = temp;
        temp->prev = NULL;
        top = temp;
    }
}

 
void display(){
    stack *temp = top;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

bool isPalindrome(struct stack *left)
{
    if (left == NULL)
       return true;
 
    // Moving to the rightmost node
    struct stack *right = left;
    while (right->next != NULL){
        right = right->next;
    }

    while (left != right)
    {
        if (left->data != right->data){
            return false;
        }
        left = left->next;
        right = right->prev;
    }

    return true;
    
}
int main(){
    push(top, 'L');
    push(top, 'E');
    push(top, 'V');
    push(top, 'E');
    push(top, 'L');

    display();
    if(isPalindrome(top)){
        cout<<"Yes a Palindrome";
    }
    else{
        cout<<"No not a Palindrome";
    }
}