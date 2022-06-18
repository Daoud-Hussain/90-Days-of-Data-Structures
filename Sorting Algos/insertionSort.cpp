#include<iostream>
using namespace std;


//Function to sort the array using insertion sort algo
void insertionSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j;
        for(j = i-1; j >= 0 && arr[j] > key; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
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
    insertionSort(arr, size);
    printArray(arr, size);

}