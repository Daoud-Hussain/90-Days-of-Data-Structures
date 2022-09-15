// C / C++ program for Dijkstra's
// shortest path algorithm for adjacency
// list representation of graph
#include <limits.h>
#include <ctime>
#include <iomanip>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int storeLocation;
int categoryID;
int productID;
double total_cost[6];

// Product structure
struct product
{
	int product_id;
	string product_name;
	int product_price;
	int product_stock;
	struct product * next_product;

};

// Category Struccture
struct category
{
	int category_id;
	string category_name;
	struct product * product_list;
	struct category * next_category;

};

// A structure to represent a
// node in adjacency list
struct AdjListNode
{
	int dest;
	double distance;
	double traffic_rate;
	string storeName;
	struct AdjListNode * next;
};

// A structure to represent
// an adjacency list
struct AdjList
{
	// Pointer to head node of list
	struct AdjListNode * head;
	struct StoreDetails * store;

};

// A structure to represent store details
struct StoreDetails
{
	string name;
	string available_category_1;
	string available_category_2;
	string available_category_3;

};
// A structure to represent a graph.
// A graph is an array of adjacency lists.
// Size of array will be V (number of
// vertices in graph)
struct Graph
{
	int V;
	struct AdjList * array;

};

// A utility function to create
// a new adjacency list node
struct AdjListNode* newAdjListNode(int dest, double distance, string storeName, double t_rate)
{
	struct AdjListNode *newNode = new AdjListNode;

	newNode->dest = dest;
	newNode->storeName = storeName;
	newNode->distance = distance;
	newNode->traffic_rate = t_rate;
	newNode->next = NULL;
	return newNode;
}

// A utility function that creates
// a graph of V vertices
struct Graph* createGraph(int V)
{
	struct Graph *graph = (struct Graph *) malloc(sizeof(struct Graph));
	graph->V = V;

	// Create an array of adjacency lists.
	// Size of array will be V
	graph->array = new AdjList[V];

	// Initialize each adjacency list
	// as empty by making head as NULL
	for (int i = 0; i < V; i++)
		graph->array[i].head = NULL;

	struct StoreDetails *store1 = new StoreDetails;
	store1->name = "sector F-6 (Super Market)";
	store1->available_category_1 = "Women Fashion";
	store1->available_category_2 = "Men's Fashion";
	store1->available_category_3 = "Perfumes";
	graph->array[0].store = store1;

	struct StoreDetails *store2 = new StoreDetails;
	store2->name = "sector G-6 (Aabpara Market)";
	store2->available_category_1 = "Shoes";
	store2->available_category_2 = "Kitchen Essentials";
	store2->available_category_3 = "Consumer Goods";
	graph->array[1].store = store2;

	struct StoreDetails *store3 = new StoreDetails;
	store3->name = "sector G-9 (Karachi Company)";
	store3->available_category_1 = "Men's Fashion";
	store3->available_category_2 = "Cosmetics";
	store3->available_category_3 = "Sporting Goods";
	graph->array[2].store = store3;

	struct StoreDetails *store4 = new StoreDetails;
	store4->name = "sector F-7 (Jinnah Super Market)";
	store4->available_category_1 = "Cosmetics";
	store4->available_category_2 = "Women Fashion";
	store4->available_category_3 = "Vegetables";
	graph->array[3].store = store4;

	struct StoreDetails *store5 = new StoreDetails;
	store5->name = "sector G-11 (Sunday Market)";
	store5->available_category_1 = "Perfumes";
	store5->available_category_2 = "Stationery Items";
	store5->available_category_3 = "Books";
	graph->array[4].store = store5;

	struct StoreDetails *store6 = new StoreDetails;
	store6->name = "sector H-9 (Sunday Market)";
	store6->available_category_1 = "Kitchen Essentials";
	store6->available_category_2 = "Books";
	store6->available_category_3 = "Vegetables";
	graph->array[5].store = store6;

	struct StoreDetails *store7 = new StoreDetails;
	store7->name = "sector G-6 (Sunday Market)";
	store7->available_category_1 = "Women Fashion";
	store7->available_category_2 = "Sporting Goods";
	store7->available_category_3 = "Kitchen Essentials";
	graph->array[6].store = store7;

