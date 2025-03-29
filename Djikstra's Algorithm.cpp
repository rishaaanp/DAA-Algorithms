#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int minDistance(vector<int>& dist, vector<bool>& sptSet, int V) {
int min = INT_MAX, min_index;
for (int v = 0; v < V; v++)
if (sptSet[v] == false && dist[v] <= min)
min = dist[v], min_index = v;
return min_index;
}
void printSolution(vector<int>& dist, int V) {
cout << "Vertex \t Distance from Source" << endl;
for (int i = 0; i < V; i++)
cout << i << " \t\t" << dist[i] << endl;
}
void dijkstra(vector<vector<int>>& graph, int src, int V) {
vector<int> dist(V, INT_MAX);
vector<bool> sptSet(V, false);
dist[src] = 0;
for (int count = 0; count < V - 1; count++) {
int u = minDistance(dist, sptSet, V);
sptSet[u] = true;
for (int v = 0; v < V; v++)
if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
&& dist[u] + graph[u][v] < dist[v])
dist[v] = dist[u] + graph[u][v];
}
printSolution(dist, V);
}
int main() {
    int V, E;
cout << "Enter the number of vertices: ";
cin >> V;
cout << "Enter the number of edges: ";
cin >> E;
vector<vector<int>> graph(V, vector<int>(V, 0));
cout << "Enter the edges (start end weight):" << endl;
for (int i = 0; i < E; i++) {
int u, v, w;
cin >> u >> v >> w;
graph[u][v] = w;
graph[v][u] = w;
}
int src;
cout << "Enter the source vertex: ";
cin >> src;
dijkstra(graph, src, V);
return 0;}