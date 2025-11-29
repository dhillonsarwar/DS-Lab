#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = LLONG_MAX;

ll minCost(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int total = m * n;

    vector<vector<pair<int,int>>> adj(total);
    
    for(int r=0; r<m; r++){
        for(int c=0; c<n; c++){
            int id = r*n + c;
            if(r+1<m) adj[id].push_back({(r+1)*n + c, grid[r+1][c]});
            if(r-1>=0) adj[id].push_back({(r-1)*n + c, grid[r-1][c]});
            if(c+1<n) adj[id].push_back({r*n + (c+1), grid[r][c+1]});
            if(c-1>=0) adj[id].push_back({r*n + (c-1), grid[r][c-1]});
        }
    }

    vector<ll> dist(total, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

    dist[0] = grid[0][0];
    pq.push({dist[0], 0});

    while(!pq.empty()) {
        auto [cost,u] = pq.top();
        pq.pop();

        if(cost > dist[u]) continue;
        if(u == total-1) return cost;

        for(auto &edge : adj[u]) {
            int v = edge.first;
            ll w = edge.second;
            if(cost + w < dist[v]) {
                dist[v] = cost + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[total-1];
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];

    cout << minCost(grid);
}