	return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph *graph, int src, int dest, double distance)
{
	// Add an edge from src to dest.
	// A new node is added to the adjacency
	// list of src. The node is
	// added at the beginning
	string sourceStore;
	string destStore;

	if (src == 0)
	{
		sourceStore = "sector F-6 (Super Market)";
	}
	else if (src == 1)
	{
		sourceStore = "sector G-6 (Aabpara Market)";
	}
	else if (src == 2)
	{
		sourceStore = "sector G-9 (Karachi Company)";
	}
	else if (src == 3)
	{
		sourceStore = "sector F-7 (Jinnah Super Market)";
	}
	else if (src == 4)
	{
		sourceStore = "sector G-11 (Sunday Market)";
	}
	else if (src == 5)
	{
		sourceStore = "sector G-6 (Sunday Market)";
	}
	else if (src == 6)
	{
		sourceStore = "sector H-9 (Sunday Market)";
	}

	if (dest == 0)
	{
		destStore = "sector F-6 (Super Market)";
	}
	else if (dest == 1)
	{
		destStore = "sector G-6 (Aabpara Market)";
	}
	else if (dest == 2)
	{
		destStore = "sector G-9 (Karachi Company)";
	}
	else if (dest == 3)
	{
		destStore = "sector F-7 (Jinnah Super Market)";
	}
	else if (dest == 4)
	{
		destStore = "sector G-11 (Sunday Market)";
	}
	else if (dest == 5)
	{
		destStore = "sector H-9 (Sunday Market)";
	}
	else if (dest == 6)
	{
		destStore = "sector G-6 (Sunday Market)";
	}

	double a;
	for (int i = 0; i < 1000; i++)
	{
		a = (double)(rand()) / RAND_MAX;
	}

	double traffic_rate = (0.0 + a *(2.0 - 0.0));

	struct AdjListNode *newNode = newAdjListNode(dest, distance, destStore, traffic_rate);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	// Since graph is undirected,
	// add an edge from dest to src also
	newNode = newAdjListNode(src, distance, sourceStore, traffic_rate);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

// Structure to represent a min heap node
struct MinHeapNode
{
	int v;
	int dist;
};

// Structure to represent a min heap
struct MinHeap
{
	// Number of heap nodes present currently
	int size;

	// Capacity of min heap
	int capacity;

	// This is needed for decreaseKey()
	int *pos;
	struct MinHeapNode **array;
};

// A utility function to create a
// new Min Heap Node
struct MinHeapNode* newMinHeapNode(int v, int dist)
{
	struct MinHeapNode *minHeapNode =
		(struct MinHeapNode *)
	malloc(sizeof(struct MinHeapNode));
	minHeapNode->v = v;
	minHeapNode->dist = dist;
	return minHeapNode;
}

// A utility function to create a Min Heap
struct MinHeap* createMinHeap(int capacity)
{
	struct MinHeap *minHeap =
		(struct MinHeap *)
	malloc(sizeof(struct MinHeap));
	minHeap->pos = (int*) malloc(
		capacity* sizeof(int));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array =
		(struct MinHeapNode **)
	malloc(capacity *
		sizeof(struct MinHeapNode *));
	return minHeap;
}

// A utility function to swap two
// nodes of min heap.
// Needed for min heapify
void swapMinHeapNode(struct MinHeapNode **a,
	struct MinHeapNode **b)
{
	struct MinHeapNode *t = *a;
	*a = *b;
	*b = t;
}

// A standard function to
// heapify at given idx
// This function also updates
// position of nodes when they are swapped.
// Position is needed for decreaseKey()
void minHeapify(struct MinHeap *minHeap,
	int idx)
{
	int smallest, left, right;
	smallest = idx;
	left = 2 *idx + 1;
	right = 2 *idx + 2;

	if (left < minHeap->size &&
		minHeap->array[left]->dist<
		minHeap->array[smallest]->dist)
		smallest = left;

	if (right < minHeap->size &&
		minHeap->array[right]->dist<
		minHeap->array[smallest]->dist)
		smallest = right;

	if (smallest != idx)
	{
		// The nodes to be swapped in min heap
		MinHeapNode *smallestNode =
			minHeap->array[smallest];
		MinHeapNode *idxNode =
			minHeap->array[idx];

		// Swap positions
		minHeap->pos[smallestNode->v] = idx;
		minHeap->pos[idxNode->v] = smallest;

		// Swap nodes
		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

		minHeapify(minHeap, smallest);
	}
}

// A utility function to check if
// the given minHeap is ampty or not
int isEmpty(struct MinHeap *minHeap)
{
	return minHeap->size == 0;
}

// Standard function to extract
// minimum node from heap
struct MinHeapNode* extractMin(struct MinHeap *
	minHeap)
{
	if (isEmpty(minHeap))
		return NULL;

	// Store the root node
	struct MinHeapNode *root =
		minHeap->array[0];

	// Replace root node with last node
	struct MinHeapNode *lastNode =
		minHeap->array[minHeap->size - 1];
	minHeap->array[0] = lastNode;

	// Update position of last node
	minHeap->pos[root->v] = minHeap->size - 1;
	minHeap->pos[lastNode->v] = 0;

	// Reduce heap size and heapify root
	--minHeap->size;
	minHeapify(minHeap, 0);

	return root;
}

// Function to decreasy dist value
// of a given vertex v. This function
// uses pos[] of min heap to get the
// current index of node in min heap
void decreaseKey(struct MinHeap *minHeap,
	int v, int dist)
{
	// Get the index of v in heap array
	int i = minHeap->pos[v];

	// Get the node and update its dist value
	minHeap->array[i]->dist = dist;

	// Travel up while the complete
	// tree is not hepified.
	// This is a O(Logn) loop
	while (i && minHeap->array[i]->dist<
		minHeap->array[(i - 1) / 2]->dist)
	{
		// Swap this node with its parent
		minHeap->pos[minHeap->array[i]->v] =
			(i - 1) / 2;
		minHeap->pos[minHeap->array[
			(i - 1) / 2]->v] = i;
		swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

		// move to parent index
		i = (i - 1) / 2;
	}
}

// A utility function to check if a given vertex
// 'v' is in min heap or not
bool isInMinHeap(struct MinHeap *minHeap, int v)
{
	if (minHeap->pos[v] < minHeap->size)
		return true;
	return false;
}

// A utility function used to print the solution
void printArr(int dist[], double traffic[], int n, Graph *graph)
{
	string sourceStore;
	string destStore;
	string selectedCategory;
	string recomended_store;
	double least_cost = 1000;
	struct AdjListNode * headNode;
	struct AdjListNode *storeNode = new AdjListNode;

	if (storeLocation == 0)
	{
		headNode = graph->array[0].head;

		sourceStore = "sector F-6 (Super Market)";
	}
	else if (storeLocation == 1)
	{
		sourceStore = "sector G-6 (Aabpara Market)";
	}
	else if (storeLocation == 2)
	{
		sourceStore = "sector G-9 (Karachi Company)";
	}
	else if (storeLocation == 3)
	{
		sourceStore = "sector F-7 (Jinnah Super Market)";
	}
	else if (storeLocation == 4)
	{
		sourceStore = "sector G-11 (Sunday Market)";
	}
	else if (storeLocation == 5)
	{
		sourceStore = "sector H-9 (Sunday Market)";
	}
	else if (storeLocation == 6)
	{
		sourceStore = "sector G-6 (Sunday Market)";
	}

	if (categoryID == 0)
	{
		selectedCategory = "Women Fashion";
	}
	else if (categoryID == 1)
	{
		selectedCategory = "Men's Fashion";
	}
	else if (categoryID == 2)
	{
		selectedCategory = "Shoes";
	}
	else if (categoryID == 3)
	{
		selectedCategory = "Consumer Goods";
	}
	else if (categoryID == 4)
	{
		selectedCategory = "Kitchen Essentials";
	}
	else if (categoryID == 5)
	{
		selectedCategory = "Sporting Goods";
	}
	else if (categoryID == 6)
	{
		selectedCategory = "Perfumes";
	}
	else if (categoryID == 7)
	{
		selectedCategory = "Vegetables";
	}
	else if (categoryID == 8)
	{
		selectedCategory = "Cosmetics";
	}
	else if (categoryID == 9)
	{
		selectedCategory = "Stationery Items";
	}
	else if (categoryID == 10)
	{
		selectedCategory = "Books";
	}

	cout << " ------------\t\t\t\t ------- \t -------- \t------  \t -----------------" << endl;
	cout << " SOURCE STORE\t\t\t\t TRAFFIC \t DISTANCE \tCOST    \t DESTINATION STORE" << endl;
	cout << " ------------\t\t\t\t ------- \t -------- \t------  \t ----------------- " << endl;
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
		{
			destStore = "sector F-6 (Super Market)";

		}
		else if (i == 1)
		{
			destStore = "sector G-6 (Aabpara Market)";

		}
		else if (i == 2)
		{
			destStore = "sector G-9 (Karachi Company)";

		}
		else if (i == 3)
		{
			destStore = "sector F-7 (Jinnah Super Market)";

		}
		else if (i == 4)
		{
			destStore = "sector G-11 (Sunday Market)";

		}
		else if (i == 5)
		{
			destStore = "sector H-9 (Sunday Market)";
		}
		else if (i == 6)
		{
			destStore = "sector G-6 (Sunday Market)";

		}

		total_cost[i] = traffic[i] *dist[i];
		cout << fixed << setprecision(1);

		if (i != storeLocation)
		{
			if ((graph->array[i].store->available_category_1 == selectedCategory) or(graph->array[i].store->available_category_2 == selectedCategory) or(graph->array[i].store->available_category_3 == selectedCategory))
			{
				cout << "  " << sourceStore << "\t\t  " << traffic[i] << " x\t\t  " << dist[i] << " km\t\t " << total_cost[i] << " \t\t  " << destStore << endl;
				if (total_cost[i] < least_cost)
				{
					least_cost = total_cost[i];
					recomended_store = destStore;
				}
			}
		}
	}

	for (int i = 0; i < 7; i++)
	{
		if (graph->array[i].store->name == recomended_store)
			storeLocation = i;
	}

	cout << "\n --------------------------------------------------------------------------- " << endl;
	cout << " Recommended Visiting Store (Using Shortest Optimized Store Path Algorithm) : " << endl << endl;
	cout << "           ---------------------------------------- " << endl;
	cout << "           " << recomended_store << endl;
	cout << "           ---------------------------------------- " << endl;
}

