#include <iostream>
using namespace std;
struct distanceNode
{
    string name;
    string cnic;
    string travelFrom;
    string travelTo;
    int price;
    int tax;
    int distanceTravel;
    distanceNode *next;
    distanceNode *previous;
};
distanceNode *first = NULL;
distanceNode *last = NULL;
bool isEmpty()
{
    if (first == NULL && last == NULL)
    {
        return true;
    }
    return false;
}
int visited[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int distances[15] = {100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000};
int matrixGraph[15][15];
string travel[15] = {"Lahore", "Karachi", "Peshawar", "Multan", "Islamabad/Faizabad", "Dera ghazi Khan", "Quetta", "Sargodha", "Hydrabad", "Sahiwal", "Swat", "Hunza Valley", "Gawadar", "larkana", "Sialkot"};
void addTOGraph(int i, int j, int weight)
{
    matrixGraph[i][j] = weight;
    matrixGraph[j][i] = weight;
}
void initialized(int matrixGraph[][15])
{
    for (int i = 0; i < (sizeof visited / sizeof visited[0]); i++)
    {
        /* code */
        for (int j = 0; j < (sizeof visited / sizeof visited[0]); j++)
        {
            /* code */
            matrixGraph[i][j] = 0;
        }
    }
}
bool isNotVisited()
{
    for (int i = 0; i < (sizeof visited / sizeof visited[0]); i++)
    {
        /* code */
        if (visited[i] == 0)
        {
            return true;
        }
    }
    return false;
}
int mininmumDiistance()
{
    int min = 100000;
    int index;
    for (int i = 0; i < (sizeof visited / sizeof visited[0]); i++)
    {
        /* code */
        if (visited[i] == 0 && distances[i] < min)
        {
            min = distances[i];
            index = i;
        }
    }
    return index;
}
int dijkstraAlgo(int source, int dep)
{
    int src = source;
    distances[source] = 0;
    while (isNotVisited())
    {
        source = mininmumDiistance();

        visited[source] = 1;
        for (int j = 0; j < (sizeof visited / sizeof visited[0]); j++)
        {
            if (visited[j] == 0)
            {
                if (matrixGraph[source][j] != 0)
                {
                    if (distances[j] > matrixGraph[source][j] + distances[source])
                    {
                        distances[j] = matrixGraph[source][j] + distances[source];
                    }
                }
            }
        }
    }
    return distances[dep];
}
void displayGraph()
{

    for (int i = 0; i < 15; i++)
    {
        /* code */
        cout << "                              ";
        for (int j = 0; j < 15; j++)
        {
            /* code */
            cout << matrixGraph[i][j] << "  ";
        }
        cout << endl;
    }
}
void graphDistance()
{
    initialized(matrixGraph);
    // Lahore Distance to all Cities
    addTOGraph(0, 1, 1250);
    addTOGraph(0, 2, 450);
    addTOGraph(0, 3, 350);
    addTOGraph(0, 4, 250);
    addTOGraph(0, 5, 437);
    addTOGraph(0, 6, 550);
    addTOGraph(0, 7, 166);
    addTOGraph(0, 8, 950);
    addTOGraph(0, 9, 155);
    addTOGraph(0, 10, 440);
    addTOGraph(0, 11, 510);
    addTOGraph(0, 12, 1820);
    addTOGraph(0, 13, 800);
    addTOGraph(0, 14, 115);
    // Karachi Distance to all Cities
    addTOGraph(1, 2, 1450);
    addTOGraph(1, 3, 650);
    addTOGraph(1, 4, 1300);
    addTOGraph(1, 5, 750);
    addTOGraph(1, 6, 620);
    addTOGraph(1, 7, 1140);
    addTOGraph(1, 8, 150);
    addTOGraph(1, 9, 1000);
    addTOGraph(1, 10, 1590);
    addTOGraph(1, 11, 1960);
    addTOGraph(1, 12, 630);
    addTOGraph(1, 13, 440);
    addTOGraph(1, 14, 1300);
    // Peshawar Distance to all Cities
    addTOGraph(2, 3, 580);
    addTOGraph(2, 4, 155);
    addTOGraph(2, 5, 270);
    addTOGraph(2, 6, 1500);
    addTOGraph(2, 7, 380);
    addTOGraph(2, 8, 1390);
    addTOGraph(2, 9, 550);
    addTOGraph(2, 10, 1300);
    addTOGraph(2, 11, 640);
    addTOGraph(2, 12, 1740);
    addTOGraph(2, 13, 1100);
    addTOGraph(2, 14, 590);
    // Multan Distance to all Cities
    addTOGraph(3, 4, 510);
    addTOGraph(3, 5, 85);
    addTOGraph(3, 6, 580);
    addTOGraph(3, 7, 320);
    addTOGraph(3, 8, 710);
    addTOGraph(3, 9, 170);
    addTOGraph(3, 10, 560);
    addTOGraph(3, 11, 1000);
    addTOGraph(3, 12, 1490);
    addTOGraph(3, 13, 512);
    addTOGraph(3, 14, 420);
    // Islamabad\Faizabad Distance to all Cities
    addTOGraph(4, 5, 320);
    addTOGraph(4, 6, 800);
    addTOGraph(4, 7, 250);
    addTOGraph(4, 8, 1250);
    addTOGraph(4, 9, 420);
    addTOGraph(4, 10, 240);
    addTOGraph(4, 11, 597);
    addTOGraph(4, 12, 1800);
    addTOGraph(4, 13, 1040);
    addTOGraph(4, 14, 213);
    // Dera Ghazi Khan Distance to all Cities
    addTOGraph(5, 6, 500);
    addTOGraph(5, 7, 440);
    addTOGraph(5, 8, 670);
    addTOGraph(5, 9, 270);
    addTOGraph(5, 10, 820);
    addTOGraph(5, 11, 1180);
    addTOGraph(5, 12, 1420);
    addTOGraph(5, 13, 460);
    addTOGraph(5, 14, 534);
    // Quetta Distance to all Cities
    addTOGraph(6, 7, 770);
    addTOGraph(6, 8, 710);
    addTOGraph(6, 9, 800);
    addTOGraph(6, 10, 1020);
    addTOGraph(6, 11, 1420);
    addTOGraph(6, 12, 916);
    addTOGraph(6, 13, 390);
    addTOGraph(6, 14, 1060);
    // Sargodha Distance to all Cities
    addTOGraph(7, 8, 1710);
    addTOGraph(7, 9, 230);
    addTOGraph(7, 10, 440);
    addTOGraph(7, 11, 800);
    addTOGraph(7, 12, 1850);
    addTOGraph(7, 13, 840);
    addTOGraph(7, 14, 360);
    // Hyderabad Distance to all Cities
    addTOGraph(8, 9, 890);
    addTOGraph(8, 10, 1430);
    addTOGraph(8, 11, 1800);
    addTOGraph(8, 12, 788);
    addTOGraph(8, 13, 310);
    addTOGraph(8, 14, 1140);
    // Sahiwal Distance to all Cities
    addTOGraph(9, 10, 610);
    addTOGraph(9, 11, 974);
    addTOGraph(9, 12, 1697);
    addTOGraph(9, 13, 678);
    addTOGraph(9, 14, 300);
    // Swat Distance to all Cities
    addTOGraph(10, 11, 504);
    addTOGraph(10, 12, 1980);
    addTOGraph(10, 13, 1220);
    addTOGraph(10, 14, 440);
    // Hunza Valley Distance to all Cities
    addTOGraph(11, 12, 2340);
    addTOGraph(11, 13, 1590);
    addTOGraph(11, 14, 800);
    // Gawadar Distance to all Cities
    addTOGraph(12, 13, 1060);
    addTOGraph(12, 14, 1960);
    // Larkana Distance to all Cities
    addTOGraph(13, 14, 920);
}

void travelling()
{

    int option;
    for (int i = 0; i < (sizeof travel / sizeof travel[0]); i++)
    {
        /* code */
        cout << "\n                              "
             << i + 1 << "." << travel[i] << "\n ";
    }
    cout << "\n                              Enter City from you depart: ";
    cin >> option;
    int choice;
    switch (option)
    {
    case 1:
        for (int i = 0; i < (sizeof travel / sizeof travel[0]); i++)
        {
            /* code */
            if (travel[i] != travel[0])
            {
                cout << "\n                              "
                     << i + 1 << ". " << travel[i] << "\n";
            }
        }
        cout << "\n                              Enter City you want to travel to: ";
        cin >> choice;
        last->travelFrom = travel[option - 1]; // Travel from
        last->travelTo = travel[choice - 1];   // Travel to
        last->distanceTravel = dijkstraAlgo((option - 1), (choice - 1));
        cout << "                              Shortest distance between " << travel[option - 1] << " and " << travel[choice - 1] << " is: " << last->distanceTravel;
        last->price = (last->distanceTravel) * 4;
        last->tax = (last->price * 10) / 100;
        last->price = last->price + last->tax;
        break;
    case 2:
        for (int i = 0; i < (sizeof travel / sizeof travel[0]); i++)
        {
            /* code */
            if (travel[i] != travel[1])
            {
                cout << "\n                              "
                     << i + 1 << ". " << travel[i] << "\n";
            }
        }
        cout << "\n                              Enter City you want to travel to: ";
        cin >> choice;
        last->travelFrom = travel[option - 1]; // Travel from
        last->travelTo = travel[choice - 1];   // Travel to
        last->distanceTravel = dijkstraAlgo((option - 1), (choice - 1));
        cout << "                              Shortest distance between " << travel[option - 1] << " and " << travel[choice - 1] << " is: " << last->distanceTravel << endl;
        last->price = (last->distanceTravel) * 4;
        last->tax = (last->price * 10) / 100;
        last->price = last->price + last->tax;
        break;
    case 3:
        for (int i = 0; i < (sizeof travel / sizeof travel[0]); i++)
        {
            /* code */
            if (travel[i] != travel[2])
            {
                cout << "\n                              "
                     << i + 1 << ". " << travel[i] << "\n";
            }
        }
        cout << "\n                              Enter City you want to travel to: ";
        cin >> choice;
        last->travelFrom = travel[option - 1]; // Travel from
        last->travelTo = travel[choice - 1];   // Travel to
        last->distanceTravel = dijkstraAlgo((option - 1), (choice - 1));
        cout << "                              Shortest distance between " << travel[option - 1] << " and " << travel[choice - 1] << " is: " << last->distanceTravel;
        last->price = (last->distanceTravel) * 4;
        last->tax = (last->price * 10) / 100;
        last->price = last->price + last->tax;
        break;
    case 4:
        for (int i = 0; i < (sizeof travel / sizeof travel[0]); i++)
        {
            /* code */
            if (travel[i] != travel[3])
            {
                cout << "\n                              "
                     << i + 1 << ". " << travel[i] << "\n";
            }
        }
        cout << "\n                              Enter City you want to travel to: ";
        cin >> choice;
        last->travelFrom = travel[option - 1]; // Travel from
        last->travelTo = travel[choice - 1];   // Travel to
        last->distanceTravel = dijkstraAlgo((option - 1), (choice - 1));
        cout << "                              Shortest distance between " << travel[option - 1] << " and " << travel[choice - 1] << " is: " << last->distanceTravel;
        last->price = (last->distanceTravel) * 4;
        last->tax = (last->price * 10) / 100;
        last->price = last->price + last->tax;
        break;
    case 5:
        for (int i = 0; i < (sizeof travel / sizeof travel[0]); i++)
        {
            /* code */
            if (travel[i] != travel[4])
            {
                cout << "\n                              "
                     << i + 1 << ". " << travel[i] << "\n";
            }
        }
        cout << "\n                              Enter City you want to travel to: ";
        cin >> choice;
        last->travelFrom = travel[option - 1]; // Travel from
        last->travelTo = travel[choice - 1];   // Travel to
        last->distanceTravel = dijkstraAlgo((option - 1), (choice - 1));
        cout << "                              Shortest distance between " << travel[option - 1] << " and " << travel[choice - 1] << " is: " << last->distanceTravel;
        last->price = (last->distanceTravel) * 4;
        last->tax = (last->price * 10) / 100;
        last->price = last->price + last->tax;
        break;
    case 6:
        for (int i = 0; i < (sizeof travel / sizeof travel[0]); i++)
        {
            /* code */
            if (travel[i] != travel[5])
            {
                cout << "\n                              "
                     << i + 1 << ". " << travel[i] << "\n";
            }
        }
        cout << "\n                              Enter City you want to travel to: ";
        cin >> choice;
        last->travelFrom = travel[option - 1]; // Travel from
        last->travelTo = travel[choice - 1];   // Travel to
        last->distanceTravel = dijkstraAlgo((option - 1), (choice - 1));
        cout << "                              Shortest distance between " << travel[option - 1] << " and " << travel[choice - 1] << " is: " << last->distanceTravel;
        last->price = (last->distanceTravel) * 4;
        last->tax = (last->price * 10) / 100;
        last->price = last->price + last->tax;
        break;
    case 7:
        for (int i = 0; i < (sizeof travel / sizeof travel[0]); i++)
        {
            /* code */
            if (travel[i] != travel[6])
            {
                cout << "\n                              "
                     << i + 1 << ". " << travel[i] << "\n";
            }
        }
        cout << "\n                              Enter City you want to travel to: ";
        cin >> choice;
        last->travelFrom = travel[option - 1]; // Travel from
        last->travelTo = travel[choice - 1];   // Travel to
        last->distanceTravel = dijkstraAlgo((option - 1), (choice - 1));
        cout << "                              Shortest distance between " << travel[option - 1] << " and " << travel[choice - 1] << " is: " << last->distanceTravel;
        last->price = (last->distanceTravel) * 4;
        last->tax = (last->price * 10) / 100;
        last->price = last->price + last->tax;
        break;
    case 8:
        for (int i = 0; i < (sizeof travel / sizeof travel[0]); i++)
        {
            /* code */
            if (travel[i] != travel[7])
            {
                cout << "\n                              "
                     << i + 1 << ". " << travel[i] << "\n";
            }
        }
        cout << "\n                              Enter City you want to travel to: ";
        cin >> choice;
        last->travelFrom = travel[option - 1]; // Travel from
        last->travelTo = travel[choice - 1];   // Travel to
        last->distanceTravel = dijkstraAlgo((option - 1), (choice - 1));
        cout << "                              Shortest distance between " << travel[option - 1] << " and " << travel[choice - 1] << " is: " << last->distanceTravel;
        last->price = (last->distanceTravel) * 4;
        last->tax = (last->price * 10) / 100;
        last->price = last->price + last->tax;
        break;
    case 9:
        for (int i = 0; i < (sizeof travel / sizeof travel[0]); i++)
        {
            /* code */
            if (travel[i] != travel[8])
            {
                cout << "\n                              "
                     << i + 1 << ". " << travel[i] << "\n";
            }
        }
        cout << "\n                              Enter City you want to travel to: ";
        cin >> choice;
        last->travelFrom = travel[option - 1]; // Travel from
        last->travelTo = travel[choice - 1];   // Travel to
        last->distanceTravel = dijkstraAlgo((option - 1), (choice - 1));
        cout << "                              Shortest distance between " << travel[option - 1] << " and " << travel[choice - 1] << " is: " << last->distanceTravel;
        last->price = (last->distanceTravel) * 4;
        last->tax = (last->price * 10) / 100;
        last->price = last->price + last->tax;
        break;
    case 10:
        for (int i = 0; i < (sizeof travel / sizeof travel[0]); i++)
        {
            /* code */
            if (travel[i] != travel[9])
            {
                cout << "\n                              "
                     << i + 1 << ". " << travel[i] << "\n";
            }
        }
        cout << "\n                              Enter City you want to travel to: ";
        cin >> choice;
        last->travelFrom = travel[option - 1]; // Travel from
        last->travelTo = travel[choice - 1];   // Travel to
        last->distanceTravel = dijkstraAlgo((option - 1), (choice - 1));
        cout << "                              Shortest distance between " << travel[option - 1] << " and " << travel[choice - 1] << " is: " << last->distanceTravel;
        last->price = (last->distanceTravel) * 4;
        last->tax = (last->price * 10) / 100;
        last->price = last->price + last->tax;
        break;
    case 11:
        for (int i = 0; i < (sizeof travel / sizeof travel[0]); i++)
        {
            /* code */
            if (travel[i] != travel[10])
            {
                cout << "\n                              "
                     << i + 1 << ". " << travel[i] << "\n";
            }
        }
        cout << "\n                              Enter City you want to travel to: ";
        cin >> choice;
        last->travelFrom = travel[option - 1]; // Travel from
        last->travelTo = travel[choice - 1];   // Travel to
        last->distanceTravel = dijkstraAlgo((option - 1), (choice - 1));
        cout << "                              Shortest distance between " << travel[option - 1] << " and " << travel[choice - 1] << " is: " << last->distanceTravel;
        last->price = (last->distanceTravel) * 4;
        last->tax = (last->price * 10) / 100;
        last->price = last->price + last->tax;
        break;
    case 12:
        for (int i = 0; i < (sizeof travel / sizeof travel[0]); i++)
        {
            /* code */
            if (travel[i] != travel[11])
            {
                cout << "\n                              "
                     << i + 1 << ". " << travel[i] << "\n";
            }
        }
        cout << "\n                              Enter City you want to travel to: ";
        cin >> choice;
        last->travelFrom = travel[option - 1]; // Travel from
        last->travelTo = travel[choice - 1];   // Travel to
        last->distanceTravel = dijkstraAlgo((option - 1), (choice - 1));
        cout << "                              Shortest distance between " << travel[option - 1] << " and " << travel[choice - 1] << " is: " << last->distanceTravel;
        last->price = (last->distanceTravel) * 4;
        last->tax = (last->price * 10) / 100;
        last->price = last->price + last->tax;
        break;
    case 13:
        for (int i = 0; i < (sizeof travel / sizeof travel[0]); i++)
        {
            /* code */
            if (travel[i] != travel[12])
            {
                cout << "\n                              "
                     << i + 1 << ". " << travel[i] << "\n";
            }
        }
        cout << "\n                              Enter City you want to travel to: ";
        cin >> choice;
        last->travelFrom = travel[option - 1]; // Travel from
        last->travelTo = travel[choice - 1];   // Travel to
        last->distanceTravel = dijkstraAlgo((option - 1), (choice - 1));
        cout << "                              Shortest distance between " << travel[option - 1] << " and " << travel[choice - 1] << " is: " << last->distanceTravel;
        last->price = (last->distanceTravel) * 4;
        last->tax = (last->price * 10) / 100;
        last->price = last->price + last->tax;
        break;
    case 14:
        for (int i = 0; i < (sizeof travel / sizeof travel[0]); i++)
        {
            /* code */
            if (travel[i] != travel[13])
            {
                cout << "\n                              "
                     << i + 1 << ". " << travel[i] << "\n";
            }
        }
        cout << "\n                              Enter City you want to travel to: ";
        cin >> choice;
        last->travelFrom = travel[option - 1]; // Travel from
        last->travelTo = travel[choice - 1];   // Travel to
        last->distanceTravel = dijkstraAlgo((option - 1), (choice - 1));
        cout << "                              Shortest distance between " << travel[option - 1] << " and " << travel[choice - 1] << " is: " << last->distanceTravel;
        last->price = (last->distanceTravel) * 4;
        last->tax = (last->price * 10) / 100;
        last->price = last->price + last->tax;
        break;
    case 15:
        for (int i = 0; i < (sizeof travel / sizeof travel[0]); i++)
        {
            /* code */
            if (travel[i] != travel[14])
            {
                cout << "\n                              "
                     << i + 1 << ". " << travel[i] << "\n";
            }
        }
        cout << "\n                              Enter City you want to travel to: ";
        cin >> choice;
        last->travelFrom = travel[option - 1]; // Travel from
        last->travelTo = travel[choice - 1];   // Travel to
        last->distanceTravel = dijkstraAlgo((option - 1), (choice - 1));
        cout << "                              Shortest distance between " << travel[option - 1] << " and " << travel[choice - 1] << " is: " << last->distanceTravel;
        last->price = (last->distanceTravel) * 4;
        last->tax = (last->price * 10) / 100;
        last->price = last->price + last->tax;
        break;
    }
}

void insert()
{
    if (isEmpty() == true)
    {
        distanceNode *current = new distanceNode();
        first = last = current;
        cout << "\n                              Enter Your Name: ";
        cin.ignore();
        getline(cin, last->name);
        cout << "\n                              Enter Cnic: ";
        cin >> last->cnic;
        travelling();
    }
    else
    {
        distanceNode *current = new distanceNode();
        current->previous = last;
        last->next = current;
        last = current;
        cout << "\n                              Enter Your Name: ";
        cin.ignore();
        getline(cin, last->name);
        cout << "\n                              Enter Cnic: ";
        cin >> last->cnic;
        travelling();
    }
}
void display()
{
    distanceNode *displayAllCustomer = first;

    int count = 1;
    cout << "                              ------------All Customer Till Now------------------" << endl;
    while (displayAllCustomer != NULL)
    {
        cout << "                              --------------------------------------------" << endl;
        cout << "                              --------------------------------------------" << endl;
        cout << "                              Customer " << count << endl;
        cout << "                              Name: " << displayAllCustomer->name << endl;
        cout << "                              Cnic Number: " << displayAllCustomer->cnic << endl;
        cout << "                              Departure from: " << displayAllCustomer->travelFrom << endl;
        cout << "                              Arrival At: " << displayAllCustomer->travelTo << endl;
        cout << "                              Total Price: " << displayAllCustomer->price << endl;
        cout << "                              Tax on Travelling: " << displayAllCustomer->tax << endl;
        cout << "                              Distance Travel: " << displayAllCustomer->distanceTravel << endl;
        cout << "                              --------------------------------------------" << endl;
        cout << "                              --------------------------------------------" << endl;
        count++;
        displayAllCustomer = displayAllCustomer->next;
    }
}
void displaySearchCustomer(string Cnic)
{
    bool choice = false;
    if (isEmpty())
    {
        cout << "\n                              No customer till now\n";
    }
    else
    {
        distanceNode *searchCustomer = first;
        while (searchCustomer != NULL)
        {
            if (searchCustomer->cnic == Cnic)
            {
                cout << "                              --------------------------------------------" << endl;
                cout << "                              --------------------------------------------" << endl;
                cout << "                              Name: " << searchCustomer->name << endl;
                cout << "                              Cnic Number: " << searchCustomer->cnic << endl;
                cout << "                              Departure from: " << searchCustomer->travelFrom << endl;
                cout << "                              Arrival At: " << searchCustomer->travelTo << endl;
                cout << "                              Total Price: " << searchCustomer->price << endl;
                cout << "                              Tax on Travelling: " << searchCustomer->tax << endl;
                cout << "                              Distance Travel: " << searchCustomer->distanceTravel << endl;
                cout << "                              --------------------------------------------" << endl;
                cout << "                              --------------------------------------------" << endl;
                choice = true;
            }
            searchCustomer = searchCustomer->next;
        }
    }
    if (choice == false)
    {
        cout << "\n                              --------------------Not Found--------------------\n";
    }
}
void WelcomingToTravelling()
{
    cout << "                              --------------Welcome to My Bus Travelling--------------------" << endl;
    cout << "                              --------------------------------------------------------------" << endl;
    int option;
    do
    {
        cout << "\n                              1.Enter Customer\n                              2.Display all Customers Tickets\n                              3.Search Specific Customer with CNIC\n                              4.Enter show Graph\n                                Enter 0 to stop\n                              Enter your choice ";
        string cnic;
        cin >> option;
        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            cout << "\n                              Enter Cnic of Customer: ";
            cin >> cnic;
            cin.ignore();
            displaySearchCustomer(cnic);
            break;
        case 4:
            cout << endl;
            displayGraph();
            cout << endl;
            break;
        default:
            break;
        }
    } while (option != 0 && option < 5);
    cout << "                              --------------------------------------------------------------";
}
/*







Pizza Delivery and Ordering services project starts from here.
All the Terms used in this project is beloow
int this i used Avl Tree  and A graph that provide the shortest distance
and A linked list Data Structure which hold All the delivered customers value




*/
int i = 0;
int y = 0;
long long array[10000];
string departure = "I-8";
int visitedPizza[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int distancesPizza[15] = {100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000};
int matrixGraphPizza[15][15];
string travelPizza[15] = {"I-8", "I-1", "I-2", "I-3", "I-4", "I-5", "I-6", "I-7", "F-1", "F-3", "F-2", "F-3", "F-4", "F-5", "F-6"};
void addTOGraphPizza(int i, int j, int weight)
{
    matrixGraphPizza[i][j] = weight;
    matrixGraphPizza[j][i] = weight;
}
void displayGraphPizza()
{
    for (int i = 0; i < 15; i++)
    {
        cout << "                              ";
        /* code */
        for (int j = 0; j < 15; j++)
        {
            /* code */
            cout << matrixGraphPizza[i][j] << "  ";
        }
        cout << endl;
    }
}
void initializedPizza(int matrixGraphPizza[][15])
{
    for (int i = 0; i < (sizeof visitedPizza / sizeof visitedPizza[0]); i++)
    {
        /* code */
        for (int j = 0; j < (sizeof visitedPizza / sizeof visitedPizza[0]); j++)
        {
            /* code */
            matrixGraphPizza[i][j] = 0;
        }
    }
}
bool isNotVisitedPizza()
{
    for (int i = 0; i < (sizeof visitedPizza / sizeof visitedPizza[0]); i++)
    {
        /* code */
        if (visitedPizza[i] == 0)
        {
            return true;
        }
    }
    return false;
}
int mininmumDiistancePizzaPizza()
{
    int min = 100000;
    int index;
    for (int i = 0; i < (sizeof visitedPizza / sizeof visitedPizza[0]); i++)
    {
        /* code */
        if (visitedPizza[i] == 0 && distancesPizza[i] < min)
        {
            min = distancesPizza[i];
            index = i;
        }
    }
    return index;
}
int dijkstraAlgoPizza(int source, int dep)
{
    int src = source;
    distancesPizza[source] = 0;
    while (isNotVisitedPizza())
    {
        source = mininmumDiistancePizzaPizza();

        visitedPizza[source] = 1;
        for (int j = 0; j < (sizeof visitedPizza / sizeof visitedPizza[0]); j++)
        {
            if (visitedPizza[j] == 0)
            {
                if (matrixGraphPizza[source][j] != 0)
                {
                    if (distancesPizza[j] > matrixGraphPizza[source][j] + distancesPizza[source])
                    {
                        distancesPizza[j] = matrixGraphPizza[source][j] + distancesPizza[source];
                    }
                }
            }
        }
    }
    return distancesPizza[dep];
}
void graphDistancePizza()
{

    initializedPizza(matrixGraphPizza);
    // Lahore Distance to all Cities
    addTOGraphPizza(0, 1, 3);
    addTOGraphPizza(0, 2, 4);
    addTOGraphPizza(0, 3, 9);
    addTOGraphPizza(0, 4, 11);
    addTOGraphPizza(0, 5, 2);
    addTOGraphPizza(0, 6, 15);
    addTOGraphPizza(0, 7, 1);
    addTOGraphPizza(0, 8, 8);
    addTOGraphPizza(0, 9, 7);
    addTOGraphPizza(0, 10, 6);
    addTOGraphPizza(0, 11, 10);
    addTOGraphPizza(0, 12, 5);
    addTOGraphPizza(0, 13, 30);
    addTOGraphPizza(0, 14, 40);
    // Karachi Distance to all Cities
    addTOGraphPizza(1, 2, 1);
    addTOGraphPizza(1, 3, 2);
    addTOGraphPizza(1, 4, 6);
    addTOGraphPizza(1, 5, 2);
    addTOGraphPizza(1, 9, 4);
    addTOGraphPizza(1, 10, 7);
    addTOGraphPizza(1, 11, 9);
    addTOGraphPizza(1, 13, 10);
    addTOGraphPizza(1, 14, 13);
    // Peshawar Distance to all Cities
    addTOGraphPizza(2, 3, 5);
    addTOGraphPizza(2, 4, 1);
    addTOGraphPizza(2, 5, 2);
    addTOGraphPizza(2, 8, 9);
    addTOGraphPizza(2, 9, 7);
    addTOGraphPizza(2, 11, 6);
    addTOGraphPizza(2, 12, 18);
    addTOGraphPizza(2, 13, 11);
    // Multan Distance to all Cities
    addTOGraphPizza(3, 4, 10);
    addTOGraphPizza(3, 5, 8);
    addTOGraphPizza(3, 6, 5);
    addTOGraphPizza(3, 7, 6);
    addTOGraphPizza(3, 9, 17);
    addTOGraphPizza(3, 10, 16);
    addTOGraphPizza(3, 12, 14);
    addTOGraphPizza(3, 14, 4);
    // Islamabad\Faizabad Distance to all Cities
    addTOGraphPizza(4, 5, 10);
    addTOGraphPizza(4, 7, 15);
    addTOGraphPizza(4, 8, 16);
    addTOGraphPizza(4, 9, 20);
    addTOGraphPizza(4, 11, 21);
    addTOGraphPizza(4, 13, 14);
    addTOGraphPizza(4, 14, 11);
    // Dera Ghazi Khan Distance to all Cities
    addTOGraphPizza(5, 6, 10);
    addTOGraphPizza(5, 7, 14);
    addTOGraphPizza(5, 9, 17);
    addTOGraphPizza(5, 10, 19);
    addTOGraphPizza(5, 11, 25);
    addTOGraphPizza(5, 12, 20);
    addTOGraphPizza(5, 13, 16);
    // Sargodha Distance to all Cities
    addTOGraphPizza(6, 7, 10);
    addTOGraphPizza(6, 8, 15);
    addTOGraphPizza(6, 9, 19);
    addTOGraphPizza(6, 10, 26);
    addTOGraphPizza(6, 11, 20);
    addTOGraphPizza(6, 12, 30);
    addTOGraphPizza(6, 13, 29);
    // Hyderabad Distance to all Cities
    addTOGraphPizza(7, 8, 17);
    addTOGraphPizza(7, 9, 29);
    addTOGraphPizza(7, 10, 14);
    addTOGraphPizza(7, 11, 10);
    addTOGraphPizza(7, 12, 18);
    addTOGraphPizza(7, 13, 32);
    addTOGraphPizza(7, 14, 36);
    // Sahiwal Distance to all Cities
    addTOGraphPizza(8, 10, 30);
    addTOGraphPizza(8, 11, 38);
    addTOGraphPizza(8, 12, 28);
    addTOGraphPizza(8, 13, 21);
    addTOGraphPizza(8, 14, 32);
    // Swat Distance to all Cities
    addTOGraphPizza(9, 10, 26);
    addTOGraphPizza(9, 11, 17);
    addTOGraphPizza(9, 12, 29);
    addTOGraphPizza(9, 13, 36);
    addTOGraphPizza(9, 14, 33);
    // Hunza Valley Distance to all Cities
    addTOGraphPizza(10, 11, 14);
    addTOGraphPizza(10, 13, 22);
    addTOGraphPizza(10, 14, 34);
    // Gawadar Distance to all Cities
    addTOGraphPizza(11, 12, 23);
    addTOGraphPizza(11, 13, 15);
    addTOGraphPizza(11, 14, 28);
    // Larkana Distance to all Cities
    addTOGraphPizza(12, 13, 10);
    addTOGraphPizza(12, 14, 19);
    // Sialkot Distance to all Cities
    addTOGraphPizza(13, 14, 21);
}
struct Customer
{
    string name;
    long long cnic;
    string travelTo;
    int numberOfOrder;
    string pizzadata;
    int price;
    int distanceTravel;
    int deliveryCharges;
    int TotalPrice;
    Customer *next1;
    Customer *previous1;
};
Customer *firstPizzaNode = NULL;
Customer *lastPizzaNode = NULL;
struct Node
{
    string name;
    long long cnic;
    string customerLocation;
    int numberOfOrder;
    string *pizzaList;
    int *pizzaPrices;
    string pizzaData;
    int pizzaPriceTotal;
    Node *right = NULL;
    Node *left = NULL;
};
Node *deletedNode = NULL;
bool isEmptyCustomer()
{
    if (firstPizzaNode == NULL && lastPizzaNode == NULL)
    {
        return true;
    }
    return false;
}
Node *createNode()
{
    string pizzaMenu[] = {"Chicken Tikka Pizza", "Chicken Fajita Pizza", "Cheesy Pizza", "Veggie Pizza", "Fajita Sicilian", "BBQ Pizza", "Pepperoni Pizaa", "Peri-peri Pizza", "Malai Boti Pizza", "Chicken Supreme Pizza", "Hot & Spicy Pizza", "Afghani Pizza"};
    int pricesOfPizza[] = {900, 1030, 1100, 760, 880, 1200, 790, 930, 1250, 1600, 1500, 1240};
    Node *current = new Node();
    cout << "\n                              Enter your Name: ";
    cin.ignore();
    getline(cin, current->name);
    cout << "\n                              Enter Customer Cnic Number: ";
    cin >> current->cnic;
    array[i] = current->cnic;
    i++;
    int v;
    for (int i = 1; i < (sizeof travelPizza / sizeof travelPizza[0]); i++)
    {
        /* code */
        cout << "                              " << (i + 1) << ". " << travelPizza[i] << endl;
    }
    cout << "\n                              Enter Your Location: ";
    cin >> v;
    current->customerLocation = travelPizza[(v - 1)];
    cout << "\n                              Enter Number of Order You want to place: ";
    cin >> current->numberOfOrder;
    cout << "\n                              1.Chicken Tikka Pizza\n                              2.Chicken Fajita Pizza\n                              3.Cheesy Pizza\n                              4.Veggie Pizza\n                              5.Fajita Sicilian\n                              6.BBQ Pizza\n                              7.Pepperoni Pizaa\n                              8.Peri-peri Pizza\n                              9.Malai Boti Pizza\n                              10.Chicken Supreme Pizza\n                              11.Hot & Spicy Pizza\n                              12.Afghani Pizza ";
    int numberOfOrder = current->numberOfOrder;
    current->pizzaList = new string[numberOfOrder];
    current->pizzaPrices = new int[numberOfOrder];
    int value;
    for (int i = 0; i < numberOfOrder; i++)
    {
        /* code */
        cout << "\n                              Order Pizza Number " << (i + 1) << ": ";
        cin >> value;
        current->pizzaList[i] = pizzaMenu[(value - 1)];
        current->pizzaPrices[i] = pricesOfPizza[(value - 1)];
    }
    cout << endl;
    // idhr change krna hai ??.xdd
    for (size_t i = 0; i < numberOfOrder; i++)
    {
        /* code */
        cout << (i + 1) << ". " << current->pizzaList[i] << endl;
    }
    int choice;
    do
    {
        cout << "Enter which (Value) pizza you want to cancel: ";
        cin >> choice;
        current->pizzaList[choice] = "Order Cancel for This pizza";
        current->pizzaPrices[choice] = 0;
        cout << "Enter 0 to stop cancelling" << endl;
    } while (choice != 0);

    for (int i = 0; i < numberOfOrder; i++)
    {
        current->pizzaPriceTotal = current->pizzaPriceTotal + current->pizzaPrices[i];
        current->pizzaData = current->pizzaData + "\n                              " + to_string(i + 1) + ". " + current->pizzaList[i] + " Price: " + to_string(current->pizzaPrices[i]) + "\n";
    }
    cout << "\n"
         << current->pizzaData << endl;
    return current;
}
void customerData(Node *p)
{
    if (p == NULL)
    {
        return;
    }
    else if (isEmptyCustomer() == true)
    {
        Customer *current = new Customer();
        current->name = p->name;
        current->cnic = p->cnic;
        current->travelTo = p->customerLocation;
        current->numberOfOrder = p->numberOfOrder;
        current->pizzadata = p->pizzaData;
        current->price = p->pizzaPriceTotal;
        firstPizzaNode = lastPizzaNode = current;
        int dep = 0;
        for (int i = 0; i < (sizeof travelPizza / sizeof travelPizza[0]); i++)
        {
            /* code */
            if (current->travelTo == travelPizza[i])
            {
                dep = i;
            }
        }
        current->distanceTravel = dijkstraAlgoPizza(0, dep);
        current->deliveryCharges = current->distanceTravel * 4;
        current->TotalPrice = current->price + current->deliveryCharges;
        deletedNode = NULL;
    }
    else
    {
        Customer *current = new Customer();
        current->name = p->name;
        current->cnic = p->cnic;
        current->travelTo = p->customerLocation;
        current->numberOfOrder = p->numberOfOrder;
        current->pizzadata = p->pizzaData;
        current->price = p->pizzaPriceTotal;
        current->previous1 = lastPizzaNode;
        lastPizzaNode->next1 = current;
        lastPizzaNode = current;
        int dep = 0;
        for (int i = 0; i < (sizeof travelPizza / sizeof travelPizza[0]); i++)
        {
            /* code */
            if (current->travelTo == travelPizza[i])
            {
                dep = i;
            }
        }
        current->distanceTravel = dijkstraAlgoPizza(0, dep);
        current->deliveryCharges = current->distanceTravel * 4;
        current->TotalPrice = current->price + current->deliveryCharges;
        deletedNode = NULL;
    }
}
void displayAllCustomerWhichAreServed()
{
    Customer *displayAllCustomer = firstPizzaNode;
    int count = 1;
    cout << "                              ------------All Customer Till Now------------------" << endl;
    while (displayAllCustomer != NULL)
    {
        cout << "                              " << endl;
        cout << "                              --------------------------------------------" << endl;
        cout << "                              --------------------------------------------" << endl;
        cout << "                              Customer " << count << endl;
        cout << "                              Name: " << displayAllCustomer->name << endl;
        cout << "                              Cnic Number: " << displayAllCustomer->cnic << endl;
        cout << "                              Departure from: New Yorker Pizza : Location: " << departure << endl;
        cout << "                              Deliver To Location: " << displayAllCustomer->travelTo << endl;
        cout << "                              Price Of Pizzas: " << displayAllCustomer->price << endl;
        cout << "                              Delivery Charges: " << displayAllCustomer->deliveryCharges << endl;
        cout << "                              Distance Travel: " << displayAllCustomer->distanceTravel << endl;
        cout << "                              Total Order: " << displayAllCustomer->numberOfOrder << endl;
        cout << "                              PizzaS Deliver\n"
             << displayAllCustomer->pizzadata << endl;
        cout << "                              Total Price: " << displayAllCustomer->TotalPrice << endl;
        cout << "                              --------------------------------------------" << endl;
        cout << "                              --------------------------------------------" << endl;
        count++;
        displayAllCustomer = displayAllCustomer->next1;
    }
}
int height(Node *p)
{
    if (p == NULL)
        return -1;
    else
    {
        int leftHeight = height(p->left);
        int rightHeight = height(p->right);
        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}
int getBalanceFactor(Node *p)
{
    if (p == NULL)
        return 0;
    return (height(p->left) - height(p->right));
}
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *t2 = y->left;
    y->left = x;
    x->right = t2;
    return y;
}
Node *balance(Node *r, Node *newNode)
{
    int balanceFactor = getBalanceFactor(r);
    // Left Left rotation
    if (balanceFactor > 1 && newNode->cnic < r->left->cnic)
        return rightRotate(r);
    // Right Right Rotation
    if (balanceFactor < -1 && newNode->cnic > r->right->cnic)
        return leftRotate(r);
    // Left Right Rotation
    if (balanceFactor > 1 && newNode->cnic > r->left->cnic)
    {
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }
    // Right Left Rotation
    if (balanceFactor < -1 && newNode->cnic < r->right->cnic)
    {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }
    return r;
}
Node *minValueNode(Node *node)
{
    Node *current = node;
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
void searchNode(Node *p, long long v)
{
    if (p == NULL)
    {
        return;
    }
    searchNode(p->left, v);
    if (p->cnic == v)
    {
        deletedNode = new Node();
        deletedNode->name = p->name;
        deletedNode->cnic = p->cnic;
        deletedNode->numberOfOrder = p->numberOfOrder;
        int numberOfOrder = p->numberOfOrder;
        deletedNode->pizzaList = new string[numberOfOrder];
        deletedNode->pizzaPrices = new int[numberOfOrder];
        for (int i = 0; i < numberOfOrder; i++)
        {
            /* code */
            p->pizzaList[i] = deletedNode->pizzaList[i];
            p->pizzaPrices[i] = deletedNode->pizzaPrices[i];
        }
        deletedNode->pizzaPriceTotal = p->pizzaPriceTotal;
        deletedNode->customerLocation = p->customerLocation;
        deletedNode->pizzaData = p->pizzaData;
    }
    searchNode(p->right, v);
}
Node *deliverPizzaToCustomer(Node *r, long long v)
{
    // base case
    if (r == NULL)
    {
        return NULL;
    }
    // If the cnic to be deleted is smaller than the root's cnic,
    // then it lies in left subtree
    else if (v < r->cnic)
    {
        r->left = deliverPizzaToCustomer(r->left, v);
    }
    // If the cnic to be deleted is greater than the root's cnic,
    // then it lies in right subtree
    else if (v > r->cnic)
    {
        r->right = deliverPizzaToCustomer(r->right, v);
    }
    // if cnic is same as root's cnic, then This is the node to be deleted
    else
    {
        // node with only one child or no child
        if (r->left == NULL)
        {
            Node *temp = r->right;
            delete r;
            return temp;
        }
        else if (r->right == NULL)
        {
            Node *temp = r->left;
            delete r;
            return temp;
        }
        else
        {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            Node *temp = minValueNode(r->right);
            // Copy the inorder successor's content to this node
            r->cnic = temp->cnic;
            // Delete the inorder successor
            r->right = deliverPizzaToCustomer(r->right, temp->cnic);
            // deliverPizzaToCustomer(r->right, temp->cnic);
        }
    }

    int bf = getBalanceFactor(r);
    // Left Left Imbalance/Case or Right rotation
    if (bf == 2 && getBalanceFactor(r->left) >= 0)
        return rightRotate(r);
    // Left Right Imbalance/Case or LR rotation
    else if (bf == 2 && getBalanceFactor(r->left) == -1)
    {
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }
    // Right Right Imbalance/Case or Left rotation
    else if (bf == -2 && getBalanceFactor(r->right) <= -0)
        return leftRotate(r);
    // Right Left Imbalance/Case or RL rotation
    else if (bf == -2 && getBalanceFactor(r->right) == 1)
    {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }
    cout << "\n                              Deleted Cnic " << v;

    return r;
}

Node *insert(Node *r, Node *newNode)
{
    if (r == NULL)
    {
        r = newNode;
        cout << "\n                              Pizza Ordered successfully\n";
        return r;
    }
    if (newNode->cnic > r->cnic)
        r->right = insert(r->right, newNode);
    else if (newNode->cnic < r->cnic)
        r->left = insert(r->left, newNode);
    else
    {
        cout << "                              Duplicate cnic can't be Used\n";
        return r;
    }
    r = balance(r, newNode);
    return r;
}
void inOrderTraversal(Node *p)
{
    if (p == NULL)
    {
        return;
    }
    inOrderTraversal(p->left);
    cout << p->cnic << "                              \n";
    inOrderTraversal(p->right);
}
void PizzaOrderingAndDeliveringServices()
{
    Node *r = NULL;
    int option;
    cout << "                             WELCOME TO PIZZA ORDER / DELIVER SERVICES" << endl;
    do
    {
        cout << "\n                              1.Ordering\n                              2.Delivery\n                              3.Pending Customers \n                              4.Customer Deliver Till Now\n                              5.Display Graph For Delivery Boy\n                              Enter 0 to Stop\n                              Enter your choice : ";
        cin >> option;
        switch (option)
        {
        case /* constant-expression */ 1:
            r = insert(r, createNode());
            /* code */
            break;
        case 2:
            searchNode(r, array[y]);
            customerData(deletedNode);
            r = deliverPizzaToCustomer(r, array[y]);
            if (r != NULL)
            {
                cout << "\n                              Pizza Delivered Succesfully\n";
                y++;
            }

            break;
        case 3:
            cout << "\n                              All Pending Pizzas Customer Id's: ";
            inOrderTraversal(r);
            cout << endl;
            break;
        case 4:
            cout << endl;
            displayAllCustomerWhichAreServed();
            cout << endl;
            break;
        case 5:
            cout << endl;
            displayGraphPizza();
            cout << endl;
            break;
        default:
            break;
        }
    } while (option != 0);
}

int main()
{
    graphDistance();
    graphDistancePizza();
    cout << "\n                              Welcome To My DSA Simple Project \n\n";
    int option;
    do
    {
        cout << "\n                              1.Pizza Ordering/Delivery Services\n                              2.Travelling/Services\n                              3.Enter 0 to stop\n                              Enter Your choice: ";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << endl;
            PizzaOrderingAndDeliveringServices();
            cout << endl;
            break;
        case 2:
            cout << endl;
            WelcomingToTravelling();
            cout << endl;
            break;
        }
    } while (option != 0 && option < 3);
    return 0;
}