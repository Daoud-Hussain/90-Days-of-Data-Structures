#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left = NULL;
    Node* right = NULL;
};
Node* root = NULL;

//Method to insert value at the left if the root's data is less than the key and vice versa
void insert(int key){
    struct Node* p = new Node();
    struct Node* curr = new Node();
    curr->data = key;
    
    //Incase of only node
    if(root == NULL){
        curr = root;
    }
    else {
        Node* k = new Node();
        while (p != NULL)
        {   
            if(p->data > curr->data){
                p = p->left;
                k = p;
            }
            else{
                p = p->right;
                k = p;
            }
        }
        if(curr->data > k->data){
            k->left = curr;
        }
        else{
            k->right = curr;
        }
    }

    

}

int main(){

}