// The main function that calculates
// distances of shortest paths from src to all
// vertices. It is a O(ELogV) function
void dijkstra(struct Graph *graph, int src)
{
	// Get the number of vertices in graph
	int V = graph->V;

	// dist values used to pick
	// minimum distance edge in cut
	int dist[V];

	// traffic values used to pick
	// minimum distance edge in cut
	double traffic[V];

	// minHeap represents set E
	struct MinHeap *minHeap = createMinHeap(V);

	// Initialize min heap with all
	// vertices. dist value of all vertices
	for (int v = 0; v < V; ++v)
	{
		dist[v] = INT_MAX;

		traffic[v] = INT_MAX;

		minHeap->array[v] = newMinHeapNode(v,
			dist[v]);
		minHeap->pos[v] = v;
	}

	// Make dist value of src vertex as 0 so that it is extracted first
	minHeap->array[src] =
		newMinHeapNode(src, dist[src]);
	minHeap->pos[src] = src;
	dist[src] = 0;
	traffic[src] = 0;
	decreaseKey(minHeap, src, dist[src]);

	// Initially size of min heap is equal to V
	minHeap->size = V;

	// In the followin loop,
	// min heap contains all nodes
	// whose shortest distance
	// is not yet finalized.
	while (!isEmpty(minHeap))
	{
		// Extract the vertex with
		// minimum distance value
		struct MinHeapNode *minHeapNode =
			extractMin(minHeap);

		// Store the extracted vertex number
		int u = minHeapNode->v;

		// Traverse through all adjacent
		// vertices of u (the extracted
		// vertex) and update
		// their distance values
		struct AdjListNode *pCrawl =
			graph->array[u].head;
		while (pCrawl != NULL)
		{
			int v = pCrawl->dest;

			// If shortest distance to v is
			// not finalized yet, and distance to v
			// through u is less than its
			// previously calculated distance
			if (isInMinHeap(minHeap, v) &&
				dist[u] != INT_MAX &&
				pCrawl->distance + dist[u] < dist[v])
			{
				dist[v] = dist[u] + pCrawl->distance;
				traffic[v] = traffic[u] + pCrawl->traffic_rate;
				// update distance
				// value in min heap also

				decreaseKey(minHeap, v, dist[v]);
			}

			pCrawl = pCrawl->next;
		}
	}

	// print the calculated shortest distances
	printArr(dist, traffic, V, graph);
}

void storeMenu(category *head_category, Graph *graph)
{
	void categoryMenu(category *head_category, Graph *graph);
	string locChoice;

	do {
		cout << endl;
		cout << "----------------------------------------------" << endl;
		cout << "      WELCOME TO OUR SUPER MARKET NETWORK" << endl << endl;
		cout << "  1) Sector F-6 (Super Market)" << endl;
		cout << "  2) Sector G-6 (Aabpara Market)" << endl;
		cout << "  3) Sector G-9 (Karachi Company)" << endl;
		cout << "  4) Sector F-7 (Jinnah Super Market)" << endl;
		cout << "  5) Sector G-11 (Sunday Market)" << endl;
		cout << "  6) Sector H-9 (Sunday Market)" << endl;
		cout << "  7) Sector G-6 (Sunday Market)" << endl;
		cout << endl;
		cout << "  Please Select Your Nearby Location (e.g. '1' for 'Sector F-6'): ";

		cin >> locChoice;
		if (locChoice.length() == 1)
		{
			char locationChoice = locChoice.at(0);
			// Display the result
			switch (locationChoice)
			{
				case '1':
					{
						storeLocation = 0;
						categoryMenu(head_category, graph);

						break;
					}

				case '2':
					{
						storeLocation = 1;
						categoryMenu(head_category, graph);
						break;
					}

				case '3':
					{
						storeLocation = 2;
						categoryMenu(head_category, graph);
						break;
					}

				case '4':
					{
						storeLocation = 3;
						categoryMenu(head_category, graph);
						break;
					}

				case '5':
					{
						storeLocation = 4;
						categoryMenu(head_category, graph);
						break;
					}

				case '6':
					{
						storeLocation = 5;
						categoryMenu(head_category, graph);
						break;
					}

				case '7':
					{
						storeLocation = 6;
						categoryMenu(head_category, graph);
						break;
					}

				default:
					cout << endl;
					cout << "    <<<<<<<<<< WRONG INPUT >>>>>>>>>>>>>>>>\n";
			}
		}
		else
		{
			cout << endl;
			cout << "    <<<<<<<<<< WRONG INPUT >>>>>>>>>>>>>>>>\n";

		}
	}

	while (true);

}

