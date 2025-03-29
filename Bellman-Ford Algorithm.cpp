#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct Edge {
int u, v, weight;
};
void bellmanFord(int V, int E, vector<Edge>& edges, int src) {
vector<int> dist(V, INT_MAX); 
dist[src] = 0; 

for (int i = 1; i <= V - 1; i++) {
for (int j = 0; j < E; j++) {
int u = edges[j].u;
int v = edges[j].v;
int weight = edges[j].weight;
if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
dist[v] = dist[u] + weight;
}
}
}
// Check for negative-weight cycles
for (int j = 0; j < E; j++) {
int u = edges[j].u;
int v = edges[j].v;
int weight = edges[j].weight;
if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
cout << "Graph contains a negative weight cycle" << endl;
return;
}
}
cout << "Vertex\tDistance from Source" << endl;
for (int i = 0; i < V; i++) {
cout << i << "\t\t" << dist[i] << endl;
}
}
int main() {
int V, E, src;
cout << "Enter the number of vertices: ";
cin >> V;
cout << "Enter the number of edges: ";
cin >> E;
vector<Edge> edges(E);
cout << "Enter the edges (u v weight):" << endl;
for (int i = 0; i < E; i++) {
cin >> edges[i].u >> edges[i].v >> edges[i].weight;
}
cout << "Enter the source vertex: ";
cin >> src;
bellmanFord(V, E, edges, src);
return 0;}
