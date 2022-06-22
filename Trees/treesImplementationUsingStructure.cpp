#include<iostream>
using namespace std;

struct Tree{
    int data;
    Tree* left ;
    Tree* right;
};
Tree* root;

Tree* insertNode(int data){
    Tree* t = new Tree();
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    return t;
}

void preOrderTraversal(Tree* t){
    if(t == NULL){
        return;
    }
    cout<<t->data<<" ";
    preOrderTraversal(t->left);
    preOrderTraversal(t->right);

}

int main()
{
    Tree* t1 = insertNode(10);
    t1->left = insertNode(20);
    t1->right = insertNode(30);
    t1->left->left = insertNode(40);
    t1->right->left = insertNode(50);

    preOrderTraversal(t1);
}