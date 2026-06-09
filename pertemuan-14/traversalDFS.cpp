#include <iostream>
#include <vector>

using namespace std;

class GraphDFS {
private:
    int V;
    vector<vector<int>> adj;
    vector<bool> visited;

public:
    GraphDFS(int vertices) {
        V = vertices;
        adj.resize(V);
        visited.resize(V, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int v) {
        visited[v] = true;
        cout << v << " ";

        for (int u : adj[v]) {
            if (!visited[u]) {
                DFS(u); // Memanggil dirinya sendiri (Rekursif)
            }
        }
    }
};

int main() {
    GraphDFS g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "Hasil Traversal DFS: ";
    g.DFS(0); // Output: 0 1 3 2 4
    cout << endl;

    return 0;
}