void categoryMenu(category *head_category, Graph *graph)
{
	void categoryCheckScreen(category *head_category, Graph *graph);
	string catChoice;
	string locName;

	if (storeLocation == 0)
	{
		locName = "Sector F-6 (Super Market)";
	}
	else if (storeLocation == 1)
	{
		locName = "Sector G-6 (Aabpara Market)";

	}
	else if (storeLocation == 2)
	{
		locName = "Sector G-9 (Karachi Company)";
	}
	else if (storeLocation == 3)
	{
		locName = "Sector F-7 (Jinnah Super Market)";
	}
	else if (storeLocation == 4)
	{
		locName = "Sector G-11 (Sunday Market)";
	}
	else if (storeLocation == 5)
	{
		locName = "Sector H-9 (Sunday Market)";
	}
	else if (storeLocation == 6)
	{
		locName = "Sector G-6 (Sunday Market)";
	}

	do {
		cout << endl;
		cout << "----------------------------------------------" << endl;
		cout << "      WELCOME TO " << locName << endl;
		cout << "      Please Select Your Buying Category (e.g. '3' for 'Shoes')" << endl << endl;
		cout << "  1) Women Fashion  " << endl;
		cout << "  2) Men's Fashion" << endl;
		cout << "  3) Shoes  " << endl;
		cout << "  4) Consumer Goods" << endl;
		cout << "  5) Kitchen Essentials" << endl;
		cout << "  6) Sporting Goods" << endl;
		cout << "  7) Perfumes" << endl;
		cout << "  8) Vegetables" << endl;
		cout << "  9) Cosmetics" << endl;
		cout << "  10) Stationery Items" << endl;
		cout << "  11) Books" << endl;
		cout << endl;
		cout << "  12) GO BACK" << endl;

		cout << "  Enter your choice: ";

		cin >> catChoice;
		if (catChoice.length() == 1)
		{
			char categoryChoice = catChoice.at(0);

			// Display the result
			switch (categoryChoice)
			{
				case '1':
					{
						categoryID = 0;
						categoryCheckScreen(head_category, graph);
						break;
					}

				case '2':
					{
						categoryID = 1;
						categoryCheckScreen(head_category, graph);
						break;
					}

				case '3':
					{
						categoryID = 2;
						categoryCheckScreen(head_category, graph);
						break;
					}

				case '4':
					{
						categoryID = 3;
						categoryCheckScreen(head_category, graph);
						break;
					}

				case '5':
					{
						categoryID = 4;
						categoryCheckScreen(head_category, graph);
						break;
					}

				case '6':
					{
						categoryID = 5;
						categoryCheckScreen(head_category, graph);
						break;
					}

				case '7':
					{
						categoryID = 6;
						categoryCheckScreen(head_category, graph);
						break;
					}

				case '8':
					{
						categoryID = 7;
						categoryCheckScreen(head_category, graph);
						break;
					}

				case '9':
					{
						categoryID = 8;
						categoryCheckScreen(head_category, graph);
						break;
					}

				
			}
		}
		else if (catChoice.length() == 2)
		{
			char categoryChoice = catChoice.at(1);

			if (catChoice.at(0) == '1')
			{
				// Display the result
				switch (categoryChoice)
				{
					case '0':
						{
							categoryID = 9;
							categoryCheckScreen(head_category, graph);
							break;
						}

					case '1':
						{
							categoryID = 10;
							categoryCheckScreen(head_category, graph);
							break;
						}

					case '2':
						{
							storeMenu(head_category, graph);
							break;
						}

					default:
						cout << endl;
						cout << "    <<<<<<<<<< WRONG INPUT >>>>>>>>>>>>>>>>\n";

				}
			}
			else
			{
				cout << endl;
				cout << "    <<<<<<<<<< WRONG INPUT >>>>>>>>>>>>>>>>\n";

			}
		}
		else
		{
			cout << endl;
			cout << "    <<<<<<<<<< WRONG INPUT >>>>>>>>>>>>>>>>\n";

		}
	}

	while (true);
}

void categoryCheckScreen(category *head_category, Graph *graph)
{
	void productsMenu(category *head_category, Graph *graph);
	string opt;
	string selectedCategory;

	if (categoryID == 0)
	{
		selectedCategory = "Women Fashion";
	}
	else if (categoryID == 1)
	{
		selectedCategory = "Men's Fashion";
	}
	else if (categoryID == 2)
	{
		selectedCategory = "Shoes";
	}
	else if (categoryID == 3)
	{
		selectedCategory = "Consumer Goods";
	}
	else if (categoryID == 4)
	{
		selectedCategory = "Kitchen Essentials";
	}
	else if (categoryID == 5)
	{
		selectedCategory = "Sporting Goods";
	}
	else if (categoryID == 6)
	{
		selectedCategory = "Perfumes";
	}
	else if (categoryID == 7)
	{
		selectedCategory = "Vegetables";
	}
	else if (categoryID == 8)
	{
		selectedCategory = "Cosmetics";
	}
	else if (categoryID == 9)
	{
		selectedCategory = "Stationery Items";
	}
	else if (categoryID == 10)
	{
		selectedCategory = "Books";
	}

	if ((graph->array[storeLocation].store->available_category_1 == selectedCategory) or(graph->array[storeLocation].store->available_category_2 == selectedCategory) or(graph->array[storeLocation].store->available_category_3 == selectedCategory))
	{
		productsMenu(head_category, graph);
	}
	else
	{
		do {
			cout << endl;
			cout << "----------------------------------------------" << endl;
			cout << "    WELCOME TO " << graph->array[storeLocation].store->name << endl << endl;
			cout << "    ***The selected category stock is limited on your nearby location ***" << endl << endl;
			cout << "    ------------------------------------" << endl;
			cout << "    Selected Category : " << selectedCategory << endl;
			cout << "    ------------------------------------" << endl << endl;

			cout << "  1) Visit other nearby stores for the same product category  " << endl;
			cout << "  2) GO BACK" << endl << endl;

			cout << "  Enter your choice: ";

			cin >> opt;
			if (opt.length() == 1)
			{
				char option = opt.at(0);
				// Display the result
				switch (option)
				{
					case '1':
						{
							dijkstra(graph, storeLocation);
							productsMenu(head_category, graph);
							break;
						}

					case '2':
						{
							categoryMenu(head_category, graph);
							break;
						}

					default:
						cout << endl;
						cout << "    <<<<<<<<<< WRONG INPUT >>>>>>>>>>>>>>>>\n";
				}
			}
			else
			{
				cout << endl;
				cout << "    <<<<<<<<<< WRONG INPUT >>>>>>>>>>>>>>>>\n";

			}
		}

		while (true);

	}
}

void productsMenu(category *head_category, Graph *graph)
{
	void productDetailsMenu(category *head_category, Graph *graph);
	string pChoice;

	int productsNum = 0;
	string selectedCategory;
	string locName;

	category *current_category = new category;
	current_category = head_category;

	if (categoryID != 0)
	{
		while (current_category->next_category != NULL)
		{
			if (current_category->category_id == categoryID)
				break;

			current_category = current_category->next_category;
		}
	}

	if (categoryID == 0)
	{
		selectedCategory = "Women Fashion";
	}
	else if (categoryID == 1)
	{
		selectedCategory = "Men's Fashion";
	}
	else if (categoryID == 2)
	{
		selectedCategory = "Shoes";
	}
	else if (categoryID == 3)
	{
		selectedCategory = "Consumer Goods";
	}
	else if (categoryID == 4)
	{
		selectedCategory = "Kitchen Essentials";
	}
	else if (categoryID == 5)
	{
		selectedCategory = "Sporting Goods";
	}
	else if (categoryID == 6)
	{
		selectedCategory = "Perfumes";
	}
	else if (categoryID == 7)
	{
		selectedCategory = "Vegetables";
	}
	else if (categoryID == 8)
	{
		selectedCategory = "Cosmetics";
	}
	else if (categoryID == 9)
	{
		selectedCategory = "Stationery Items";
	}
	else if (categoryID == 10)
	{
		selectedCategory = "Books";
	}

	if (storeLocation == 0)
	{
		locName = "Sector F-6 (Super Market)";
	}
	else if (storeLocation == 1)
	{
		locName = "Sector G-6 (Aabpara Market)";

	}
	else if (storeLocation == 2)
	{
		locName = "Sector G-9 (Karachi Company)";
	}
	else if (storeLocation == 3)
	{
		locName = "Sector F-7 (Jinnah Super Market)";
	}
	else if (storeLocation == 4)
	{
		locName = "Sector G-11 (Sunday Market)";
	}
	else if (storeLocation == 5)
	{
		locName = "Sector H-9 (Sunday Market)";
	}
	else if (storeLocation == 6)
	{
		locName = "Sector G-6 (Sunday Market)";
	}

	do {
		cout << endl;
		cout << "    ------------------------------------------------------------------------------" << endl;
		cout << "      WELCOME TO " << locName << " >> Selected Category: " << selectedCategory << endl;
		cout << "    -----------------------------------------------------------------------------" << endl;
		cout << "      The available products are:" << endl << endl;
		cout << "      Select Your Product (e.g. '1' for 'Abaya')" << endl << endl;

		product *current_product = new product;
		current_product = current_category->product_list;

		int i = 1;
		while (current_product->next_product != NULL)
		{
			cout << "  " << i << ") " << current_product->product_name << endl;
			current_product = current_product->next_product;
			i++;
		}

		cout << endl;
		cout << "  6) GO BACK" << endl;

		cout << "  Enter your choice: ";

		cin >> pChoice;

		if (pChoice.length() == 1)
		{
			char productChoice = pChoice.at(0);
			// Display the result
			switch (productChoice)
			{
				case '1':
					{
						productID = 0;
						productDetailsMenu(head_category, graph);
						break;
					}

				case '2':
					{
						productID = 1;
						productDetailsMenu(head_category, graph);
						break;
					}

				case '3':
					{
						productID = 2;
						productDetailsMenu(head_category, graph);
						break;
					}

				case '4':
					{
						productID = 3;
						productDetailsMenu(head_category, graph);
						break;
					}

				case '5':
					{
						productID = 4;
						productDetailsMenu(head_category, graph);
						break;
					}

				case '6':
					{
						categoryMenu(head_category, graph);
						break;
					}

				default:
					cout << endl;
					cout << "    <<<<<<<<<< WRONG INPUT >>>>>>>>>>>>>>>>\n";
			}
		}
		else
		{
			cout << endl;
			cout << "    <<<<<<<<<< WRONG INPUT >>>>>>>>>>>>>>>>\n";

		}
	}

	while (true);
}

