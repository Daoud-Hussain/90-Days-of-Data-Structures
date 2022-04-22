#include<iostream>
using namespace std;


struct stu{
    int data;
    stu* next;
};
struct stu* first = NULL;
struct stu* last = NULL;


void printNodes(stu* p){
	while(p != NULL){
		cout<<p->data<<" ";
		p = p->next;
		
	}
}


stu* reverseNodes(stu * p){
    if(p == NULL || p->next==NULL){
        return p;
    }
    stu* newFirst = reverseNodes(p->next);
    p->next->next = p;
    p->next = NULL;
    return newFirst;

    
}

int main(int argc, char const *argv[])
{
	//Creating First Node
	//struct stu* temp1();
	struct stu* temp1 = new stu();
	temp1->data= 25;
	temp1->next= NULL;
	first = temp1;
	
	
	struct stu* temp2 = new stu();
	temp2->data= 30;
	temp2->next= NULL;
	temp1->next = temp2;
	
	struct stu* temp3 = new stu();
	temp3->data= 35;
	temp3->next= NULL;
	temp2->next = temp3;
	
	struct stu* temp4 = new stu();
	temp4->data= 40;
	temp4->next= NULL;
	temp3->next = temp4;
	
	printNodes(first);
	cout<<"\n";
	stu* printStart = first;
	stu* x = reverseNodes(first);
	printNodes(x);
}
