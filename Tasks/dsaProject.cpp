#include<iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;
//======================================GLOBAL VARIABLES==========================================================
const int INF = 1000;
string dest;
vector<int>gph[7];
int graph[7][7];
int graphtime[7][7];
string cities[7] = {"Lahore","Multan","Islamabad","Karachi","Peshawar","Gujrat","Sialkot"};
int visited[7];
int parent[7];
int source;
string start =cities[source];
//================================BASIC IMPLEMENTATION OF GRAPHS==================================================
void add_edge(vector<int>gph[],int u,int v){
    gph[u].push_back(v);
    gph[v].push_back(u);
}
void addEdgeDistance(int v1, int v2, int w){
		graph[v1][v2] = w;
		graph[v2][v1] = w;				
}
void addEdgeTime(int v1, int v2, int w){
		graphtime[v1][v2] = w;
		graphtime[v2][v1] = w;				
}
void display(){
	cout<<"\n------GRAPH------\n";
	for (int i= 0; i<7; i++){
		cout<<"  ";
		for (int j=0; j<7;j++){
				cout<<graph[i][j]<<" ";	
		}
		cout<<"\n";	
	}
	cout<<"-----------------\n";	
}
//===========================================STACK CLASS==================================================================
class sta{
	public:
		int size, top;
		string *s;
	sta(){
		size=10;
		s=new string[size];
		top=-1;
	}

	void push(string x){
		s[++top]=x;						
	}		
	string pop(){
		string x = s[top--];
		return x;
	}
	bool isEmpty(){
		if(top==-1)
			return true;
		else
			return false;
	}
	void display(){
		for(int i=top; i>=0; i--){
				cout<<"\n"<<s[i];
		}
		cout<<"\n";
	}
};
//=====================================DIJKSTRA ALGORITHM===========================================================

// finds and displays the shortest route to each city from the source

void displayShortestPath(int distance[], int parent[],int source, string unit){
	cout<<"\n--------------------Shortest Routes to All Cities---------------------\n\n";
	int j;
	sta s1;									// Stack is used in printing of path in Dijkstra's Algorithm
	for(int i=0;i<7;i++){
		if(i!=source){
			s1.push(cities[i]);
			j=i;
			do{
				j=parent[j];
				s1.push(cities[j]);
			}while(j!=source);
		}
		while(!s1.isEmpty()){
			cout<<s1.pop()<<" --> ";
		}		
		if (i!=source){
			cout<<distance[i]<<" "<<unit<<"\n\n";	
		}
	}
	cout<<"\n------------------------------------------------------------------------\n";
}

int minDistance(int distance[], int visited[]){
	int min = INF; 									// Finds the vertex with minimum distance from all those vertices which are unvisited
	int minIndex;
	for (int i = 0; i < 7; i++)
		if (visited[i] == false && distance[i] <= min){
			min = distance[i], minIndex = i;
		}
	return minIndex;
}

void dijkstrasAlgorithm(int graph[][7],int distance[], int visited[], int parent[],int source,string unit){

	for(int i = 0; i < 7; i++){
		distance[i] = INF;
		visited[i] = 0;
		parent[i] = -1;
	}
	distance[source] = 0;

	for (int i = 0; i < 6; i++) {
		int u = minDistance(distance, visited);		
		visited[u] = 1;
		for (int i = 0; i < 7; i++){
			if (visited[i] == 0 && graph[u][i]){
				if (distance[u] + graph[u][i] < distance[i]){
					distance[i] = distance[u] + graph[u][i];	
					parent[i] = u;
				}
			}
		}
	}
	displayShortestPath(distance,parent,source,unit);
}

//===================================LINKED LISTS OF ROUTES========================================================

// displays all routes available from the source city
// constructs linked lists of direct and indirect routes 

struct linkedRoutes{               // indirect routes from your city 
	string departure, destination;
	int distance;
	linkedRoutes *rrnext = NULL;	
};
struct routesFromSource{           // direct routes from your city
	string departure, destination;
	int distance; 
	int route;
	routesFromSource *next = NULL;
	linkedRoutes *rnext = NULL;
};

routesFromSource *rfirst = NULL;
routesFromSource *rlast = NULL;


