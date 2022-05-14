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
    // if(curr == root){
    //     curr->left = NULL;
    //     curr->right = NULL;        
    //     curr->data = value;
    //     root = curr;

    // }
    // else{
        curr->left = NULL;
        curr->right = NULL;        
        curr->data = value;
    //}
}

void insertTreeNode(Tree* givenRoot, int value){
    Tree* prev = NULL;
    while(givenRoot!= NULL){
        prev = root;
        if(value == givenRoot->data){
            return;
        }
        else if(value < givenRoot->data){
            givenRoot = givenRoot->left;
        }
        else {
            givenRoot = givenRoot->right;
        }
    }

    Tree* newNode = createTreeNode(value );
    if(prev->data < value){
        prev->left = newNode;
    }
    else{
        prev->right = newNode;
    }

}

void inOrderTraversal(Tree* t){
    if(t == NULL){
        return;
    }
    inOrderTraversal(t->left);
    cout<<t->data<<" ";
    inOrderTraversal(t->right);
}

int main(){

        //     60
        //   /     \
        //   50    70
        //   / \   / \
        // 45  55  65 75

    Tree* parent = createTreeNode(60);
    parent->left = createTreeNode(50);
    parent->right = createTreeNode(70);
    parent->left->left = createTreeNode(45);
    parent->left->right = createTreeNode(55);
    parent->right->left = createTreeNode(65);
    parent->right->right = createTreeNode(75);


    insertTreeNode(parent, 20);
    cout<<parent->left->left->data<< " ";
    //inOrderTraversal(parent);
}