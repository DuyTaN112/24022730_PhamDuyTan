#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int n;                    
    bool directed;              
    vector<vector<int>> adj;   

public:
    Graph(int n, bool directed = false) {
        this->n = n;
        this->directed = directed;
        adj.assign(n, vector<int>(n, 0));
    }

    void addEdge(int u, int v, int w = 1) {
        adj[u][v] = w;
        if (!directed) adj[v][u] = w;
    }

    void removeEdge(int u, int v) {
        adj[u][v] = 0;
        if (!directed) adj[v][u] = 0;
    }

    void printMatrix() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << adj[i][j] << " ";
            cout << "\n";
        }
    }

    void BFS(int start) {
        vector<bool> visited(n, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS: ";

        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << " ";

            for (int v = 0; v < n; v++) {
                if (adj[u][v] != 0 && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << "\n";
    }

    void DFSUtil(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";

        for (int v = 0; v < n; v++) {
            if (adj[u][v] != 0 && !visited[v])
                DFSUtil(v, visited);
        }
    }

    void DFS(int start) {
        vector<bool> visited(n, false);
        cout << "DFS: ";
        DFSUtil(start, visited);
        cout << "\n";
    }
};

int main() {
    Graph g(5, false); 

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.printMatrix();

    g.BFS(0);
    g.DFS(0);

    return 0;
}
