#include <iostream>
using namespace std;

struct Tree {
    Tree* left;
    Tree* right;
    int data;
};
Tree* root; 


Tree* createTreeNode(int value){
    Tree* curr = new Tree();
    if(curr == root){
        curr->left = NULL;
        curr->right = NULL;        
        curr->data = value;
        root = curr;

    }
    else{
        curr->left = NULL;
        curr->right = NULL;        
        curr->data = value;
    }
}


//InOrder Traversal using Recursion
void preOrderTraversal(Tree* t){
    if(t == NULL){
        return;
    }
    cout<<t->data<<" ";
    preOrderTraversal(t->left);
    preOrderTraversal(t->right);
}

int main(){
    Tree* parent = createTreeNode(20);
    parent->left = createTreeNode(30);
    parent->right = createTreeNode(40);
    parent->left->left = createTreeNode(70);
    parent->left->right = createTreeNode(50);
    parent->right->left = createTreeNode(10);
    parent->right->right = createTreeNode(50);

    preOrderTraversal(parent);

}