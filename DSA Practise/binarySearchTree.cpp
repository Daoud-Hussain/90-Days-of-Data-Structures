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

Tree* insertTreeNode(int value){
    Tree* curr = new Tree();
    if(value < root->data){
        root->left = createTreeNode(value);
    }
    else{
        root->right = createTreeNode(value);

    }
    return curr;
}

int main(){
    Tree *parent = createTreeNode(60);
    insertTreeNode(70);
    insertTreeNode(50);
    insertTreeNode(40);
    insertTreeNode(66);
}