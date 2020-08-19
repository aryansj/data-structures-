#include<bits/stdc++.h>
using namespace std;

void addEdge(int x, int y, vector <int> *adj){    // function to add an edge from node x to node y
    adj[x].push_back(y);
}

void dfs(int start, vector <int> *adj, bool *visited){
    int i;
    visited[start] = true;
    cout << start << " ";
 
    for(i = 0; i < adj[start].size(); i++){  
        if(!visited[adj[start][i]]){
            dfs( adj[start][i], adj, visited);
        }
    }

}

int main() {
    int size;
    cout << "enter size" << endl;
    cin >> size;
    vector <int> adj[size];
    
    addEdge(1, 2, adj); 
    addEdge(2, 1, adj); 
    addEdge(2, 5, adj); 
    addEdge(5, 2, adj); 
    addEdge(1, 3, adj); 
    addEdge(3, 1, adj); 
    addEdge(3, 6, adj);
    addEdge(6, 3, adj);  
    addEdge(4, 1, adj);
    addEdge(1, 4, adj);  
    addEdge(4, 7, adj);
    addEdge(7, 4, adj);  
  
    bool visited[size];                              // create an array of boolean to check if a node is visited  
    int i;

    for(i = 0; i < size; i++)
        visited[i] = false;
  
    cout << "Following is depth First Traversal "
         << "(starting from vertex 2) \n"; 
    dfs(1, adj, visited);
  
    return 0; 
}