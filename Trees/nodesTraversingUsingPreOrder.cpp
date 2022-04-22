#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;
};
Node *root = NULL;


// Method to create nodes in BST
Node *createNode(int value)
{
    Node *curr = new Node();
    if (curr == root)
    {
        curr->data = value;
        curr->left = NULL;
        curr->right = NULL;
        root = curr;
    }
    else
    {
        curr->data = value;
        curr->left = NULL;
        curr->right = NULL;
    }
}

// Method to traverse nodes using Pre-order
void traverseNodes(Node *p)
{
    if (p == NULL)
    {
        return;
    }
    cout << p->data << " ";
    traverseNodes(p->left);
    traverseNodes(p->right);
}

int main()
{   
    //         10
    //       /    \
    //      20     30
    //     /  \     \
    //    40   50    60

    Node *n1 = createNode(10);
    n1->left = createNode(20);
    n1->right = createNode(30);
    n1->left->left = createNode(40);
    n1->left->right = createNode(50);
    n1->right->right = createNode(60);
    

    traverseNodes(n1);
}