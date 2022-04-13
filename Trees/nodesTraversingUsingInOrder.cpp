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

//Method to print values of BST nodes using InOrder
void inOrderTraversal(Node* p){
    if( p == NULL){
        return;
    }
    inOrderTraversal(p->left);
    cout<<p->data<<" ";
    inOrderTraversal(p->right);

}



int main()
{
    //         10
    //       /    \
    //      20     30
    //     /  \     \
    //    40   50    60


   // Creating nodes in the binary tree
    Node *n1 = createNode(10);
    n1->left = createNode(20);
    n1->right = createNode(30);
    n1->left->left = createNode(40);
    n1->left->right = createNode(50);
    n1->right->right = createNode(60);
    
    inOrderTraversal(n1);
}
