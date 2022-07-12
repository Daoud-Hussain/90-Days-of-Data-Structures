#include<iostream>
using namespace std;

//Grpahs Implementation to find Dijistra's algo
int graph[7][7];
const int INF = 1000;
string sectors[7] = {"F7","I9","I8","H8","F8","H6","I10"};
int visited[7];
int parent[7];
int source = 0;
int finalDistance;
string destination;
string shortestPath;
string start =sectors[source];

class sta{
	public:
		int size, top;
		string *s;
	sta(){
		size=10;
		s=new string[size];
		top=-1;
	}

	void push(string x){
		s[++top]=x;						
	}		
	string pop(){
		string x = s[top--];
		return x;
	}
	bool isEmpty(){
		if(top==-1)
			return true;
		else
			return false;
	}
	void display(){
		for(int i=top; i>=0; i--){
				cout<<"\n"<<s[i];
		}
		cout<<"\n";
	}
};



void addEdgeDistance(int v1, int v2, int w){
		graph[v1][v2] = w;
		graph[v2][v1] = w;				
}

void displayShortestPath(int distance[], int parent[],int source, string unit, string destination){
	int j;
	sta s1;			// Stack is used in printing of path in Dijkstra's Algorithm
	for(int i=0;i<7;i++){
        if ((sectors[i]).compare(destination)==0){
            if(i!=source){
                s1.push(sectors[i]);
                j=i;
                //To display correctly
                do{
                    j=parent[j];
                    s1.push(sectors[j]);
                }while(j!=source);
            }
            while(!s1.isEmpty()){
                s1.pop();
            }		
            if (i!=source){
                finalDistance = distance[i];	
            }
        }
	}
	cout<<"\n------------------------------------------------------------------------\n";
}

int minDistance(int distance[], int visited[]){
	int min = INF; 				
	int minIndex;
	for (int i = 0; i < 7; i++)
		if (visited[i] == false && distance[i] <= min){
			min = distance[i], minIndex = i;
		}
	return minIndex;
}

void dijkstrasAlgorithm(int graph[][7],int distance[], int visited[], int parent[],int source,string unit, string destination){

	for(int i = 0; i < 7; i++){
		distance[i] = INF;
		visited[i] = 0;
		parent[i] = -1;
	}
	distance[source] = 0;

	for (int i = 0; i < 6; i++) {
		int u = minDistance(distance, visited);		
		visited[u] = 1;
		for (int i = 0; i < 7; i++){
                if (visited[i] == 0 && graph[u][i]){
                    if (distance[u] + graph[u][i] < distance[i]){
                        distance[i] = distance[u] + graph[u][i];	
                        parent[i] = u;
                    }
                }
		}
	}
	displayShortestPath(distance,parent,source,unit, destination);
}


//Linkedlist implementation
//Structure to add,update,check,delete orders
struct Orders{
    string orderName;
    string customerName;
    string mobileNo;
    int price;
    int id;
    int distance;
    string destination;
    Orders* next;
};
Orders* first = NULL;
Orders* last = NULL;

//Stack structure is being used to take feedback
struct stack
{   
    int top;
    int size;
    string *arr;

    stack(){
        int top = -1;
        int size = 5;
        string *arr = new string[size];
    }


    void display()
    {   
        cout<<"---------- Feedbacks ---------------"<<endl;
        cout<<"------------------------------------"<<endl;
        int t = top;
        while (t != -1)
        {
            cout << arr[t] << " ";
            t--;
        }
    }

