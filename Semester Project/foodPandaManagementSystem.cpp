#include<iostream>
using namespace std;

/*
    It is a simple management system made using arrays that
    performs CRUD operations using C++ procedural programming.
*/
//Structure to add,update,check,delete orders
struct Orders{
    string orderName;
    string customerName;
    string mobileNo;
    int price;
    int id;
    Orders* next;
};
Orders* first = NULL;
Orders* last = NULL;


// --------------------------------------------------------------------------------------------------
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
void preOrdertraversal(Tree *p)
{
    if (p == NULL)
    {
        return;
    }
    cout << p->data << " ";
    preOrdertraversal(p->left);
    preOrdertraversal(p->right);
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


// -------------------------------------------------------------------------------------------

//Function to purchase a new product
void orderProducts(){
    string product = "";
    int option,price;
    bool flag = true;
    string name = "";
    string phone = "";
    cout<<endl;

    cout<<"*********** Purchase a Project ***********"<<endl;
    cout<<"Enter the customer name: "<<" ";
    cin>>name;
    cout<<"Enter the mobile number: "<<" ";
    cin>>phone;
    cout<<endl<<endl;

    cout<<"************Available products************"<<endl;
    cout<<"1. Chicken-Burger:                    200"<<endl;
    cout<<"2. Andy-wala Burger:                  150"<<endl;
    cout<<"3. Small-Sized-Pizza:                 400"<<endl;
    cout<<"4. Large-Sized-Pizza:                 750"<<endl;
    cout<<"5. Fries:                             100"<<endl;
    cout<<"6. One-Liter-Coke:                    120"<<endl;
    cout<<"7. Shuwarma:                          150"<<endl;
    cout<<"******************************************"<<endl<<endl;


    cout<<"Enter your choice: ";
    cin>>option;

    
    switch (option)
    {
        case 1:
        {   
            price = 200;
            product = "Chicken-Burger";
            break;
        }
        case 2:
        {
            price = 150;
            product = "Andy-wala-Burger";
            break;
        }
        case 3:
        {
            price = 400;
            product = "Small-Sized-Pizza";
            break;
        }
        case 4:
        {
            price = 750;
            product = "Large-Sized-Pizza";
            break;
        }
        case 5:
        {
            price = 100;
            product = "Fries";
            break;
        }
        case 6:
        {
            price = 120;
            product = "One-Liter-Coke";
            break;
        }
        case 7:
        {
            price = 150;
            product = "Shuwarma";
            break;
        }

        default:
        {
            cout<<"Invalid input!!"<<endl;
            break;
            flag = false;
        }
    }


    //calcualating order id
    int orderId = 1;
    
    Orders* node = first;
    while(node != NULL){
        orderId++;
        node = node->next;
    }
   
    if(first == NULL && last == NULL){
        //Incase of no order
        Orders* order = new Orders();
        order->orderName = product;
        order->price = price;
        order->customerName = name;
        order->mobileNo = phone;
        order->id= orderId;
        first = order;
        last = order;
        order->next = NULL;
    }
    else{
        Orders* order = new Orders();
        order->orderName = product;
        order->price = price;
        order->customerName = name;
        order->mobileNo = phone;
        last->next = order;
        order->id = orderId;
        last = order;
        order->next = NULL;
    }


    if(flag){
        cout<<product<<" is purchased Successfully"<<endl;
    }
    else{
        cout<<"Couldn't purchased the product Successfully"<<endl;
    }
    cout<<endl;


}


void checkOrders(){
    Orders* temp = first;
    while(temp != NULL){
        cout<<"\n";
        cout<<"----------Your Orders---------------"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"Order Number:            "<<temp->id<<endl;
        cout<<"Customer Name:           "<<temp->customerName<<endl;
        cout<<"Order Name:              "<<temp->orderName<<endl;
        cout<<"Price:                   "<<temp->price<<endl;
        cout<<"Mobile Number:           "<<temp->mobileNo<<endl;
        temp = temp->next;
    }
}



void checkBills(){
    string name = "";
    string phone = "";
    int total = 0;
    cout<<endl;

    cout<<"*********** Check your bill ***********"<<endl;
    cout<<"Enter the customer name: "<<" ";
    cin>>name;
    cout<<"Enter the mobile number: "<<" ";
    cin>>phone;

    Orders* temp = first;
    bool done = false;
    while(temp != NULL){
        if(temp->customerName == name && temp->mobileNo == phone){
            cout<<"\n";
            total += temp->price;
            cout<<"----------Your Orders---------------"<<endl;
            cout<<"-----------------------------------"<<endl;
            cout<<"Order Number:            "<<temp->id<<endl;
            cout<<"Customer Name:           "<<temp->customerName<<endl;
            cout<<"Order Name:              "<<temp->orderName<<endl;
            cout<<"Price:                   "<<temp->price<<endl;
            cout<<"Mobile Number:           "<<temp->mobileNo<<endl;
            done = true;
        }
        temp = temp->next;
    }
    if(done)
        cout<<"Total:                   "<<total<<endl;
    else{
        cout<<"No such record exists!!!"<<endl;
    }
}


void updateOrders(){
    string name = "";
    string phone = "";
    int option, price;
    string product = "";
    bool done = false;
    cout<<endl;

    cout<<"*********** Check your bill ***********"<<endl;
    cout<<"Enter the customer name: "<<" ";
    cin>>name;
    cout<<"Enter the mobile number: "<<" ";
    cin>>phone;

    Orders* temp = first;
    int orderNo = 1;
    while(temp != NULL){
        if(temp->customerName == name && temp->mobileNo == phone){
            cout<<"\n";
            cout<<"*********** Available products ***********"<<endl;
            cout<<"1. Chicken-Burger:                    200"<<endl;
            cout<<"2. Andy-wala Burger:                  150"<<endl;
            cout<<"3. Small-Sized-Pizza:                 400"<<endl;
            cout<<"4. Large-Sized-Pizza:                 750"<<endl;
            cout<<"5. Fries:                             100"<<endl;
            cout<<"6. One-Liter-Coke:                    120"<<endl;
            cout<<"7. Shuwarma:                          150"<<endl;
            cout<<"******************************************"<<endl<<endl;


            cout<<"Enter your new choice: ";
            cin>>option;

            
            switch (option)
            {
                case 1:
                {   
                    price = 200;
                    product = "Chicken-Burger";
                    break;
                }
                case 2:
                {
                    price = 150;
                    product = "Andy-wala-Burger";
                    break;
                }
                case 3:
                {
                    price = 400;
                    product = "Small-Sized-Pizza";
                    break;
                }
                case 4:
                {
                    price = 750;
                    product = "Large-Sized-Pizza";
                    break;
                }
                case 5:
                {
                    price = 100;
                    product = "Fries";
                    break;
                }
                case 6:
                {
                    price = 120;
                    product = "One-Liter-Coke";
                    break;
                }
                case 7:
                {
                    price = 150;
                    product = "Shuwarma";
                    break;
                }

                default:
                {
                    cout<<"Invalid input!!"<<endl;
                    break;
                }
            }
            //Updating the order record in Linkedlist
            temp->orderName = product;
            temp->price = price;
            done = true;
            
        }
        temp = temp->next;
    }
    if(done)
        cout<<"Data updated successfully"<<endl;
    else{
        cout<<"No such record exists!!!"<<endl;
    }
}


void cancelOrder(){
    string name = "";
    string phone = "";
    int total = 0;
    int orderId;
    cout<<endl;

    cout<<"*********** Cancel an Order ***********"<<endl;
    cout<<"Enter the customer name: "<<" ";
    cin>>name;
    cout<<"Enter the mobile number: "<<" ";
    cin>>phone;
    cout<<"Enter your order ID: "<<" ";
    cin>>orderId;

    Orders* temp = first;
    Orders* prev = NULL;
    bool done = false;

    while(temp != NULL){
        if(temp->customerName == name && temp->mobileNo == phone && temp->id == orderId){
            cout<<"\n";
            prev->next = temp->next;
            delete temp;
            done = true;
        }
        prev = temp;
        temp = temp->next;
    }
    if(done)
        cout<<"Successfully canceled an order!!!"<<endl;
    else{
        cout<<"No such record exists!!!"<<endl;
    }
}

int main(){
//Main Calling function
    while(true){
            int choice;
            cout<<"\n";
            cout<<"****** FoodPanda Management System *******"<<endl;
            cout<<"------------------------------------------"<<endl;
            cout<<"Enter 1 to purchase products: "<<endl;
            cout<<"Enter 2 to check all orders: "<<endl;
            cout<<"Enter 3 to check bills: "<<endl;
            cout<<"Enter 4 to update order: "<<endl;
            cout<<"Enter 5 to cancel order: "<<endl;
            cout<<"Enter 6 to exit: "<<endl<<endl;

            cout<<"Enter your choice: ";
            cin>>choice;

            cout<<endl;

            switch(choice){
                case 1:
                    orderProducts();
                    break;

                case 2:
                    checkOrders();
                    break;
    
                case 3:
                    checkBills();
                    break;
                case 4:
                    updateOrders();
                    break;
                case 5:
                    cancelOrder();
                    break;
                case 6:
                    cout<<"Thank you for visiting our bakkery!!\nHave a great day Sir!!"<<endl<<endl;
                    exit(0);
                    break;
                default:
                    cout<<"Invalid input!!!"<<endl;

            }
            cout<<endl;   
        }
}