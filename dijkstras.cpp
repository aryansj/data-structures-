#include<bits/stdc++.h>
using namespace std;
const int V = 9;

int minDist(int *dist, bool *setNode){
    int index, minimum = INT_MAX, i;
    for(i = 0; i < V; i++){
        if(setNode[i] == false && dist[i] <= minimum){
            minimum = dist[i];
            index = i;
        }
    }
    return index;
}

void printSol(int *dist, int start){
    int i;
    for(i = 0; i < V; i++){
        cout << "Shortest distance of " << i << " from " << start << " is " << dist[i] << endl;
    }
}

void dijkstras(int graph[V][V], int start){

    int dist[V], i, j;
    bool setNode[V];

    for(i = 0; i < V; i++){
        dist[i] = INT_MAX;
        setNode[i] = false;
    }
    dist[start] = 0;

    for(i = 0; i < V; i++){
        int u = minDist(dist, setNode);
        setNode[u] = true;
        for(j = 0; j < V; j++){
            if(setNode[j] == false && graph[u][j] && dist[u] + graph[u][j] < dist[j])
                dist[j] = dist[u] + graph[u][j];
        }
    }

    printSol(dist, start);
}

int main(){
     int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

      dijkstras(graph, 0);                  
}