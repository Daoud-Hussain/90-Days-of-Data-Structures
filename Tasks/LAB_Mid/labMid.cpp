#include<iostream>
#include <string>
using namespace std;

struct Market{
    string name;
    string order;
    int price;
    int sale; 
    Market* next; 
};

struct Customers{
    int id;
    string shopName;
    string customerName;
    string Quantity;
    Customers* next = NULL;
};

struct coffeeQueue{
    int front  = -1;
    int rear = -1;
    int size = 10;
    string *CoffeeQueueArr = new string[size];


    //Enqueue methods using FIFO 
    //Means Enqueue from rear and dequeue from front 
    void enQueue(string givenShop, string givenName, string quantity)
    {
        if (front == -1 && rear == -1)
        {   
            front++;
            rear++;
            int num = std::stoi(givenShop);
            for(int i=0; i < num; i++){
                CoffeeQueueArr[rear++] = givenShop;
                CoffeeQueueArr[rear++] = givenName;
            }
        }
        else
        {
            rear++;
            int num = std::stoi(givenShop);
            for(int i=0; i < num; i++){
                CoffeeQueueArr[rear++] = givenShop;
                CoffeeQueueArr[rear++] = givenName;
            }
        }
    }

    string deQueue()
    {
        if (front!= -1 || rear != -1)
        {
           string value1 = CoffeeQueueArr[front++];
           string value2 = CoffeeQueueArr[front++];
            return value1 + value2 ;
        }
    }


};

struct pizzaQueue{
    int front  = -1;
    int rear = -1;
    int size = 10;
    string *PizzaQueueArr = new string[size];


    //Enqueue methods using LIFO
    //Means Enqueue from rear and dequeue from rear 
    void enQueue(string givenShop, string givenName, string givenQuantity)
    {
        if (front == -1 && rear == -1)
        {   
            front++;
            rear++;
            int num = std::stoi(givenShop);
            for(int i=0; i < num; i++){
                PizzaQueueArr[rear] = givenShop;
                PizzaQueueArr[rear] = givenName;
            }
        }
        else
        {
            rear++;
            //Converting string into integer
            int num = std::stoi(givenShop);
            for(int i=0; i < num; i++){
                PizzaQueueArr[rear] = givenShop;
                PizzaQueueArr[rear] = givenName;
            }
        }
    }

    string deQueue()
    {
        if (front!= -1 || rear != -1)
        {
           string value1 = PizzaQueueArr[rear--];
           string value2 = PizzaQueueArr[front--];
            return value1 + value2 ;
        }
    }


};

struct iceCreamQueue{
    int front  = -1;
    int rear = -1;
    int size = 15;
    string *iceCreamQueueArr = new string[size];


    //Enqueue methods using priority 
    void enQueue(string givenName, string givenShop, string givenQuantity)
    {
        if (front == -1 && rear == -1)
        {   
            front++;
            rear++;
            //Converting string into integers
            int num = std::stoi(givenShop);
            for(int i=0; i < num; i++){
                iceCreamQueueArr[(rear+1)%size] = givenShop;
                iceCreamQueueArr[(rear+1)%size] = givenName;
            }
        }
        else
        {
            rear++;
            int num = std::stoi(givenShop);
            for(int i=0; i < num; i++){
                iceCreamQueueArr[(rear+1)%size] = givenShop;
                iceCreamQueueArr[(rear+1)%size] = givenName;
            }
        }
    }

    //Dequeing the data from icecream queue
    string deQueue()
    {
        if (front!= -1 || rear != -1)
        {   
            int fr = front;
            int maxFindArr[size];
            string maxNameArr[size];
            string maxOrderName = "";
            int count = 0;
            int i = 0;
            while(fr != rear){
                if(iceCreamQueueArr[fr] == iceCreamQueueArr[fr-1] ){
                    count++;
                    maxOrderName = iceCreamQueueArr[fr];
                }
                else{
                    //Storing maximum order count in the maximum array
                    maxFindArr[i] = count;
                    maxNameArr[i] = maxOrderName;
                    i++;
                }
            }


            int max = 0;
            int maxIndex = 0;
            //Finding the customer name with maximum orders
            for(int i=0; i < size; i++){
                if(maxFindArr[i] > max){
                    maxIndex = maxFindArr[i];
                }
            }


            //Dequeing the name of Customer with maximum orders from the iceCreamQueue
            int tempFront = front;
            while(tempFront != rear){
                if(iceCreamQueueArr[tempFront++] == maxOrderName){
                string value1 = iceCreamQueueArr[front++];
                return value1;
                }
            }
        }
    }


};




