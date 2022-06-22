#include <iostream>
using namespace std;

void linearSearch(int arr[], int size, int key)
{
    int temp = -1;
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            temp = 0;
            index = i;
    }

    if(temp != -1){
        cout<<"Element " <<key<<" found at "<<index<<" index"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
}

int main(void)
{
    int arr[] = {2, 3, 4, 10, 40};
    int key = 10;
    int size = sizeof(arr) / sizeof(arr[0]);

    linearSearch(arr, size, key);
   
}