void addRouteFromSource(int x, int y,int r){
	routesFromSource *curr = new routesFromSource;
	curr->departure = cities[x];
	curr->destination = cities[y];
	curr->distance = graph[x][y];
	curr->route = r;
	
	if (rfirst==NULL){
		rfirst=rlast=curr;
	}
	else{
		rlast->next=curr;
		rlast =  curr;
	}
}
routesFromSource * searchRoute(string dep){
	routesFromSource *p = rfirst;
	while(p!=NULL && ((p->destination).compare(dep)!=0)){
		p=p->next;
	}
	return p;
}
routesFromSource * searchRouteForFlight(int route){
	routesFromSource *p = rfirst;
	while(p!=NULL && p->route!=route){
		p=p->next;
	}
	return p;
}
linkedRoutes * searchAllRoutes(string dep){
	routesFromSource *p = rfirst;
	linkedRoutes *q;
	bool flag = false;
	while(p!=NULL){
		q = p->rnext;
		while(q!=NULL){
			if((q->destination).compare(dep)==0){
				flag = true;
				break;
			}
			else{
				q=q->rrnext;	
			}
		}
		if (flag){
			break;
		}
		else{
			p=p->next;	
		}
	}
	return q;
}
void addLinkedRoutes(int x, int y){
	linkedRoutes *curr = new linkedRoutes;
	curr->departure = cities[x];
	curr->destination = cities[y];
	curr->distance = graph[x][y];
	routesFromSource *p = searchRoute(curr->departure);

	if (p!=NULL){
		curr->rrnext = p->rnext;
		p->rnext = curr;
	}
	else{
		linkedRoutes *q = searchAllRoutes(curr->departure);
		curr->rrnext = q->rrnext;
		q->rrnext = curr;
	}
}

void displayRoutesFromSource(){
	routesFromSource *p=rfirst;
	while(p!=NULL){
		cout<<"\n---------------Route "<<p->route<<"-----------------\n";
		cout<<"\tDeparture  : "<<p->departure<<"\n";
		cout<<"\tDestination: "<<p->destination<<"\n";
		cout<<"\tDistance   : "<<p->distance<<"\n";
		linkedRoutes *q = p->rnext;
		while(q!=NULL){
			cout<<"\n\tDeparture  : "<<q->departure<<"\n";
			cout<<"\tDestination: "<<q->destination<<"\n";
			cout<<"\tDistance   : "<<q->distance<<"\n";	
			q=q->rrnext;		
		}
		p=p->next;
	}
	cout<<"\n-----------------------------------------------\n";
}
//======================================ALL EDGES============================================================
void printpath(vector<int>path) //Print Edges
{
    int size = path.size();
    for (int i = 0; i < size; i++)
         if(i==size-1){
            cout << cities[path[i]] <<" ";
        }   
        else{
            cout << cities[path[i]] <<"--->";
        }  
    cout << "\n\n";
}
int isNotVisited(int x, vector<int> path) //Checking if Vertices are visited or not 
{
    int size = path.size();
    for (int i = 0; i < size; i++)
        if (path[i] == x)
            return 0;
    return 1;
}

void findpaths(vector<int>g[], int source,int destination, int v) //Through BFS
{
    queue<vector<int> > q;
    vector<int> path;
    path.push_back(source);
    q.push(path);
    while (!q.empty()) {
        path = q.front();
        q.pop();
        int last = path[path.size() - 1];
        if (last == destination)
            printpath(path);       

        for (int i = 0; i < g[last].size(); i++) {
            if (isNotVisited(g[last][i], path)) {
                vector<int> newpath(path);
                newpath.push_back(g[last][i]);
                q.push(newpath);
            }
        }
    }
}

//======================================PRIMS ALGORITHM============================================================

// creates the minimum spanning tree from graph of cities

