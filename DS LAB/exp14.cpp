
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<int> adj[100];

public:
    Graph(int vertices) {
        V = vertices;
    }

    // Add edge
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS Traversal
    void DFSUtil(int vertex, bool visited[]) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adj[vertex]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int start) {
        bool visited[100] = {false};

        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // BFS Traversal
    void BFS(int start) {
        bool visited[100] = {false};
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();

            cout << vertex << " ";

            for (int neighbor : adj[vertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    int V, E, u, v, start;

    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    g.DFS(start);
    g.BFS(start);

    return 0;
}
