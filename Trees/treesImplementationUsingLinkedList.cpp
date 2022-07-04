#include <iostream>
using namespace std;

struct trees
{
    int data;
    trees *left = NULL;
    trees *right = NULL;
};
struct trees *root = NULL;
 
// Method to create a node
trees *createNode(int value)
{
    trees *curr = new trees();
    curr->data = value;
    curr->left = NULL;
    curr->right = NULL;

    return curr;
}

//Method to print nodes of trees 
void printNodes(trees* ptr){
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->left;
    }
}
int main()
{
    struct trees *p = createNode(20);
    struct trees *p1 = createNode(10);
    struct trees *p2 = createNode(30);

    root = p;
    //Linking the node with root
    p->left = p1;
    p->right = p2;
}