#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1000000; // Representasi nilai tak hingga
vector<pair<int, int>> graph[100]; // Array of pair untuk menyimpan {tetangga, bobot}

void dijkstra(int start, int V) {
    vector<int> dist(V, INF);
    // Priority queue untuk mengambil bobot terkecil secara otomatis
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start}); // Menyimpan {jarak, vertex}

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            // Relaksasi Edge: Cek apakah ada jalur yang lebih murah/pendek
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "=== Jarak Terpendek dari Vertex " << start << " ===\n";
    for (int i = 0; i < V; i++) {
        cout << "Ke Vertex " << i << " : " << dist[i] << endl;
    }
}

int main() {
    int V = 3; // Misal ada 3 kota (0: Surabaya, 1: Sidoarjo, 2: Gresik)
    
    // Hubungkan kota beserta bobotnya (jarak)
    graph[0].push_back({1, 5}); // Surabaya -> Sidoarjo (5km)
    graph[1].push_back({0, 5}); 
    graph[0].push_back({2, 3}); // Surabaya -> Gresik (3km)
    graph[2].push_back({0, 3});

    dijkstra(0, V); // Cari rute terpendek dimulai dari Surabaya (0)
    return 0;
}
