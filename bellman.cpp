#include<bits/stdc++.h>
using namespace std;

struct edge{
    int start;
    int end;
    int weight;
};

void printDist(int *dist, int V, int src){
    int i;
    for(i = 0; i < V; i++)
        cout << "shortest distance of " << i << " from " << src << " is " << dist[i] << endl;
}

void bellman(int V, int E, struct edge *e, int src){
    int dist[V], i, j;
    for(i = 0; i < V; i++)  
        dist[i] = INT_MAX;

    dist[src] = 0;

    for(i = 0; i < V - 1; i++){
        for(j = 0; j < E; j++){
            if(dist[e[j].start] != INT_MAX && dist[e[j].start] + e[j].weight < dist[e[j].end])
                dist[e[j].end] = dist[e[j].start] + e[j].weight;
        }
    }    

    for(j = 0; j < E; j++){
        if(dist[e[j].start] != INT_MAX && dist[e[j].start] + e[j].weight < dist[e[j].end]){
            cout << "Negative weight cycle exists" << endl;
            return;
        }
    }

    printDist(dist, V, src);
}

int main(){
    int V = 5; // Number of vertices in graph 
    int E = 8; // Number of edges in graph 
    struct edge e[E];
    // add edge 0-1 (or A-B in above figure) 
    e[0].start = 0; 
    e[0].end = 1; 
    e[0].weight = -1; 
  
    // add edge 0-2 (or A-C in above figure) 
    e[1].start = 0; 
    e[1].end = 2; 
    e[1].weight = 4; 
  
    // add edge 1-2 (or B-C in above figure) 
    e[2].start = 1; 
    e[2].end = 2; 
    e[2].weight = 3; 
  
    // add edge 1-3 (or B-D in above figure) 
    e[3].start = 1; 
    e[3].end = 3; 
    e[3].weight = 2; 
  
    // add edge 1-4 (or A-E in above figure) 
    e[4].start = 1; 
    e[4].end = 4; 
    e[4].weight = 2; 
  
    // add edge 3-2 (or D-C in above figure) 
    e[5].start = 3; 
    e[5].end = 2; 
    e[5].weight = 5; 
  
    // add edge 3-1 (or D-B in above figure) 
    e[6].start = 3; 
    e[6].end = 1; 
    e[6].weight = 1; 
  
    // add edge 4-3 (or E-D in above figure) 
    e[7].start = 4; 
    e[7].end = 3; 
    e[7].weight = -3; 
  
    bellman(V, E, e, 0); 
    return 0; 

}