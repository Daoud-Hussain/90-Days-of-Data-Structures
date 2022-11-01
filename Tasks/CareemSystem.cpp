#include <iostream>
using namespace std;
struct ride
{
	string rideName;
	int charges;
	int km;
	ride *next;
};

struct car *first = NULL;
struct car *last = NULL;

// Car structure
struct car
{
	string driverName;
	string carName;
	int regNo;
	int carType;
	int km;
	int earning;
	car *next = NULL;
	ride *ridePtr;
};

// Method to add a new car 
car *insertCar(car *head, string cn, int rn, int ct)
{
	struct car *curr = new car();
	if (first->next == NULL)
	{
		curr->regNo = rn;
		curr->carName = cn;
		curr->carType = ct;
	}
	else
	{
		curr->regNo = rn;
		curr->carName = cn;
		curr->carType = ct;
	}
	curr->next = head;
	head = curr;
	return head;
}

// Method to print all cars
void printNodes(car *p)
{
	while (p != NULL)
	{
		cout << "CarName: " << p->carName << " ";
		cout << "RegNo: " << p->regNo << " ";
		cout << "CarType: " << p->carType << " ";
		cout << endl;
		p = p->next;
	}
}

// Method to print all cars of type 2
void displayType2Nodes(car *p)
{
	while (p != NULL)
	{
		if (p->carType == 2)
		{
			cout << p->carName << " " << p->regNo;
			cout << endl;
		}
		p = p->next;
	}
}

// Method to add a new ride in a car
void addNewRide(car *head, int regNum)
{
	while (head->next != NULL && head->regNo != regNum)
	{
		head = head->next;
	}

	if (head != NULL)
	{

		ride *ptr = new ride();
		int ch, kilom;
		string rn;
		cout << "Enter ride name: ";
		cin >> rn;
		cout << "Enter charges: ";
		cin >> ch;
		cout << "Enter km: ";
		cin >> kilom;
		ptr->charges = ch;
		head->earning += ptr->charges;
		ptr->km = kilom;
		ptr->rideName = rn;

		if (head->ridePtr == NULL)
		{
			head->ridePtr = ptr;
			head->ridePtr->next = NULL;
		}
		else
		{
			ptr->next = head->ridePtr;
			head->ridePtr = ptr;
		}
	}
}

// Method to display rides of cars
void displayCarRides(car *head, int rn)
{
	while (head != NULL && head->regNo != rn)
	{
		head = head->next;
	}
	if (head != NULL)
	{

		ride *khaliPtr = head->ridePtr;
		cout << "Ride name: "<< khaliPtr->rideName << endl;
		cout << "Ride Charges: "<< khaliPtr->charges << endl;
		cout << "Ride Km: "<< khaliPtr->km << endl;
	}
}
// Method to display total earning of a car
void displayTotalEarning(car *p, int rn)
{

	while (p->next != NULL)
	{
		if (p->regNo == rn)
		{
			cout << "Total Earning of the given Car is: " << p->earning << endl;
		}

		p = p->next;
	}
}

// Method to display earnings of all the cars
void displayEarningOfAllCars(car *p)
{
	while (p != NULL)
	{
		cout << "Total earning of car with registration number: " << p->regNo << " is: " << p->earning << endl;
		p = p->next;
	}
}

// Main Function
int main()
{
	car *car1 = new car();
	car1->carName = "Honda";
	car1->carType = 1;
	car1->regNo = 5;
	car1->next = NULL;
	first = car1;
	ride *ptr = car1->ridePtr;

	ride *ptr2 = new ride();
	ptr2->charges = 100;
	car1->earning += ptr2->charges;
	ptr2->km = 1000;
	ptr2->rideName = "Zohaib Jani";
	ptr = ptr2;
	ptr->next = NULL;

	// ride *ptr3 = new ride();
	// ptr3->charges = 100;
	// car1->earning += ptr3->charges;
	// ptr3->km = 1000;
	// ptr3->rideName = "Zohaib Jani";
	// ptr3->next = ptr;
	// ptr = ptr3;

	car *car2 = new car();
	car2->carName = "Civic";
	car2->carType = 2;
	car2->regNo = 10;
	car1->next = car2;
	car2->next = NULL;

	car *car3 = new car();
	car3->carName = "Corolla";
	car3->carType = 2;
	car3->regNo = 15;
	car2->next = car3;
	car3->next = NULL;

	car *car4 = new car();
	car4->carName = "Lamborghini";
	car4->carType = 1;
	car4->regNo = 20;
	car3->next = car4;
	car4->next = NULL;

	// displayTotalEarning(first, 10);
	// displayEarningOfAllCars(first);
	bool flag = true;
	while (flag)
	{
		int choice;
		cout << "Enter 1 to register a new car: ";
		cout << endl
			 << "Enter 2 to display details of all cars: ";
		cout << endl
			 << "Enter 3 to display cars of type 2: ";
		cout << endl
			 << "Enter 4 to register a new ride: ";
		cout << endl
			 << "Enter 5 to display all rides: ";
		cout << endl
			 << "Enter 6 to display earning of a specific car: ";
		cout << endl
			 << "Enter 7 to display earning of all cars: ";
		cout << endl
			 << "Enter 8 to exit: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
		{
			cout << "REGISTER A NEW CAR" << endl;
			string cn;
			int rn, ct;
			cout << "Enter car name: ";
			cin >> cn;
			cout << "Enter registration number: ";
			cin >> rn;
			cout << "Enter car type 1/2: ";
			cin >> ct;
			first = insertCar(first, cn, rn, ct);
			cout << endl;
			break;
		}
		case 2:
		{
			cout << endl
				 << "DISPLAY ALL REGISTERED CARS" << endl;
			printNodes(first);
			cout << endl;

			break;
		}
		case 3:
		{
			cout << endl
				 << "DISPLAY ALL CARS OF TYPE 2" << endl;
			displayType2Nodes(first);
			cout << endl;

			break;
		}
		case 4:
		{
			cout << endl
				 << "ADD A NEW RIDE CAR" << endl;
			int registerationNo;
			cout << "Enter the registeration number of car you want to add ride: ";
			cin >> registerationNo;
			addNewRide(first, registerationNo);
			cout << endl;
			break;
		}

		case 5:
		{
			cout << endl
				 << "DISPLAY ALL RIDES" << endl;
			int registerationNo;
			cout << "Enter the registeration number of car you want to display rides: ";
			cin >> registerationNo;
			displayCarRides(first, registerationNo);
			cout << endl;
			break;
		}
		case 6:
		{
			cout << endl
				 << "DISPLAY EARNING OF A SPECIFIC CAR" << endl;
			int registerationNo;
			cout << "Enter the registeration number of car you want to check earning: ";
			cin >> registerationNo;
			displayTotalEarning(first, registerationNo);
			cout << endl;
			break;
		}
		case 7:
		{
			cout << endl
				 << "DISPLAY EARNING OF ALL CARS" << endl;
			displayEarningOfAllCars(first);
			cout << endl;
			break;
		}

		case 8:
		{
			flag = false;
			break;
		}

		default:
			cout<<"Enter a Valid Input!!!";
			break;
		}
	}
}
