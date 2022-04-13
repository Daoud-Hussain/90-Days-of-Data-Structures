#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;
};
Node* root = NULL;


// Method to create a Node in the tree
Node *createNode(int value)
{
    Node *curr = new Node();
    // In case of no root
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


//Method to print values of BST nodes using Post-Order
void postOrderTraversal(Node* p){
    if(p == NULL){
        return;
    }
    postOrderTraversal(p->left);
    postOrderTraversal(p->right);
    cout<<p->data<<" ";
    
}

int main()
{
    // Creating nodes in the binary tree
    Node *n1 = createNode(10);
    n1->left = createNode(20);
    n1->right = createNode(30);
    n1->left->left = createNode(40);
    n1->right->left = createNode(50);
    
    postOrderTraversal(n1);
}