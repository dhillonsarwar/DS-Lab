#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;

    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    adj.assign(V, vector<int>());
    visited.assign(V, false);

    // Input edges
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);   // undirected graph
    }

    int components = 0;

    // Check all vertices
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {     // Unvisited node means a new component
            components++;
            dfs(i);
        }
    }

    cout << components << endl;
}
