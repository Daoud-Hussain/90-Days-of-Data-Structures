#include <iostream>
using namespace std;

struct stu
{
	int data;
	stu *next;
};

stu *first = NULL;
stu *last = NULL;

void printNodes(stu *p)
{
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

stu *reverseNodes(stu *p)
{
	if (p == NULL || p->next == NULL)
	{
		return p;
	}
	stu *newFirst = reverseNodes(p->next);
	p->next->next = p;
	p->next = NULL;
	return newFirst;
}


bool checkPalindrome(stu *revFirst)
{
	stu *p = first;
	stu *q = revFirst;

	bool flag = true;;

	while (p->next != NULL)
	{	

		if (p->data != q->data)
		{
			flag = false;
		}
		
		p = p->next;
		q = q->next;

	}
	if (flag)
	{	
		cout<<"YES";
		return true;
	}
	else{
		return false;
	}

}


int main()
{

	stu *temp1 = new stu();
	temp1->data = 25;
	temp1->next = NULL;
	first = temp1;

	stu *temp2 = new stu();
	temp2->data = 25;
	temp2->next = NULL;
	temp1->next = temp2;

	stu *temp3 = new stu();
	temp3->data = 22;
	temp3->next = NULL;
	temp2->next = temp3;

	stu *temp4 = new stu();
	temp4->data = 25;
	temp4->next = NULL;
	temp3->next = temp4;

	stu *temp5 = new stu();
	temp5->data = 26;
	temp5->next = NULL;
	temp4->next = temp5;

	printNodes(first);
	cout << endl;
	stu *tempPrint = first;
	stu *x = reverseNodes(tempPrint);
	printNodes(x);


	stu *revFirst = reverseNodes(first);
	checkPalindrome(revFirst);
}
