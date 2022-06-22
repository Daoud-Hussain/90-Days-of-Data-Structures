#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
	int low = 0, high = size - 1;
	int mid;
	
	while (high - low > 1) {
		int mid = (high + low) / 2;
		if (arr[mid] < key) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
    
	if (arr[low] == key) {
		cout << "Element found at "<<low<<" index"<<endl;
	}
	else if (arr[high] == key) {
		cout << "Element found at "<<high<<" index"<<endl;

	}
	else {
		cout << "Element not Found!!" << endl;
	}
}

int main()
{   
    int size = 10;
	int arr[size] = { 1, 4, 9, 15, 16 ,22, 27, 33};
	int key = 22;
	binarySearch(arr,size, key);
	return 0;
}