void productDetailsMenu(category *head_category, Graph *graph)
{
	string pDChoice;

	string locName;

	category *current_category = new category;
	current_category = head_category;

	if (categoryID != 0)
	{
		while (current_category->next_category != NULL)
		{
			if (current_category->category_id == categoryID)
				break;

			current_category = current_category->next_category;
		}
	}

	product *current_product = new product;
	current_product = current_category->product_list;

	if (productID != 0)
	{
		while (current_product->next_product != NULL)
		{
			if (current_product->product_id == productID)
				break;
			current_product = current_product->next_product;
		}
	}

	if (storeLocation == 0)
	{
		locName = "Sector F-6 (Super Market)";
	}
	else if (storeLocation == 1)
	{
		locName = "Sector G-6 (Aabpara Market)";

	}
	else if (storeLocation == 2)
	{
		locName = "Sector G-9 (Karachi Company)";
	}
	else if (storeLocation == 3)
	{
		locName = "Sector F-7 (Jinnah Super Market)";
	}
	else if (storeLocation == 4)
	{
		locName = "Sector G-11 (Sunday Market)";
	}
	else if (storeLocation == 5)
	{
		locName = "Sector H-9 (Sunday Market)";
	}
	else if (storeLocation == 6)
	{
		locName = "Sector G-6 (Sunday Market)";
	}

	do {
		cout << endl;
		cout << "----------------------------------------------" << endl;
		cout << "      WELCOME TO " << locName << endl;
		cout << "      Product Details:" << endl;
		cout << "      -----------------:" << endl;
		cout << "  Product ID:  " << current_product->product_id << endl;
		cout << "  Product Name:  " << current_product->product_name << endl;
		cout << "  Product Category:   " << current_category->category_name << endl;
		cout << "  Product Price:   " << current_product->product_price << endl;
		cout << "  Available Stock:   " << current_product->product_stock << endl << endl;

		cout << "  1) Buy Product" << endl;
		cout << "  2) Cancel  " << endl;
		cout << endl;
		cout << "  Select Your Choice: ";

		cin >> pDChoice;

		if (pDChoice.length() == 1)
		{
			char productDetailChoice = pDChoice.at(0);
			// Display the result
			switch (productDetailChoice)
			{
				case '1':
					{
						if (current_product->product_stock == 0)
						{
							cout << " PRODUCT STOCK IS CURRENTLY EMPTY" << endl;
						}
						else
						{
							cout << "  THANKS FOR BUYING PRODUCT" << endl;
							// decrement logic
							current_product->product_stock = (current_product->product_stock) - 1;
						}

						productsMenu(head_category, graph);
						break;
					}

				case '2':
					{
						productsMenu(head_category, graph);
						break;
					}

				default:
					cout << endl;
					cout << "    <<<<<<<<<< WRONG INPUT >>>>>>>>>>>>>>>>\n";
			}
		}
		else
		{
			cout << endl;
			cout << "    <<<<<<<<<< WRONG INPUT >>>>>>>>>>>>>>>>\n";
		}
	}

	while (true);
}

