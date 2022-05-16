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


//Counting leaf Nodes using Recursion
void countLeafNodes(Node* givenRoot){
    int count = 0;
    if(givenRoot->left == NULL && givenRoot->right == NULL){
        count++;
        return;
    }
    //Moving to the left most node until we get a leaf
    countLeafNodes(givenRoot->left);
    countLeafNodes(givenRoot->right);
    
    cout<<endl;
    cout<<"Count is: "<< count;
}


int main()
{
    //         50
    //       /    \
    //      20     60
    //     /  \     \
    //    10   15    70



    // Creating nodes in the binary tree
    Node *n1 = createNode(50);
    n1->left = createNode(20);
    n1->right = createNode(60);
    n1->left->left = createNode(10);
    n1->left->right = createNode(15);
    n1->right->right = createNode(70);
    
    postOrderTraversal(n1);
    countLeafNodes(n1);
}