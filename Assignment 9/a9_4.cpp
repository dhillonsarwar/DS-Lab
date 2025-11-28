#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

class MinHeap {
public:
    vector<int> heap;   
    vector<int> dist;  

    MinHeap(int n, vector<int>& distRef) : dist(distRef) {
        heap.resize(n);
        for(int i=0;i<n;i++) heap[i]=i;
        size=n;
    }

    int size;

    void heapify(int i) {
        int smallest=i;
        int left=2*i+1, right=2*i+2;

        if(left < size && dist[heap[left]] < dist[heap[smallest]])
            smallest=left;

        if(right < size && dist[heap[right]] < dist[heap[smallest]])
            smallest=right;

        if(smallest!=i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    int extractMin() {
        if(size <= 0) return -1;

        int root = heap[0];
        heap[0] = heap[size-1];
        size--;
        heapify(0);

        return root;
    }

    void decreaseKey(int vertex) {
        // Bubble up
        int i = find(vertex);
        while(i>0 && dist[heap[i]] < dist[heap[(i-1)/2]]) {
            swap(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }

   
    int find(int v){
        for(int i=0;i<size;i++)
            if(heap[i]==v) return i;
        return -1;
    }

    bool contains(int v){
        return find(v) < size && find(v) != -1;
    }
};


void dijkstra(vector<vector<int>>& graph, int src) {
    int V = graph.size();
    vector<int> dist(V, INF);
    vector<bool> visited(V, false);

    dist[src]=0;
    MinHeap minHeap(V, dist);

   
    while(minHeap.size > 0) {
        int u = minHeap.extractMin();

        if(visited[u]) continue;
        visited[u]=true;

        for(int v=0; v<V; v++) {
            if(graph[u][v] != 0 && !visited[v] && dist[u] != INF &&
               dist[u] + graph[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + graph[u][v];
                minHeap.decreaseKey(v);
            }
        }
    }

   
    cout << "\nVertex   Distance from Source\n";
    for(int i=0;i<V;i++)
        cout << i << "\t\t" << dist[i] << endl;
}


int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "\nEnter adjacency matrix (" << V << "x" << V << "):\n";
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            cin >> graph[i][j];

    int src;
    cout << "\nEnter source vertex: ";
    cin >> src;

    dijkstra(graph, src);

    return 0;
}
