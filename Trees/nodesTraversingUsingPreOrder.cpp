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
    Node *rootNode = createNode(10);
    rootNode->left = createNode(20);
    rootNode->left->left = createNode(30);
    rootNode->left->right = createNode(40);
    rootNode->right = createNode(50);
    rootNode->right->right = createNode(60);
    rootNode->right->left = createNode(70);

    traverseNodes(rootNode);
}