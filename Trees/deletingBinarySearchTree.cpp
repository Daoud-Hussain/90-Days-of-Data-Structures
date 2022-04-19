#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
}; 
Node* root = NULL;


//Method to create a new node at the start
Node* createNode(int value){
    Node* curr = new Node();
    if(curr == root){
        curr->data = value;
        curr->left = NULL;
        curr->right = NULL;
        root = curr;
    }
    else{
        curr->data = value;
        curr->left = NULL;
        curr->right = NULL;
    }
}

//Method to print values of BST nodes using InOrder
void inOrderTraversal(Node* p){
    if( p == NULL){
        return;
    }
    inOrderTraversal(p->left);
    cout<<p->data<<" ";
    inOrderTraversal(p->right);

}


//Method to delete a node in BST
void deleteBSTNode(int key){
    
}

int main(){
    Node* p1 = createNode(20);
    p1->left = createNode(10);
    p1->right = createNode(30);
    p1->left->left = createNode(5);
    p1->right->left = createNode(7);

    inOrderTraversal(p1);
}