bool finish(){
	bool flag = true;
	for (int i=0; i<7;i++){
		if (visited[i] == 0){
			flag = false;
		}
	}
	return flag;
}
void prims(int source){           
	int cost=0;
  	for (int i=0;i<7;i++){
		visited[i] = 0;			
  	}
	visited[source] = 1;
	int rt = 1;
	while (!finish()) {	
		int min = INF;
		int x;
		int y;	
		for (int i = 0; i < 7; i++) {
		  if (visited[i]) {
		    for (int j = 0; j < 7; j++) {
		      if (graph[i][j] && visited[j]==0) {
		        if (graph[i][j] < min) {
		          min = graph[i][j];
		          x = i;
		          y = j;
		        }
		      }
		    }
		  }
		}
	//	cout << "Cost of " << cities[x] << " --> " << cities[y]<< " :  " << graph[x][y]<<"\n";
		if ((cities[x]).compare(start)==0){
			addRouteFromSource(x,y,rt);
			rt++;	
		}
		else{
			addLinkedRoutes(x,y);
		}
		visited[y] = 1;
		cost += graph[x][y];
	}
	cout<<"\nTotal Cost of Minimum Spanning Tree: "<<cost<<" km\n";
}
//============================LINKED LISTS OF PLANES AND PASSANGERS================================================

struct passanger{
    string pass_name;
    string departure;
    string destination;
    string seat;
    passanger* ppnext=NULL;
};
struct plane{
    int id;
    string departure;
    string destination;
    int countOfPassangers;
    double oneTicketCost;
    plane* next=NULL;
    passanger* pnext=NULL;
};

plane* first=NULL;
plane* last=NULL;

// Maximum Capacity of each PLane = 5

int count(plane *p){           // counts and returns the number of Passangers in each Plane
	passanger *q = p->pnext;
	int ct = 0;
	if (p->pnext==NULL){
		return 0;
	}
	else{
		while(q!=NULL){
			ct++;
			q=q->ppnext;
		}
		return ct;
	}
}
void registerPlane(){
	 
	routesFromSource *p = rfirst;
	while(p!=NULL){

	    plane* curr=new plane;
		
		curr->id = p->route;
		curr->departure = p->departure;
		curr->destination = p->destination;
	 	curr->oneTicketCost = (p->distance)*(100);
	 	curr->countOfPassangers = count(curr);
	
	    if(first==NULL){
	        first=last=curr;
	    }
	    else{
	        last->next=curr;
	        last=curr;	
		}
		p=p->next;
	}
}
plane* searchPlaneByDepDes(string dep, string des){
    plane* p=first;
    while(p!=NULL){
    	if (((p->departure).compare(dep)==0)&&((p->destination).compare(des)==0)){
    		break;
		}
		else{
        	p=p->next;			
		}
    }
    return p;
}
void insertPassangers(){
    passanger* pcurr=new passanger;
    cout<<"\nName of Passanger: ";
    cin>>pcurr->pass_name;
    cout<<"Departure: ";
	cin>>pcurr->departure;
	cout<<"Destination: ";
	cin>>pcurr->destination;
	cout<<"Seat: ";
	cin>>pcurr->seat;
	
	plane *q = searchPlaneByDepDes(pcurr->departure, pcurr->destination);
	  
    if (q->countOfPassangers<5){
	    if(q==NULL){
	        cout<<"\nThis route does not exist...\n\n";
	    }
	    else{
	        if(q->pnext==NULL){
	            q->pnext=pcurr;
	        }
	        else{
	        	if ((pcurr->seat).compare("luxury")==0){
		            pcurr->ppnext=q->pnext;
		            q->pnext=pcurr;        		
				}
				else{
					passanger *ptr = q->pnext;
		            while(ptr->ppnext!=NULL){
		                ptr=ptr->ppnext;
		            }
		            ptr->ppnext = pcurr;	
				}
	        }
	    }
		q->countOfPassangers = count(q);  	
	}
	else{
		cout<<"\nNo seats available in this PLane...\n\n";
	}
}
void displayPlanes(){
    plane* p=first;
    if(p==NULL){
        cout<<"\nNo Plane is Scheduled...\n\n";
    }
    else{
    	cout<<"\n------------------Plane Details------------------------\n";
        while(p!=NULL){
            cout<<"\n\tPlane Route     : "<<p->id<<endl;
            cout<<"\tDeparture       : "<<p->departure<<endl;
            cout<<"\tDestination     : "<<p->destination<<endl;
            cout<<"\tTotal Passangers: "<<p->countOfPassangers<<endl;
            cout<<"\tCost of 1 Ticket: "<<p->oneTicketCost<<endl;
            cout<<"\n";
		    p=p->next;
        }
        cout<<"\n-----------------------------------------------------\n\n";
    }
}
plane* searchPlaneByRoute(int route){
    plane* p=first;
    while(p!=NULL && p->id!=route){
        p=p->next;			
		
    }
    return p;
}

