#include<iostream>
using namespace std;


//Function to sort the array using bubble sort algo
void bubbleSort(int arr[], int size){
    for(int i = 0; i < size -1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                //Swapping values
                int temp = arr[j]; 
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


//Function to values of array 
int* printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    return arr;
}

int main()
{   
    int size = 10;
    int arr[] = {10,21,2,30,5,13,44,17,9,31};

    cout<<"Before"<<endl;
    printArray(arr, size);


    cout<<"\nAfter"<<endl;
    bubbleSort(arr, size);
    printArray(arr, size);

}