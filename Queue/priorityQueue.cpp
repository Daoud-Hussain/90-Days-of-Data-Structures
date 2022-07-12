#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Structure for the elements in the
// priority queue
struct item {
	int value;
	int priority;
};

item pr[100000];
int size = -1;

void enqueue(int value, int priority)
{
	size++;

	// Insert the element
	pr[size].value = value;
	pr[size].priority = priority;
}

int peek()
{
	int highestPriority = INT_MIN;
	int ind = -1;

	for (int i = 0; i <= size; i++) {

		if (highestPriority == pr[i].priority && ind > -1 && pr[ind].value < pr[i].value) {
			highestPriority = pr[i].priority;
			ind = i;
		}
		else if (highestPriority < pr[i].priority) {
			highestPriority = pr[i].priority;
			ind = i;
		}
	}

	return ind;
}

void dequeue()
{
	// Find the position of the element
	// with highest priority
	int ind = peek();

	// Shift the element one index before
	// from the position of the element
	// with highest priority is found
	for (int i = ind; i < size; i++) {
		pr[i] = pr[i + 1];
	}

	// Decrease the size of the
	// priority queue by one
	size--;
}

// Driver Code
int main()
{
	enqueue(10, 1);
	enqueue(14, 3);
	enqueue(16, 4);
	enqueue(12, 2);

	int ind = peek();

	cout << pr[ind].value << endl;
	dequeue();

	ind = peek();
	cout << pr[ind].value << endl;

	dequeue();

	ind = peek();
	cout << pr[ind].value << endl;

	return 0;
}