// Driver program to test above functions
int main()
{
	// create the graph given in above fugure
	int V = 7;
	struct Graph *graph = createGraph(V);

	srand(time(0));
	addEdge(graph, 0, 1, 4);
	addEdge(graph, 0, 6, 8);
	addEdge(graph, 1, 2, 8);
	addEdge(graph, 1, 6, 11);
	addEdge(graph, 2, 3, 7);
	addEdge(graph, 2, 5, 4);
	addEdge(graph, 3, 4, 9);
	addEdge(graph, 3, 5, 14);
	addEdge(graph, 4, 5, 10);
	addEdge(graph, 5, 6, 2);
	addEdge(graph, 6, 3, 6);

	category *head_category = new category;
	category *second_category = new category;
	category *third_category = new category;
	category *fourth_category = new category;
	category *fifth_category = new category;
	category *sixth_category = new category;
	category *seventh_category = new category;
	category *eight_category = new category;
	category *ninth_category = new category;
	category *tenth_category = new category;
	category *last_category = new category;

	product *head_product_cat1 = new product;
	product *second_product_cat1 = new product;
	product *third_product_cat1 = new product;
	product *fourth_product_cat1 = new product;
	product *fifth_product_cat1 = new product;
	product *last_product_cat1 = new product;

	product *head_product_cat2 = new product;
	product *second_product_cat2 = new product;
	product *third_product_cat2 = new product;
	product *fourth_product_cat2 = new product;
	product *fifth_product_cat2 = new product;
	product *last_product_cat2 = new product;

	product *head_product_cat3 = new product;
	product *second_product_cat3 = new product;
	product *third_product_cat3 = new product;
	product *fourth_product_cat3 = new product;
	product *fifth_product_cat3 = new product;
	product *last_product_cat3 = new product;

	product *head_product_cat4 = new product;
	product *second_product_cat4 = new product;
	product *third_product_cat4 = new product;
	product *fourth_product_cat4 = new product;
	product *fifth_product_cat4 = new product;
	product *last_product_cat4 = new product;

	product *head_product_cat5 = new product;
	product *second_product_cat5 = new product;
	product *third_product_cat5 = new product;
	product *fourth_product_cat5 = new product;
	product *fifth_product_cat5 = new product;
	product *last_product_cat5 = new product;

	product *head_product_cat6 = new product;
	product *second_product_cat6 = new product;
	product *third_product_cat6 = new product;
	product *fourth_product_cat6 = new product;
	product *fifth_product_cat6 = new product;
	product *last_product_cat6 = new product;

	product *head_product_cat7 = new product;
	product *second_product_cat7 = new product;
	product *third_product_cat7 = new product;
	product *fourth_product_cat7 = new product;
	product *fifth_product_cat7 = new product;
	product *last_product_cat7 = new product;

	product *head_product_cat8 = new product;
	product *second_product_cat8 = new product;
	product *third_product_cat8 = new product;
	product *fourth_product_cat8 = new product;
	product *fifth_product_cat8 = new product;
	product *last_product_cat8 = new product;

	product *head_product_cat9 = new product;
	product *second_product_cat9 = new product;
	product *third_product_cat9 = new product;
	product *fourth_product_cat9 = new product;
	product *fifth_product_cat9 = new product;
	product *last_product_cat9 = new product;

	product *head_product_cat10 = new product;
	product *second_product_cat10 = new product;
	product *third_product_cat10 = new product;
	product *fourth_product_cat10 = new product;
	product *fifth_product_cat10 = new product;
	product *last_product_cat10 = new product;

	product *head_product_cat11 = new product;
	product *second_product_cat11 = new product;
	product *third_product_cat11 = new product;
	product *fourth_product_cat11 = new product;
	product *fifth_product_cat11 = new product;
	product *last_product_cat11 = new product;

	head_category->category_id = 0;
	head_category->category_name = "Women Fashion ";
	head_category->product_list = head_product_cat1;
	head_category->next_category = second_category;

	second_category->category_id = 1;
	second_category->category_name = "Men's Fashion ";
	second_category->product_list = head_product_cat2;
	second_category->next_category = third_category;

	third_category->category_id = 2;
	third_category->category_name = "Shoes";
	third_category->product_list = head_product_cat3;
	third_category->next_category = fourth_category;

	fourth_category->category_id = 3;
	fourth_category->category_name = "Consumer Goods";
	fourth_category->product_list = head_product_cat4;
	fourth_category->next_category = fifth_category;

	fifth_category->category_id = 4;
	fifth_category->category_name = "Kitchen Essentials";
	fifth_category->product_list = head_product_cat5;
	fifth_category->next_category = sixth_category;

	sixth_category->category_id = 5;
	sixth_category->category_name = "Sporting Goods";
	sixth_category->product_list = head_product_cat6;
	sixth_category->next_category = seventh_category;

	seventh_category->category_id = 6;
	seventh_category->category_name = "Perfumes";
	seventh_category->product_list = head_product_cat7;
	seventh_category->next_category = eight_category;

	eight_category->category_id = 7;
	eight_category->category_name = "Vegetables";
	eight_category->product_list = head_product_cat8;
	eight_category->next_category = ninth_category;

	ninth_category->category_id = 8;
	ninth_category->category_name = "Cosmetics";
	ninth_category->product_list = head_product_cat9;
	ninth_category->next_category = tenth_category;

	tenth_category->category_id = 9;
	tenth_category->category_name = "Stationery Items";
	tenth_category->product_list = head_product_cat10;
	tenth_category->next_category = last_category;

	last_category->category_id = 10;
	last_category->category_name = "Books";
	last_category->product_list = head_product_cat10;
	last_category->next_category = NULL;

	head_product_cat1->product_id = 884;
	head_product_cat1->product_name = "Abaya";
	head_product_cat1->product_price = 1200;
	head_product_cat1->product_stock = 5;
	head_product_cat1->next_product = second_product_cat1;

	second_product_cat1->product_id = 321;
	second_product_cat1->product_name = "Velvet Embroidery Dress";
	second_product_cat1->product_price = 2000;
	second_product_cat1->product_stock = 5;
	second_product_cat1->next_product = third_product_cat1;

	third_product_cat1->product_id = 102;
	third_product_cat1->product_name = "Hijab";
	third_product_cat1->product_price = 500;
	third_product_cat1->product_stock = 5;
	third_product_cat1->next_product = fourth_product_cat1;

	fourth_product_cat1->product_id = 639;
	fourth_product_cat1->product_name = "Sapphire Zareen Collection Unstiched Suit";
	fourth_product_cat1->product_price = 3000;
	fourth_product_cat1->product_stock = 5;
	fourth_product_cat1->next_product = fifth_product_cat1;

	fifth_product_cat1->product_id = 772;
	fifth_product_cat1->product_name = "Edenrobe Women Un-Stitched 3-piece";
	fifth_product_cat1->product_price = 2000;
	fifth_product_cat1->product_stock = 5;
	fifth_product_cat1->next_product = last_product_cat1;

	last_product_cat1->product_id = 402;
	last_product_cat1->product_name = "Edenrobe Women Un-Stitched";
	last_product_cat1->product_price = 6000;
	last_product_cat1->product_stock = 5;
	last_product_cat1->next_product = NULL;

	/////////////////////////////////////////////////////// CATEGORY 2 PDODUCTS	//////////////////////////////////////
	head_product_cat2->product_id = 555;
	head_product_cat2->product_name = "Men Suit";
	head_product_cat2->product_price = 5000;
	head_product_cat2->product_stock = 5;
	head_product_cat2->next_product = second_product_cat2;

	second_product_cat2->product_id = 392;
	second_product_cat2->product_name = "Sweaters";
	second_product_cat2->product_price = 1200;
	second_product_cat2->product_stock = 5;
	second_product_cat2->next_product = third_product_cat2;

	third_product_cat2->product_id = 645;
	third_product_cat2->product_name = "Business Casual Dress";
	third_product_cat2->product_price = 8000;
	third_product_cat2->product_stock = 5;
	third_product_cat2->next_product = fourth_product_cat2;

	fourth_product_cat2->product_id = 340;
	fourth_product_cat2->product_name = "Men Embroided Kurta";
	fourth_product_cat2->product_price = 1500;
	fourth_product_cat2->product_stock = 5;
	fourth_product_cat2->next_product = fifth_product_cat2;

	fifth_product_cat2->product_id = 109;
	fifth_product_cat2->product_name = "Cocktail Attire Dress";
	fifth_product_cat2->product_price = 5000;
	fifth_product_cat2->product_stock = 5;
	fifth_product_cat2->next_product = last_product_cat2;

	last_product_cat2->product_id = 781;
	last_product_cat2->product_name = "Men Shorts";
	last_product_cat2->product_price = 1300;
	last_product_cat2->product_stock = 5;
	last_product_cat2->next_product = NULL;

	/////////////////////////////////////////////////////// CATEGORY 3 PDODUCTS	//////////////////////////////////////
	head_product_cat3->product_id = 076;
	head_product_cat3->product_name = "Sneakers";
	head_product_cat3->product_price = 2000;
	head_product_cat3->product_stock = 5;
	head_product_cat3->next_product = second_product_cat3;

	second_product_cat3->product_id = 298;
	second_product_cat3->product_name = "Boats";
	second_product_cat3->product_price = 2500;
	second_product_cat3->product_stock = 5;
	second_product_cat3->next_product = third_product_cat3;

	third_product_cat3->product_id = 908;
	third_product_cat3->product_name = "Borgue";
	third_product_cat3->product_price = 3000;
	third_product_cat3->product_stock = 5;
	third_product_cat3->next_product = fourth_product_cat3;

	fourth_product_cat3->product_id = 112;
	fourth_product_cat3->product_name = "Sandals";
	fourth_product_cat3->product_price = 1400;
	fourth_product_cat3->product_stock = 5;
	fourth_product_cat3->next_product = fifth_product_cat3;

	fifth_product_cat3->product_id = 487;
	fifth_product_cat3->product_name = "Black Oxford";
	fifth_product_cat3->product_price = 3500;
	fifth_product_cat3->product_stock = 5;
	fifth_product_cat3->next_product = last_product_cat3;

	last_product_cat3->product_id = 319;
	last_product_cat3->product_name = "Basketball Shoe";
	last_product_cat3->product_price = 4000;
	last_product_cat3->product_stock = 5;
	last_product_cat3->next_product = NULL;
	/////////////////////////////////////////////////////// CATEGORY 4 PDODUCTS	//////////////////////////////////////
	head_product_cat4->product_id = 776;
	head_product_cat4->product_name = "Magazines";
	head_product_cat4->product_price = 300;
	head_product_cat4->product_stock = 5;
	head_product_cat4->next_product = second_product_cat4;

	second_product_cat4->product_id = 278;
	second_product_cat4->product_name = "Laundry Detergent";
	second_product_cat4->product_price = 1200;
	second_product_cat4->product_stock = 5;
	second_product_cat4->next_product = third_product_cat4;

	third_product_cat4->product_id = 782;
	third_product_cat4->product_name = "Energy Drinks";
	third_product_cat4->product_price = 800;
	third_product_cat4->product_stock = 5;
	third_product_cat4->next_product = fourth_product_cat4;

	fourth_product_cat4->product_id = 409;
	fourth_product_cat4->product_name = "Vitamins";
	fourth_product_cat4->product_price = 500;
	fourth_product_cat4->product_stock = 5;
	fourth_product_cat4->next_product = fifth_product_cat4;

	fifth_product_cat4->product_id = 891;
	fifth_product_cat4->product_name = "Fragrant Candles";
	fifth_product_cat4->product_price = 800;
	fifth_product_cat4->product_stock = 5;
	fifth_product_cat4->next_product = last_product_cat4;

	last_product_cat4->product_id = 398;
	last_product_cat4->product_name = "Tooth paste";
	last_product_cat4->product_price = 500;
	last_product_cat4->product_stock = 5;
	last_product_cat4->next_product = NULL;
	/////////////////////////////////////////////////////// CATEGORY 5 PDODUCTS	//////////////////////////////////////
	head_product_cat5->product_id = 593;
	head_product_cat5->product_name = "Knives";
	head_product_cat5->product_price = 500;
	head_product_cat5->product_stock = 5;
	head_product_cat5->next_product = second_product_cat5;

	second_product_cat5->product_id = 321;
	second_product_cat5->product_name = "Measuring Cups";
	second_product_cat5->product_price = 1500;
	second_product_cat5->product_stock = 5;
	second_product_cat5->next_product = third_product_cat5;

	third_product_cat5->product_id = 408;
	third_product_cat5->product_name = "Fish Turner";
	third_product_cat5->product_price = 2000;
	third_product_cat5->product_stock = 5;
	third_product_cat5->next_product = fourth_product_cat5;

	fourth_product_cat5->product_id = 012;
	fourth_product_cat5->product_name = "Tongs";
	fourth_product_cat5->product_price = 1500;
	fourth_product_cat5->product_stock = 5;
	fourth_product_cat5->next_product = fifth_product_cat5;

	fifth_product_cat5->product_id = 675;
	fifth_product_cat5->product_name = "Salad Spinner";
	fifth_product_cat5->product_price = 200;
	fifth_product_cat5->product_stock = 5;
	fifth_product_cat5->next_product = last_product_cat5;

	last_product_cat5->product_id = 184;
	last_product_cat5->product_name = "Stock pot";
	last_product_cat5->product_price = 2000;
	last_product_cat5->product_stock = 5;
	last_product_cat5->next_product = NULL;
	/////////////////////////////////////////////////////// CATEGORY 6 PDODUCTS	//////////////////////////////////////
	head_product_cat6->product_id = 031;
	head_product_cat6->product_name = "Tennis Racquet";
	head_product_cat6->product_price = 1000;
	head_product_cat6->product_stock = 5;
	head_product_cat6->next_product = second_product_cat6;

	second_product_cat6->product_id = 832;
	second_product_cat6->product_name = "Insulated Bottle";
	second_product_cat6->product_price = 2500;
	second_product_cat6->product_stock = 5;
	second_product_cat6->next_product = third_product_cat6;

	third_product_cat6->product_id = 543;
	third_product_cat6->product_name = "Spalding Beast Basketball";
	third_product_cat6->product_price = 5000;
	third_product_cat6->product_stock = 5;
	third_product_cat6->next_product = fourth_product_cat6;

	fourth_product_cat6->product_id = 765;
	fourth_product_cat6->product_name = "Football Gloves";
	fourth_product_cat6->product_price = 2000;
	fourth_product_cat6->product_stock = 5;
	fourth_product_cat6->next_product = fifth_product_cat6;

	fifth_product_cat6->product_id = 309;
	fifth_product_cat6->product_name = "Volleyball Protector";
	fifth_product_cat6->product_price = 6000;
	fifth_product_cat6->product_stock = 5;
	fifth_product_cat6->next_product = last_product_cat6;

	last_product_cat6->product_id = 861;
	last_product_cat6->product_name = "Sports Sweatshirt";
	last_product_cat6->product_price = 1200;
	last_product_cat6->product_stock = 5;
	last_product_cat6->next_product = NULL;
	/////////////////////////////////////////////////////// CATEGORY 7 PDODUCTS	//////////////////////////////////////
	head_product_cat7->product_id = 879;
	head_product_cat7->product_name = "PARIS Puor Homme";
	head_product_cat7->product_price = 2000;
	head_product_cat7->product_stock = 5;
	head_product_cat7->next_product = second_product_cat7;

	second_product_cat7->product_id = 401;
	second_product_cat7->product_name = "PARIS Puor Femme";
	second_product_cat7->product_price = 2000;
	second_product_cat7->product_stock = 5;
	second_product_cat7->next_product = third_product_cat7;

	third_product_cat7->product_id = 579;
	third_product_cat7->product_name = "LONDON Puor Homme";
	third_product_cat7->product_price = 2000;
	third_product_cat7->product_stock = 5;
	third_product_cat7->next_product = fourth_product_cat7;

	fourth_product_cat7->product_id = 539;
	fourth_product_cat7->product_name = "LONDON Puor Femme";
	fourth_product_cat7->product_price = 2000;
	fourth_product_cat7->product_stock = 5;
	fourth_product_cat7->next_product = fifth_product_cat7;

	fifth_product_cat7->product_id = 012;
	fifth_product_cat7->product_name = "MOSCOW Puor Homme";
	fifth_product_cat7->product_price = 2000;
	fifth_product_cat7->product_stock = 5;
	fifth_product_cat7->next_product = last_product_cat7;

	last_product_cat7->product_id = 902;
	last_product_cat7->product_name = "MOSCOW Puor Femme";
	last_product_cat7->product_price = 2000;
	last_product_cat7->product_stock = 5;
	last_product_cat7->next_product = NULL;

	/////////////////////////////////////////////////////// CATEGORY 8 PDODUCTS	//////////////////////////////////////
	head_product_cat8->product_id = 876;
	head_product_cat8->product_name = "Cabbage";
	head_product_cat8->product_price = 70;
	head_product_cat8->product_stock = 5;
	head_product_cat8->next_product = second_product_cat8;

	second_product_cat8->product_id = 234;
	second_product_cat8->product_name = "Chives";
	second_product_cat8->product_price = 90;
	second_product_cat8->product_stock = 5;
	second_product_cat8->next_product = third_product_cat8;

	third_product_cat8->product_id = 045;
	third_product_cat8->product_name = "Kohlrabi";
	third_product_cat8->product_price = 45;
	third_product_cat8->product_stock = 5;
	third_product_cat8->next_product = fourth_product_cat8;

	fourth_product_cat8->product_id = 568;
	fourth_product_cat8->product_name = "Sweet Potatoes";
	fourth_product_cat8->product_price = 30;
	fourth_product_cat8->product_stock = 5;
	fourth_product_cat8->next_product = fifth_product_cat8;

	fifth_product_cat8->product_id = 301;
	fifth_product_cat8->product_name = "Green Onion";
	fifth_product_cat8->product_price = 40;
	fifth_product_cat8->product_stock = 5;
	fifth_product_cat8->next_product = last_product_cat8;

	last_product_cat8->product_id = 782;
	last_product_cat8->product_name = "Eggplant";
	last_product_cat8->product_price = 50;
	last_product_cat8->product_stock = 5;
	last_product_cat8->next_product = NULL;

	/////////////////////////////////////////////////////// CATEGORY 9 PDODUCTS	//////////////////////////////////////
	head_product_cat9->product_id = 345;
	head_product_cat9->product_name = "Eye Shaow Palette";
	head_product_cat9->product_price = 3000;
	head_product_cat9->product_stock = 5;
	head_product_cat9->next_product = second_product_cat9;

	second_product_cat9->product_id = 780;
	second_product_cat9->product_name = "Makeup Brushes";
	second_product_cat9->product_price = 3000;
	second_product_cat9->product_stock = 5;
	second_product_cat9->next_product = third_product_cat9;

	third_product_cat9->product_id = 321;
	third_product_cat9->product_name = "Highlighter";
	third_product_cat9->product_price = 2500;
	third_product_cat9->product_stock = 5;
	third_product_cat9->next_product = fourth_product_cat9;

	fourth_product_cat9->product_id = 875;
	fourth_product_cat9->product_name = "Bronzer";
	fourth_product_cat9->product_price = 1500;
	fourth_product_cat9->product_stock = 5;
	fourth_product_cat9->next_product = fifth_product_cat9;

	fifth_product_cat9->product_id = 877;
	fifth_product_cat9->product_name = "Eye Liner";
	fifth_product_cat9->product_price = 2000;
	fifth_product_cat9->product_stock = 5;
	fifth_product_cat9->next_product = last_product_cat9;

	last_product_cat9->product_id = 043;
	last_product_cat9->product_name = "Mascara";
	last_product_cat9->product_price = 1500;
	last_product_cat9->product_stock = 5;
	last_product_cat9->next_product = NULL;

	/////////////////////////////////////////////////////// CATEGORY 10 PDODUCTS	//////////////////////////////////////
	head_product_cat10->product_id = 567;
	head_product_cat10->product_name = "Stickers";
	head_product_cat10->product_price = 200;
	head_product_cat10->product_stock = 5;
	head_product_cat10->next_product = second_product_cat10;

	second_product_cat10->product_id = 234;
	second_product_cat10->product_name = "Registers";
	second_product_cat10->product_price = 160;
	second_product_cat10->product_stock = 5;
	second_product_cat10->next_product = third_product_cat10;

	third_product_cat10->product_id = 560;
	third_product_cat10->product_name = "Pointers";
	third_product_cat10->product_price = 50;
	third_product_cat10->product_stock = 5;
	third_product_cat10->next_product = fourth_product_cat10;

	fourth_product_cat10->product_id = 061;
	fourth_product_cat10->product_name = "Markers";
	fourth_product_cat10->product_price = 50;
	fourth_product_cat10->product_stock = 5;
	fourth_product_cat10->next_product = fifth_product_cat10;

	fifth_product_cat10->product_id = 987;
	fifth_product_cat10->product_name = "White Paper Sheets";
	fifth_product_cat10->product_price = 20;
	fifth_product_cat10->product_stock = 5;
	fifth_product_cat10->next_product = last_product_cat10;

	last_product_cat10->product_id = 442;
	last_product_cat10->product_name = "Ballpoints";
	last_product_cat10->product_price = 40;
	last_product_cat10->product_stock = 5;
	last_product_cat10->next_product = NULL;

	/////////////////////////////////////////////////////// LAST CATEGORY PDODUCTS	//////////////////////////////////////

	head_product_cat11->product_id = 422;
	head_product_cat11->product_name = "English";
	head_product_cat11->product_price = 300;
	head_product_cat11->product_stock = 5;
	head_product_cat11->next_product = second_product_cat11;

	second_product_cat11->product_id = 503;
	second_product_cat11->product_name = "Calculus";
	second_product_cat11->product_price = 300;
	second_product_cat11->product_stock = 5;
	second_product_cat11->next_product = third_product_cat11;

	third_product_cat11->product_id = 210;
	third_product_cat11->product_name = "Physics";
	third_product_cat11->product_price = 300;
	third_product_cat11->product_stock = 5;
	third_product_cat11->next_product = fourth_product_cat11;

	fourth_product_cat11->product_id = 677;
	fourth_product_cat11->product_name = "Chemistry";
	fourth_product_cat11->product_price = 400;
	fourth_product_cat11->product_stock = 5;
	fourth_product_cat11->next_product = fifth_product_cat11;

	fifth_product_cat11->product_id = 909;
	fifth_product_cat11->product_name = "Biology";
	fifth_product_cat11->product_price = 400;
	fifth_product_cat11->product_stock = 5;
	fifth_product_cat11->next_product = last_product_cat11;

	last_product_cat11->product_id = 553;
	last_product_cat11->product_name = "Pakistan Studies";
	last_product_cat11->product_price = 300;
	last_product_cat11->product_stock = 5;
	last_product_cat11->next_product = NULL;

	storeMenu(head_category, graph);

	return 0;
}