void displayPassangers(){
    int route;
    cout<<"\nEnter Route  : ";
    cin>>route;
    plane *p=searchPlaneByRoute(route);
    passanger* r=p->pnext;
    if(r==NULL){
        cout<<"\nNo Passangers yet...\n";
    }
    else{
    	cout<<"\n==================Passangers in Plane "<<p->id<<"=======================\n\n";
        while(r!=NULL){
            cout<<"\tPassanger Name: "<<r->pass_name<<"\n";
            cout<<"\tDeparture     : "<<r->departure<<"\n";
            cout<<"\tDestination   : "<<r->destination<<"\n";
            cout<<"\tPassanger Seat: "<<r->seat<<"\n\n";
            r=r->ppnext;
        }
        cout<<"\n=======================================================================\n";
    }
}
passanger * searchPassanger(plane *p,string name){
	passanger *q = p->pnext;
	while(q!=NULL){
		if (((q->pass_name).compare(name)==0)){
			break;
		}
		else{
			q=q->ppnext;			
		}
	}
	return q;
}
void cancelBooking(){
	string pass_name;
	int r;
	cout<<"\n============= Cancel Booking =================\n\n";
	cout<<"\tPassanger Name: ";
	cin>>pass_name;
	cout<<"\tFlight Route  : ";
	cin>>r;
	plane *p = searchPlaneByRoute(r);    //search the plane for which this booking exists
	passanger *q = p->pnext;

	if(p==NULL){
		cout<<"\nNo such route exists...\n\n";    //if no such plane exists
	}
	else{
		if(p->pnext==NULL){											//if there is no booking for the plane your searched
			cout<<"\nThere is no booking for this plane...\n\n";  
		}
		else{
			passanger *a = searchPassanger(p,pass_name);   //search for the specific passanger you wantto delete in plane 'p'
			passanger *prev = q;
			while(q!=NULL && q!=a){
				prev=q;
				q=q->ppnext;
			}
			if (a==NULL){									//if no such passanger exists
				cout<<"\nNo such Booking exists...\n\n";
			}	
			else if(p->pnext==a && a->ppnext==NULL){		//if there is only one passanger in plane
				p->pnext = NULL;
				delete(a);
			}
			else if(p->pnext==a){							//if you want to delete the first passanger
				p->pnext = a->ppnext;
				delete(a);
			}
			else if(a->ppnext==NULL){						//if you want to delete the last passanger
				prev->ppnext = NULL;
				delete(a);
			}
			else{											//if you want to delete a passanger from between the list
				prev->ppnext = a->ppnext;
				delete(a);
			}
		}
	}
	p->countOfPassangers = count(p);
	cout<<"\nYour Booking is Cancelled...\n\n";
	cout<<"\n===============================================\n";
	
	
}

//==========================================CALCULATES REVENUE GENERATED==================================================

double calculateTotalRevenueOfPlane(plane *p){
	return (p->countOfPassangers * p->oneTicketCost);
			
}
void revenueOfSpecificPlane(){
	cout<<"\n================Revenue of a Specific Flight=================\n";
	int r;
	cout<<"\nEnter the route: ";
	cin>>r;

	plane *p = searchPlaneByRoute(r);
	if(p==NULL){
		cout<<"\nNo such route exists...\n\n";
	}
	else{
		cout<<"\nTotal revenue generated by Plane "<<p->id<<": $"<<calculateTotalRevenueOfPlane(p);	
	}
	cout<<"\n\n=============================================================\n";
}
void revenueOfAllPlanes(){
	cout<<"\n====================Revenue Of All Flights=====================\n";
	if(first==NULL){
		cout<<"\nNo Planes are Registered, no revenue is generated yet...\n";
	}
	else{
		plane *p=first;
		double sum=0;
		while(p!=NULL){
			sum += calculateTotalRevenueOfPlane(p);
			p=p->next;		
		}

		cout<<"\nTotal revenue generated by all Planes: $"<<sum<<"\n";
	}
	cout<<"\n==============================================================\n";
}

//==================================================MAIN METHOD===========================================================

