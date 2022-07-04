#include<iostream>
using namespace std;

/*
    It is a simple management system made using arrays that
    performs CRUD operations using C++ procedural programming.
*/
struct Orders{
    string orderName;
    string customerName;
    string mobileNo;
    int price;
    Orders* next;
};
Orders* first = NULL;
Orders* last = NULL;


//Function to purchase a new product
void orderAProduct(){
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

   
    if(first == NULL && last == NULL){
        //Incase of no order
        Orders* order = new Orders();
        order->orderName = product;
        order->price = price;
        order->customerName = name;
        order->mobileNo = phone;
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
    int orderNo = 1;
    while(temp != NULL){
        cout<<"\n";
        cout<<"----------Your Orders---------------"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"Order Number:            "<<orderNo<<endl;
        cout<<"Customer Name:           "<<temp->customerName<<endl;
        cout<<"Order Name:              "<<temp->orderName<<endl;
        cout<<"Price:                   "<<temp->price<<endl;
        cout<<"Mobile Number:           "<<temp->mobileNo<<endl;
        temp = temp->next;
        orderNo++;
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
    int orderNo = 1;
    while(temp != NULL){
        if(temp->customerName == name){
            if(temp->mobileNo == phone){
                cout<<"\n";
                total += temp->price;
                cout<<"----------Your Orders---------------"<<endl;
                cout<<"-----------------------------------"<<endl;
                cout<<"Order Number:            "<<orderNo<<endl;
                cout<<"Customer Name:           "<<temp->customerName<<endl;
                cout<<"Order Name:              "<<temp->orderName<<endl;
                cout<<"Price:                   "<<temp->price<<endl;
                cout<<"Mobile Number:           "<<temp->mobileNo<<endl;
                orderNo++;
            }
            else{
                cout<<"Invalid phone!! Try Again"<<endl;
            }
        }
        else{
            cout<<"Invalid name!! Try Again"<<endl;
        }
        temp = temp->next;
    }
    cout<<"Total Bill: "<<total<<endl;
}

int main(){
//Main Calling function
    while(true){
            int choice;
            cout<<"\n";
            cout<<"*******FoodPanda Management System********"<<endl;
            cout<<"------------------------------------------"<<endl;
            cout<<"Enter 1 to purchase products: "<<endl;
            cout<<"Enter 2 to check products: "<<endl;
            cout<<"Enter 3 to show bills: "<<endl;
            cout<<"Enter 4 to edit products: "<<endl;
            cout<<"Enter 5 to exit: "<<endl<<endl;

            cout<<"Enter your choice: ";
            cin>>choice;

            cout<<endl;

            switch(choice){
                case 1:
                    orderAProduct();
                    break;

                case 2:
                    checkOrders();
                    break;
    
                case 3:
                    checkBills();
                    break;
                // case 4:
                //     editRecords(productArray, pricesArray);
                //     break;
                case 5:
                    cout<<"Thank you for visiting our bakkery!!\nHave a great day Sir!!"<<endl<<endl;
                    exit(0);
                    break;
                default:
                    cout<<"Invalid input!!!"<<endl;

            }
            cout<<endl;   
        }
}