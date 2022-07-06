#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left = NULL;
    Node* right = NULL;
};
Node* root = NULL;

//Method to insert value at the left if the root's data is less than the tempRootey and vice versa
void insert(int key){
    // Node* temp = NULL;
    // Node* curr = NULL;
    // Node* tempRoot = NULL;

    // curr->data = key;
    // curr->left = NULL;
    // curr->right = NULL;
    
    // //Incase of only Node
    // if(root == NULL){
    //     root = curr;
    // }
    // else {
    //     temp = root;
    //     while (temp != NULL)
    //     {   
    //         tempRoot = temp;
    //         if(temp->data > key){
    //             temp = temp->left;
    //         }
    //         else if(temp->data < key){
    //             temp = temp->right;
    //         }
    //         else{
    //             //Loop going on!!!
    //         }
    //     }

    //     if(key > tempRoot->data){
    //         tempRoot->left = curr;
    //     }
    //     else{
    //         tempRoot->right = curr;
    //     }

    // }
    struct Node *tempNode = new Node();
    struct Node *current;
    struct Node *parent;

    tempNode->data = key;
    tempNode->left = NULL;
    tempNode->right = NULL;

    //if tree is empty
    if(root == NULL) {
        root = tempNode;
    } else {
        current = root;
        parent = NULL;

        while(current!=NULL) {                
            parent = current;
                
            //go to left of the tree
            if(key < parent->data) {
                current = current->left;                
                //insert to the left
                    
                if(current == NULL) {
                    parent->left = tempNode;
                    return;
                }
            }  //go to right of the tree
            else {
                current = current->right;
                
                //insert to the right
                if(current == NULL) {
                    parent->right = tempNode;
                    return;
                }
            }
        }            
    }  
}     


   
void inOrderTraversal(Node* p){
    if(p == NULL){
        return;
    }
    inOrderTraversal(p->left);
    cout<<p->data<<" ";
    inOrderTraversal(p->right);
    
}

int main(){
    Node* rootNode = new Node();
    insert(50);
    insert(60);
    insert(20);
    insert(30);
    insert(70);
    insert(35);

    inOrderTraversal(root);

}