int main(){	

int distance[7];


//-----------GRAPH DISTANCE----------
	addEdgeDistance(0,1,315);
	addEdgeDistance(0,2,374);
	addEdgeDistance(0,3,1025);
	addEdgeDistance(1,4,520);
	addEdgeDistance(2,3,149);
	addEdgeDistance(2,4,186);	
	addEdgeDistance(2,5,158);	
	addEdgeDistance(3,5,1095);
	addEdgeDistance(6,4,598);
	addEdgeDistance(6,5,50);	
	//-----------GRAPH TIME----------
	addEdgeTime(0,1,3);
	addEdgeTime(0,2,4);
	addEdgeTime(0,3,8);
	addEdgeTime(1,4,7);
	addEdgeTime(2,3,2);
	addEdgeTime(2,4,2);	
	addEdgeTime(2,5,3);	
	addEdgeTime(3,5,5);
	addEdgeTime(6,4,7);
	addEdgeTime(6,5,1);	
//-----------GRAPH FOR EDGES----------
	add_edge(gph,0,1);
    add_edge(gph,0,2);
	add_edge(gph,0,3);
	add_edge(gph,1,4);
	add_edge(gph,2,3);	
	add_edge(gph,2,4);	
	add_edge(gph,2,5);	
	add_edge(gph,3,5);
	add_edge(gph,4,6);
	add_edge(gph,5,6);
	
	int city;

	cout<<"\n\t***************Enter Your City**************** \n\n"; 
	while(true){
		for (int i=0;i<7;i++){
			cout<<"\t\t\t"<<(i)<<" : "<<cities[i]<<"\n";
		}
		cin>>city;
		if (city>=0 && city<7){
			break;
		}
		else{
			cout<<"\nSorry, we do not operate in your city. Try another location...\n";
		}
	}
			
	cout<<"\n\t********Cost of Ticket per km: $100************\n\n";
	int source = city;
	start = cities[city];
	prims(source);
	registerPlane();
	
	
		cout<<"\n	   WELCOME TO PAKISTAN INTERNATIONAL AIRLINES\n\n";
    int opt;
    do{
    	cout<<"\n----------------------------MAIN MENU----------------------------------\n";
    	cout<<"\n\tEnter 1  : Display All Routes From Your City\n";
    	cout<<"\tEnter 2  : Display Shortest Route to each City w.r.t Distance\n";
		cout<<"\tEnter 3  : Display Shortest Route to each City w.r.t Time\n";
        cout<<"\tEnter 4  : Display All Possible Paths From Source To Destination\n";
        cout<<"\tEnter 5  : Display details of all Flights\n";
        cout<<"\tEnter 6  : Book a Passanger Seat\n";
        cout<<"\tEnter 7  : Display all Passangers in a Specific Flight\n";
        cout<<"\tEnter 8  : Cancel booking of a Specific Passanger\n";
        cout<<"\tEnter 9 : Calculate revenue generated by a specific flight\n";
        cout<<"\tEnter 10 : Calculate total revenue generated by all flights\n";
		cout<<"\tEnter 0  : EXIT\n";
		cout<<"\n-----------------------------------------------------------------------\n";
        cout<<"\nEnter your option: ";
        cin>>opt;
        switch(opt){
        	case 1:
        		displayRoutesFromSource();
        		break;
        	case 2:
        		dijkstrasAlgorithm(graph,distance,visited,parent,source,"km");
				break;	
			case 3:
        		dijkstrasAlgorithm(graphtime,distance,visited,parent,source,"hours");
				break;	
			case 4:
				cout<<"Enter Destination: ";
				cin>>dest;
				int j;
				for (j=0;j<7;j++){
					if ((cities[j]).compare(dest)==0){
						break;
					}
				}
				 cout << "Path from source " << cities[source]
         		<< " to destination " << dest<< " are \n";
        		findpaths(gph,source,j,7);
				break;
 
            case 5:{
                displayPlanes();
                break;
            }
            case 6:{
                insertPassangers();
                break;
            }
            case 7:{
                displayPassangers();
                break;
            }
            case 8:
            	cancelBooking();
            	break;
            	
            case 9:{
                revenueOfSpecificPlane();
                break;
            }
            case 10:{
                revenueOfAllPlanes();
                break;
            }
            case 0:
            	cout<<"\n---------------Thankyou for Travelling with Us---------------\n";
            	break;
        }
    }while(opt!=0);
    return 0;
}
