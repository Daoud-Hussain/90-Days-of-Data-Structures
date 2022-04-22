#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
}; 
Node* root = NULL;


//Method to create a new node at the start
Node* createNode(int value){
    Node* curr = new Node();
    if(curr == root){
        curr->data = value;
        curr->left = NULL;
        curr->right = NULL;
        root = curr;
    }
    else{
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


//Method to delete a node in BST
void deleteBSTNode(int key){
    Node* child = root;
    Node* parent;
    

    while(child != NULL && child->data != key){

        parent = child;
        if(key > child->data){
            child = child->right;
        }
        else{
            child = child->left;
        }

        if(child == NULL){
            cout<<"No record Found!!";
        }
        else{
            if(parent->right != NULL || parent->left != NULL){
                if(parent->left != NULL ){
                    if(child->right == NULL){
                        parent->left = child->left;
                        delete child;
                    }
                    else{
                        parent->left = child->right;
                        delete child;

                    }
                }
            }
            else{
                if(parent->right != NULL){
                    if(child->right != NULL){
                        parent->right = child->left;
                        delete child;

                    }
                    else{
                        parent->right = child->right;
                        delete child;

                    }
                }
            }
        }
        
    }

}

int main(){
    //            20
    //         /     \
    //        10       30
    //       /  \     /  \
    //      5    15  25   40
    //     /     /   \    /
    //    4     13  22    35

    Node* p1 = createNode(20);
    p1->left = createNode(10);
    p1->right = createNode(30);
    p1->left->left = createNode(5);
    p1->left->left->left = createNode(4);
    p1->left->right = createNode(15);
    p1->left->right->left = createNode(13);
    p1->right->left = createNode(25);
    p1->right->left->left = createNode(22);
    p1->right->right = createNode(40);
    p1->right->right->left = createNode(35);

    inOrderTraversal(p1);

    deleteBSTNode(30);
}