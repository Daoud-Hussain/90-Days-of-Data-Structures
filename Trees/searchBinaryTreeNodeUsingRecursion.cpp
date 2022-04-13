#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;
};
Node* root = NULL;

//Method to search a specific node in the Binary Tree
bool searchNode(Node* p, int key){
    if(p == NULL){
        return p;
    }
    if(p->data == key){
        cout<<"Node "<<p->data<<" is found!!";
        return true;
    }
    if(key > p->data){
        searchNode(p->right, 30);
    }
    else{
        searchNode(p->left, 30);
    }
} 


//Method to create a Node in the tree
Node* createNode(int value)
{
    Node *curr = new Node();
    //In case of no root
    if (curr == root)
    {
        curr->data = value;
        curr->left = NULL;
        curr->right = NULL;
        curr = root;
    }
    else
    {
        curr->data = value;
        curr->left = NULL;
        curr->right = NULL;
    }
}

//Method to print values of BST nodes
Node* printNodes(Node* p){
    if( p!=NULL){
        return p;
    }
    printNodes(p->left);
    cout<<p->data<<" ";
    printNodes(p->right);
}


int main()
{   
    //Creating nodes in the binary tree
    Node *n1 = createNode(10);
    Node *n2 = createNode(20);
    Node *n3 = createNode(30);
    Node *n4 = createNode(40);
    Node *n5 = createNode(50);

    //Linking nodes of binary tree
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    printNodes(n1);
}