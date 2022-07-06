#include<iostream>
using namespace std;

struct Tree{
    int data; 
    int height;
    Tree* left;
    Tree* right;
};

//Function to return height of a tree node
int height(Tree* node){
    if(node == NULL){
        return 0;
    }
    return node->height;
}

//Function to return balance factor (BF) of a tree node
int getBalanceFactor(Tree* node){
    if(node == NULL){
        return 0;
    }
    return height(node->left) - height(node->right);
}


// Function to traverse nodes using Pre-order
void inOrdertraversal(Tree *p)
{
    if (p == NULL)
    {
        return;
    }
    inOrdertraversal(p->left);
    cout << p->data << " ";
    inOrdertraversal(p->right);
}

Tree* createTreeNode(int data){
    Tree* curr = new Tree();
    curr->data = data;
    curr->height = 1;
    curr->left = NULL;
    curr->right = NULL;
}

int max(int a, int b){
    if(a > b)
        return a;
    return b;
}

//Function for RR-rotation
Tree* leftRotation(Tree* root){
    Tree* curr = root->right;
    Tree* temp = curr->left;

    if(root != NULL){
        curr->left = root;
        root->right = temp;
    }

    //After rotating a node we must update its height
    root->height = max(height(root->left) , height(root->right)) + 1;
    curr->height = max(height(curr->left) , height(curr->right)) + 1;
}

//Function for LL-rotation
Tree* rightRotation(Tree* root){
    Tree* curr = root->left;
    Tree* temp = curr->right;

    if(root != NULL){
        curr->right = root;
        root->left = temp;
    }

    //After rotating a node we must update its height
    root->height = max(height(root->left) , height(root->right)) + 1;
    curr->height = max(height(curr->left) , height(curr->right)) + 1;
    return curr;
}


Tree* insertNode(Tree* root, int value){
    if(root == NULL){
        return(createTreeNode(value));
    }
    else if(root->data > value){
        root->left = insertNode(root->left, value);
    }

    else if(root->data < value){
        root->right = insertNode(root->right, value);
    }
    else{
        cout<<"No duplicate node exists in BST"<<endl;
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));
 

    //Checking if the inserted node is unbalanced or not
    int balanceFactor = getBalanceFactor(root);

    //If the node is unbalanced,  we will have four cases
    //1. RR - rotation
    if(balanceFactor < -1 && value > root->right->data ){
        return leftRotation(root);
    }

    //2. LL - rotation
    if(balanceFactor > 1 && value < root->left->data ){
        return rightRotation(root);
    }

    //3. RL - rotation
    if(balanceFactor < -1 && value < root->right->data){
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    //4. LR - rotation
    if(balanceFactor > 1 && value > root->left->data){
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    return root;
}


int main()
{   
    Tree* root = NULL;
    root = insertNode(root, 10);
    
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);


    inOrdertraversal(root);
    
}