//Method to traverse the linkedlist 
void printNodes(Customers* m){
    Customers* curr = m;
    while(curr != NULL){
        cout<< m->customerName<<endl;
        cout<< m->shopName<<endl;
        cout<<"Customer ID: "<< m->id<<endl;

        m = m->next;

    }
}

//Method to add a customer
void* addACustomer(Customers* head, string name, string givenShop,int givenID, string quan){
	Customers* curr = new Customers();
	Customers* p = head;
	
	while(p->next != NULL){
		p = p->next;
	}
	curr->Quantity = quan;
    curr->customerName = name;
	curr->shopName = givenShop;
    curr->id = givenID;
	p->next = curr;
	curr->next = NULL;
	
}

int main(){
    Market* m1 = new Market();
    m1->name = "Coffee";
    m1->order = "FIFO";
    m1->price = 50;
    m1->sale = 0;
    m1->next = NULL;


    Market* m2 = new Market();
    m2->name = "IceCream";
    m2->order = "Priority";
    m2->price = 30;
    m2->sale = 0;
    m1->next = m2;
    m2->next = NULL;


    Market* m3 = new Market();
    m3->name = "Pizza";
    m3->order = "LIFO";
    m3->price = 250;
    m3->sale = 0;
    m2->next = m3;
    m3->next = NULL;



    Customers* c1 = new Customers();
    
    coffeeQueue myCoffee;
    pizzaQueue myPizza;
    iceCreamQueue myIceCream;
    addACustomer(c1, "Daoud", "Coffee",1, "3");
    addACustomer(c1, "Ahmed", "Pizza",2, "5");
    addACustomer(c1, "Zuwanish", "IceCream",3, "2");
    addACustomer(c1, "Muneeb", "Pizza", 4,"3");
    addACustomer(c1, "Ali", "Coffee", 5, "1");

    printNodes(c1);

    //Traversing all the customers one by one till we get the NULL
    while(c1->next != NULL){
        if(c1->shopName == "Coffee"){
            myCoffee.enQueue(c1->shopName, c1->customerName, c1->Quantity);
        }
        if(c1->shopName == "Pizza"){
            myPizza.enQueue(c1->shopName,c1->customerName, c1->Quantity);
        }
        if(c1->shopName == "IceCream"){
            myIceCream.enQueue(c1->shopName,c1->customerName, c1->Quantity);
        }
        c1 = c1->next;
    
    }

    // bool flag = true;
    // int choice = 0;
    // while(flag){
    //     cout<<"Enter 1 to add a customer"<<endl;
    //     cout<<"Enter 2 to add your order"<<endl;
    //     cout<<"Enter 3 to serve your order"<<endl;
    //     cout<<"Enter 4 to exit "<<endl;
    //     cout<<endl;
    //     cout<<"Enter your choice: ";
    //     cin>>choice;
    //     switch (choice)
    //     {
    //     case 1: 
    //     {   
    //         string name;
    //         string order;
    //         int quantity;
    //         cout<<"Enter your name: ";
    //         cin>>name;
    //         cout<<"Enter your Item name: ";
    //         cin>>order;
    //         cout<<"Enter your quantity: ";
    //         cin>>quantity;

    //         addACustomer(c1, name, order, quantity);
    //         break;
    //         cout<<endl;

    //     }

    //     case 2: 
    //     {   
    //         //Taking order
            
    //         cout<<endl;
    //         break;
    //     }
    //     case 3:
    //     {   
    //         string userName;
    //         cout<<"Which Customer number you want to serve order: ";
    //         cin>>userName;
    //         Customers* temp = c1;
    //         while(temp != NULL){
    //             if(temp->customerName == userName){
    //                 if(temp->shopName == "Coffee"){
    //                     myCoffee.deQueue();
    //                 }
    //                 else if(temp->shopName == "Pizza"){
    //                     myPizza.deQueue();
    //                 }
    //                 else if(temp->shopName == "IceCream"){
    //                     myIceCream.deQueue();
    //                 }
    //                 else{
    //                     cout<<"Invalid ";
    //                 }
    //             }
    //         }
    //     }

    //     case 4:
    //         flag = false;
    //         break;
    //     default:
    //         break;
    //     }
    // }

    //Printing all the customers
    



}