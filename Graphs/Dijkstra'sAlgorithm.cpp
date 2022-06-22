#include <iostream>
#include <string>
using namespace std;

#define V 15
 

int minDistance(int dist[], bool sptSet[])
{
   
    // Initialize min value
    int min = 2147483648;
	int min_index;
 
    for (int v = 0; v < V; v++){
        if (sptSet[v] == false && dist[v] <= min){
            min = dist[v];
			min_index = v;
		}
 	}
    return min_index;
}
 
void printSolution(int dist[],string path[])
{
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout<< i << " \t\t"<<dist[i]<<"\t\t"<< endl;

        
}
 

void dijkstra(int graph[V][V], int src)
{
    int dist[V]; 
    bool sptSet[V]; 
 	string path[V];
    
    for (int i = 0; i < V; i++){
	
        dist[i] = 2147483648;
		sptSet[i] = false;
		path[i] = to_string(src);
 	}
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        
        int u = minDistance(dist, sptSet);
 
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++){
		
 
            
            if (sptSet[v]==false && graph[u][v]!=0  && (dist[u] + graph[u][v] < dist[v])){
			
                dist[v] = dist[u] + graph[u][v];
				path[v]  = path[v].append("-->");
				path[v]  = path[v].append(to_string(u));
        	}
        }
    }
 
    // print the constructed distance array
    printSolution(dist,path);
}
 
// driver program to test above function
int main()
{
//   					   0,	1	2	3	4	5	6	7	8	9	10	11	12	13	14
    int graph[V][V] = { 
						 { 0,	0,	0,	0,	0,	0,	0,	0,	0,	12,	8,	0,	0,	0,	0},
						 { 0,	0,	11,	0,	4,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
						 { 0,	11,	0,	5,	0,	2,	0,	0,	0,	0,	0,	0,	0,	0,	0},
						 { 0,	0,	5,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0,	0},
						 { 0,	4,	0,	0,	0,	0,	0,	0,	7,	0,	11,	0,	0,	0,	0},
						 { 0,	0,	2,	0,	0,	0,	7,	6,	8,	0,	0,	0,	0,	0,	0},
						 { 0,	0,	0,	2,	0,	7,	0,	0,	0,	9,	0,	0,	0,	0,	0},
						 { 0,	0,	0,	0,	0,	6,	0,	0,	9,	0,	0,	0,	0,	0,	0},
						 { 0,	0,	0,	0,	7,	8,	0,	9,	0,	10,	14,	0,	0,	0,	0},
						 { 12,	0,	0,	0,	0,	0,	9,	0,	10,	0,	17,	0,	0,	0,	0},
						 { 8,	0,	0,	0,	11,	0,	0,	0,	14,	17,	0,	0,	0,	0,	0},
						 { 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
						 { 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
						 { 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
						 { 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0} 
						 };
 					
 					
    dijkstra(graph, 5);
 
    return 0;
}