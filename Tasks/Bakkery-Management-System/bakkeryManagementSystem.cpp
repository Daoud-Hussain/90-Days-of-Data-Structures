#include<iostream>
using namespace std;

/*
    It is a simple management system made using arrays that
    performs CRUD operations using C++ procedural programming.
*/


//Function to purchase a new product
void purchaseProducts(string productArray[], int priceArray[]){
    string product;
    int price, option;
    int output = 0;
    cout<<endl;
    cout<<"********Available products******"<<endl;
    cout<<"1. Biscuits:                 50"<<endl;
    cout<<"2. Fruits:                250"<<endl;
    cout<<"3. Snacks:              150"<<endl;
    cout<<"4. Ketchup:                 200"<<endl;
    cout<<"5. Chocolates:              350"<<endl;
    cout<<"*********************************"<<endl<<endl;


    cout<<"Enter your choice: ";
    cin>>option;
    switch (option)
    {
    case 1:
    {
        price = 50;
        product = "Biscuits";
        break;
    }
    case 2:
    {
        price = 250;
        product = "Fruits";
        break;
    }
    case 3:
    {
        price = 150;
        product = "Snacks";
        break;
    }
    case 4:
    {
        price = 200;
        product = "Ketchup";
        break;
    }
    case 5:
    {
        price = 350;
        product = "Chocolates";
        break;
    }

    default:
        cout<<"Invalid input!!"<<endl;
        output = 1;
        break;
    }

    for(int i = 0; i < 10; i++){
        
        if(productArray[i] == "" && output == 0){
            productArray[i] = product;
            priceArray[i] = price;
            break;
        }
        else{

        }
        
    }
    if(output == 0){
        cout<<"Product purchased Successfully"<<endl;
    }
    else{
        cout<<"Couldn't purchased the product Successfully"<<endl;
    }
    cout<<endl;



}


//Function to check the purchased products
void checkRecord(string productArray[], int priceArray[]){
    
    //Printing values placed in the array
    cout<<endl<<"***************************"<<endl;
    cout<<"********Purchased elements:****** "<<endl;
    cout<<"---------------------------------"<<endl;
    for(int i = 0; i < 10; i++){
        if(productArray[i] != ""){
            cout<<i+1<<". "<<productArray[i]<<"          "<<priceArray[i]<<endl;
        }
    }
    cout<<"*****************************"<<endl;
    cout<<endl;
}


//Function to calculate bill of purchased products
void showBill(string productArray[], int priceArray[]){ 
    int totalBill = 0;

    cout<<endl<<"***************************"<<endl;
    cout<<"********Purchased elements:****** "<<endl;
    cout<<"---------------------------------"<<endl;
    for(int i = 0; i < 10; i++){
        if(productArray[i] != ""){
            cout<<i+1<<". "<<productArray[i]<<"          "<<priceArray[i]<<endl;
            totalBill += priceArray[i];
        }
    }
    cout<<"Total Bill:          "<<totalBill<<endl;
    cout<<"**********************************"<<endl;
    cout<<endl;
}


//Function to edit/modify the purchased products
void editRecords(string productArray[], int priceArray[]){
    
    cout<<endl<<"***************************"<<endl;
    cout<<"********Purchased elements:****** "<<endl;
    cout<<"---------------------------------"<<endl;
    for(int i = 0; i < 10; i++){
        if(productArray[i] != ""){
            cout<<i+1<<". "<<productArray[i]<<"          "<<priceArray[i]<<endl;
        }
    }
    cout<<"*****************************"<<endl;
    cout<<endl;

    int option;
    string product;
    cout<<"Enter the number of record you want to update: ";
    cin>>option;
    bool flag = false;
    int price;

    while(!flag){
        cout<<"Enter the new product you want to update: ";
        cin>>product;
        if(product == "Biscuits" ) {
            price = 50; 
            flag= true;
        }
        else if(product == "Snacks" ) {
            price = 150; 
            flag= true;
        }
        else if(product == "Ketchup" ) {
            price = 200; 
            flag= true;
        }
        else if(product == "Chocolates" ) {
            price = 350; 
            flag= true;
        }
        else if(product == "Fruits" ) {
            price = 250; 
            flag= true;
        }
        else{
            cout<<"Invalid product entered try again!!"<<endl;
        }
    }

    for(int i = 0; i < 10; i++){
        if(productArray[i] != ""){
            if(i+1 == option){
                productArray[i] = product;
                priceArray[i] = price;
                cout<<"Record Updated Successfully"<<endl;
            }
        }
    }
    cout<<endl;
}


//Main Calling function
int main()
{   
    string productArray[10];
    int pricesArray[10];
    while(true){
        int choice;
        cout<<"********Bakkery Management System********"<<endl;
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
                purchaseProducts(productArray, pricesArray);
                break;

            case 2:
                checkRecord(productArray, pricesArray);
                break;
            case 3:
                showBill(productArray, pricesArray);
                break;
            case 4:
                editRecords(productArray, pricesArray);
                break;
            case 5:
                exit(0);
                break;
            default:
                cout<<"Invalid input!!!"<<endl;

        }
        cout<<endl;   
    }

}