    bool isFull()
    {
        if (top == size - 1)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    void push(string value)
    {
        if (isFull())
        {
            cout << "Stack OverFlow";
        }
        else
        {
            top++;
            arr[top] = value;
        }
    }

    string pop()
    {

        if (isEmpty())
        {
            cout << "Stack UnderFlow";
        }
        else
        {
            string value = arr[top];
            top--;
            // cout << "Popped Value is: " << value;
            return value;
        }
    }

//8. Function to take feedback from the customers
    string takeFeedback(string feedback){
        push(feedback);
        return feedback;
    }

}; 

// AVL-Trees structure to store delivered orders 
struct Tree{
    string orderName;
    string customerName;
    string mobileNo;
    int price;
    string destination;
    int id;
    int distance;
    int height;
    Tree* left;
    Tree* right;
};
Tree* root = NULL;

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

Tree* createTreeNode(string on, string cn, int dist, string dest, string mn, int ID,int pr){
    Tree* curr = new Tree();
    curr->orderName = on;
    curr->customerName = cn;
    curr->mobileNo = mn;
    curr->distance = dist;
    curr->destination = dest;
    curr->price = pr;
    
    curr->id = ID;
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


// 7. Function to display all delivered orders from AVL tree
void inOrdertraversal(Tree *p)
{
    if (p == NULL)
    {
        return;
    }
    inOrdertraversal(p->left);
    cout<<endl;
    cout<<"------ Your Delivered Orders ------"<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"Order Number:            "<<p->id<<endl;
    cout<<"Customer Name:           "<<p->customerName<<endl;
    cout<<"Order Name:              "<<p->orderName<<endl;
    cout<<"Price:                   "<<p->price<<endl;
    cout<<"Mobile Number:           "<<p->mobileNo<<endl;
    cout<<"From:                    F7"<<endl;
    cout<<"To:                      "<<p->destination<<endl;
    cout<<"Shortest Distance:       "<<finalDistance<<"km"<<endl;
    inOrdertraversal(p->right);

}


Tree* insertTreeNode(Tree* root, Orders* cancelled){
    if(root == NULL){
        return(createTreeNode(cancelled->orderName, cancelled->customerName, cancelled->distance, cancelled->destination, cancelled->mobileNo, cancelled->id, cancelled->price ));
    }
    else if(root->id > cancelled->id){
        root->left = insertTreeNode(root->left, cancelled);
    }

    else if(root->id < cancelled->id){
        root->right = insertTreeNode(root->right, cancelled);
    }
    else{
        cout<<"No duplicate node exists in BST"<<endl;
    }

    root->height = 1 + max(height(root->left), height(root->right));
 

    //Checking if the inserted node is unbalanced or not
    int balanceFactor = getBalanceFactor(root);

    //If the node is unbalanced,  we will have four cases
    //1. RR - rotation
    if(balanceFactor < -1 && cancelled->id > root->right->id ){
        return leftRotation(root);
    }

    //2. LL - rotation
    if(balanceFactor > 1 && cancelled->id < root->left->id ){
        return rightRotation(root);
    }

    //3. RL - rotation
    if(balanceFactor < -1 && cancelled->id < root->right->id){
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    //4. LR - rotation
    if(balanceFactor > 1 && cancelled->id > root->left->id){
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    return root;
}


// -------------------------------------------------------------------------------------------
// Working functions starting

//1. Function to purchase a new product
void orderProducts(){
    string product = "";
    int option,price;
    bool flag = true;
    string name = "";
    string phone = "";
    int distance[7];
    
    cout<<"Enter your destination: "<<" ";
    cin>>destination;
    dijkstrasAlgorithm(graph,distance,visited,parent,source,"km",destination);
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
        order->destination = destination;
        order->distance = finalDistance;
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
        order->destination = destination;
        order->distance = finalDistance;
        last = order;
        order->next = NULL;
    }
    finalDistance = 0;


    if(flag){
        cout<<product<<" is purchased Successfully"<<endl;
    }
    else{
        cout<<"Couldn't purchased the product Successfully"<<endl;
    }
    cout<<endl;


}

//2. Function to check all the orders
void checkOrders(){
    Orders* temp = first;
    if(temp == NULL){
        cout<<"No record found!!!"<<endl;
    }
    while(temp != NULL){
        cout<<"\n";
        cout<<"----------Your Orders---------------"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"Order Number:            "<<temp->id<<endl;
        cout<<"Customer Name:           "<<temp->customerName<<endl;
        cout<<"Order Name:              "<<temp->orderName<<endl;
        cout<<"Price:                   "<<temp->price<<endl;
        cout<<"Mobile Number:           "<<temp->mobileNo<<endl;
        cout<<"From:                    F7"<<endl;
        cout<<"To:                      "<<temp->destination<<endl;
        cout<<"Shortest Distance:       "<<temp->distance<<"km"<<endl;

        temp = temp->next;
    }
    
}

//3. Function to check bill of a specific customer
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
            cout<<"From:                    F7"<<endl;
            cout<<"To:                      "<<temp->destination<<endl;
            cout<<"Shortest Distance:       "<<finalDistance<<"km"<<endl;
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

//4. Function to update/modify an order
void updateOrders(){
    string name = "";
    string phone = "";
    int option, price;
    string product = "";
    bool done = false;
    cout<<endl;

    cout<<"*********** Update your Order ***********"<<endl;
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

//5. Function to cancel an order
void cancelOrder(){
    string name = "";
    string phone = "";
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
            //Deleting nodes
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

//6. Function to deliver orders of a customer
void deliverOrders(){
    string name = "";
    string phone = "";

    cout<<endl;

    cout<<"*********** Deliver Orders ***********"<<endl;
    cout<<"Enter the customer name: "<<" ";
    cin>>name;
    cout<<"Enter the mobile number: "<<" ";
    cin>>phone;

    Orders* temp = first;
    Orders* temp2 = first;
    Orders* prev = NULL;
    bool done = false;

    cout<<"----------Your Orders---------------"<<endl;
    cout<<"-----------------------------------"<<endl;
    while(temp != NULL){
        if(temp->customerName == name && temp->mobileNo == phone){
            // Storing all the orders that are to be delivered in AVL Tree
            root = insertTreeNode(root, temp);
            done = true;

        }
        temp = temp->next;

    }

    while(temp2 != NULL){
        if(temp2->customerName == name && temp2->mobileNo == phone){
            //Deleting all delivered orders
            if(prev == NULL){
                //For first node
                Orders* curr = first;
                first = first->next;
                curr->next = NULL;
                delete curr;
            }
            else if(temp2 == NULL){
                //For last node
                prev->next = NULL;
                last = prev;
            }
            else{
                //For middle nodes
                prev->next = temp2->next;
                delete temp2;
            }
        }
        prev = temp2;
        temp2 = temp2->next;

    }

    if(done){
        cout<<"Successfully delivered all orders!!!"<<endl;
        string feedback = "";
        cout<<"Before quiting, Please share your valuable feedback: (Great/Good/Bad)?? ";
        cin>>feedback;
        stack *s1;
        s1->takeFeedback(feedback);
    }
    else{
        cout<<"No such record exists!!!"<<endl;
    }
}



int main(){
//Main Calling function
    while(true){
            
            //Initializing graph 
            addEdgeDistance(0,1,315);
	        addEdgeDistance(0,2,374);
	        addEdgeDistance(0,3,1025);
	        addEdgeDistance(1,4,520);
	        addEdgeDistance(2,3,149);
	        addEdgeDistance(2,4,186);	
	        addEdgeDistance(2,5,158);	
	        addEdgeDistance(3,5,1095);
	        addEdgeDistance(6,4,598);
	        addEdgeDistance(6,5,50);


            int choice;
            cout<<"\n";
            cout<<"****** FoodPanda Management System *******"<<endl;
            cout<<"------------------------------------------"<<endl;
            cout<<"Enter 1 to purchase products: "<<endl;
            cout<<"Enter 2 to check all orders: "<<endl;
            cout<<"Enter 3 to check bills: "<<endl;
            cout<<"Enter 4 to update order: "<<endl;
            cout<<"Enter 5 to cancel order: "<<endl;
            cout<<"Enter 6 to deliver order: "<<endl;
            cout<<"Enter 7 to check delivered orders: "<<endl;
            cout<<"Enter 8 to check feedback: "<<endl;
            cout<<"Enter 9 to exit: "<<endl<<endl;

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
                    deliverOrders();
                    break;
                case 7:
                    inOrdertraversal(root);
                    break;
                case 8:
                {
                    stack *s1;
                    s1->display();
                    break;
                }
                case 9:
                    cout<<"Thank you for visiting our bakkery!!\nHave a great day Sir!!"<<endl<<endl;
                    exit(0);
                    break;
                default:
                    cout<<"Invalid input!!!"<<endl;

            }
            cout<<endl;   
        }
}