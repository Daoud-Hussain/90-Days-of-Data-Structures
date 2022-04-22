#include <iostream>
using namespace std;

struct stu {
    int data;
    stu* next = NULL;
};


//Method to input data at a specific index
stu* insertAtIndex(stu* head, int data, int index){
	stu* curr = new stu();
	stu* p = head;
	int i = 0;
	while(i!=index-1){
		p = p->next;
		i++;
	}
	curr->data = data;
	curr->next = p->next;
	p->next = curr;
	
}

//Method to input data at the start
stu* insertAtStart(stu* head, int data){
	stu* curr = new stu();
	curr->data = data;
	curr->next = head;
	head = curr;
	return head;
	
}

//Method to input data at the end
stu* insertAtEnd(stu* head, int data){
	stu* curr = new stu();
	stu* p = head;
	
	while(p->next != NULL){
		p = p->next;
	}
	curr->data = data;
	p->next = curr;
	curr->next = NULL;
	
}

//Method to print data 
void LinkedListTraversal(stu* ptr){
	while(ptr != NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
}


int main(){
	struct stu* first = new stu();
	struct stu* mid = new stu();
	struct stu* aftermid = new stu();
	struct stu* last = new stu();
		
	first->data = 10;
	first->next = mid;
	mid->data = 20;
	mid->next = aftermid;
	aftermid->data = 40;
	aftermid->next = last;
	last->data = 50;
	last->next = NULL;
	
	LinkedListTraversal(first);
	cout<<endl;
	insertAtIndex(first, 30,2);
		
	first = insertAtStart(first, 5);
	LinkedListTraversal(first);
	
	cout<<endl;
	insertAtEnd(first, 60);
	LinkedListTraversal(first);
}
