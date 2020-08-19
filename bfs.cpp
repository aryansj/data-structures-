#include<bits/stdc++.h>
using namespace std;

void addEdge(int x, int y, vector <int> *adj){    // function to add an edge from node x to node y
    adj[x].push_back(y);
}

void bfs(int start, int n, vector <int> *adj){
    bool visited[n];                              // create an array of boolean to check if a node is visited  
    int i;

    for(i = 0; i < n; i++)
        visited[i] = false;

    vector <int> v;
    visited[start] = true;
    v.push_back(start);

    while( v.size() != 0 ){
        int temp = v.front();
        cout << temp << " ";
        v.erase(v.begin());
        
        for(i = 0; i < adj[temp].size(); i++){  // iterate through all unvisited neighbours of the front element and push them in the vector
            if(!visited[adj[temp][i]]){
                visited[adj[temp][i]] = true;
                v.push_back(adj[temp][i]);
            }
        }
        
    }

}

int main() {
    int size;
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
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 1) \n"; 
    bfs(1, size, adj); 
  
    return 0; 
}