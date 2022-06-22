#include<iostream>
using namespace std;

//Method to swap two nodes
void swap(int *a, int *b){
    int* temp = a;
    a = b; 
    b = temp;

}

//Here, we have data as value of root
//and i as index of root that will be always 0 initially
void heapify(int givenArr[], int size, int i){
    int largest = i;
    int leftChild = 2*i; 
    int rightChild = 2*i + 1;

    if(leftChild < size && givenArr[leftChild] > givenArr[largest] ){
        largest = leftChild;
    }
    if(rightChild < size && givenArr[rightChild] > givenArr[largest]){
        largest = rightChild;
    }
    if(largest != i){
        swap(i, largest);
        heapify(givenArr, size, largest);
    }


}


int main()
{   
    int arr[10] = {1,2,5,7,9,12,14,19};  
    heapify(arr, 8, 0);  
}