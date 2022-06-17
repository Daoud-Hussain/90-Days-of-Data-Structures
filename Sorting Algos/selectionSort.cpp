#include<iostream>
using namespace std;


//Function to sort the array using selection sort algo
void selectionSort(int arr[], int size){
    for(int i = 0; i < size -1; i++){
        int minIndex = i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[minIndex]){
                //Finding the minimum value index if
                // found between the array
                minIndex = j;
            }
        }

        // Swapping the minimum value with ith value
        int temp = arr[minIndex]; 
        arr[minIndex] = arr[i];
        arr[i] = temp;
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
    selectionSort(arr, size);
    printArray(arr, size);

}