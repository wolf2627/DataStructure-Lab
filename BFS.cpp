#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph {
    int vertices;
    vector<vector<int>> adjList;
public:
    Graph(int v) : vertices(v), adjList(v) {}
    void addEdge(int src, int dest) {
        adjList[src - 1].push_back(dest - 1);
    }
    void BFS(int startVertex);
};
void Graph::BFS(int startVertex) {
    vector<bool> visited(vertices, false);
    queue<int> q;
    cout << "BFS of graph: ";
    q.push(startVertex - 1);
    visited[startVertex - 1] = true;
    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();
        cout << currentVertex + 1 << "\t";
        for (int neighbor : adjList[currentVertex]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}
int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;
    Graph graph(vertices);
    for (int i = 0; i < edges; ++i) {
        int src, dest;
        cout << "Enter source: ";
        cin >> src;
        cout << "Enter destination: ";
        cin >> dest;
        graph.addEdge(src, dest);
    }
    int startVertex;
    cout << "Enter start vertex for BFS: ";
    cin >> startVertex;
    graph.BFS(startVertex);
    return 0;
}