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

        vector <int>:: iterator i;
        for(i = adj[temp].begin(); i != adj[temp].end(); i++){  // iterate through all unvisited neighbours of the front element and push them in the vector
            if(!visited[*i]){
                visited[*i] = true;
                v.push_back(*i);
            }
        }
        
    }

}

int main() {
    int size;
    cin >> size;
    vector <int> adj[size];
    
    addEdge(0, 1, adj); 
    addEdge(0, 2, adj); 
    addEdge(1, 2, adj); 
    addEdge(2, 0, adj); 
    addEdge(2, 3, adj); 
    addEdge(3, 3, adj); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    bfs(2, size, adj); 
  
    return 0; 
}