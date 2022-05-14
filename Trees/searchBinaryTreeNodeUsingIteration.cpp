#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;
};
Node *root = NULL;

//Method to search a specific node in the Binary Tree
bool searchNode(Node *rootNode, int key)
{
    Node *curr = new Node();
    curr->data = key;
    Node *p = rootNode;

    bool flag = false;
    while (p != NULL)
    {
        if (curr->data > p->data)
        {
            p = p->right;
        }
        else if (curr->data < p->data)
        {
            p = p->left;
        }
        else
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << "Node " << p->data << " is found in the binary tree!!";
        return true;
    }
    else{
        return false;

    }
}


//Method to create a Node in the tree
Node *createTreeNode(int value)
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


void inOrderTraversal(Node* t){
    if(t == NULL){
        return;
    }
    inOrderTraversal(t->left);
    cout<<t->data<<" ";
    inOrderTraversal(t->right);
}
int main()
{   
    //Creating nodes in the binary tree
    Node* parent = createTreeNode(60);
    parent->left = createTreeNode(50);
    parent->right = createTreeNode(70);
    parent->left->left = createTreeNode(45);
    parent->left->right = createTreeNode(55);
    parent->right->left = createTreeNode(65);
    parent->right->right = createTreeNode(75);


    searchNode(parent,65);
    cout<<endl;
    inOrderTraversal(parent);

}