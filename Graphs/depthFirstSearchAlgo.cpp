#include<iostream>
using namespace std;

//Representing graph with adjacency matrix globally
int graphArray[7][7] = {
    {0,1,1,1,0,0,0},
    {1,0,1,0,0,0,0},
    {1,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0},
};
int visited[7] = {0,0,0,0,0,0,0};



void depthFirstSearch(int node){
    cout<<node<<" ";
    visited[node] = 1;

    for(int j = 0; j < 7; j++){
        if(graphArray[node][j] == 1 && visited[j] == 0){
            depthFirstSearch(j);
        }
    }


}


int main()
{
    depthFirstSearch(0);
    
}