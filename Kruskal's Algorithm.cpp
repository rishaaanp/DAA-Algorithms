#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class DSU {
int* parent;
int* rank;
public:
DSU(int n) {
parent = new int[n];
rank = new int[n];
for (int i = 0; i < n; i++) {
parent[i] = -1;
rank[i] = 1;
} }
int find(int i) {
if (parent[i] == -1)
return i;
return parent[i] = find(parent[i]);
}
void unite(int x, int y) {
int s1 = find(x);
int s2 = find(y);
if (s1 != s2) {
if (rank[s1] < rank[s2]) {
parent[s1] = s2;
} else if (rank[s1] > rank[s2]) {
parent[s2] = s1;
} else {
parent[s2] = s1;
rank[s1] += 1;
}
}
}
};
class Graph {
vector<vector<int>> edges;
int V;
public:
Graph(int V) {
this->V = V;
}
void addEdge(int u, int v, int w) {
edges.push_back({w, u, v});
}
void kruskals_mst() {
sort(edges.begin(), edges.end());
DSU s(V);
int mstWeight = 0;
cout << "Following are the edges in the constructed MST:" << endl;
for (auto& edge : edges) {
int w = edge[0];
int u = edge[1];
int v = edge[2];
if (s.find(u) != s.find(v)) {
    s.unite(u, v);
mstWeight += w;
cout << u << " -- " << v << " == " << w << endl;
}}
cout << "Minimum Cost Spanning Tree: " << mstWeight << endl;
}};
int main() {
int V, E;
cout << "Enter the number of vertices: ";
cin >> V;
cout << "Enter the number of edges: ";
cin >> E;
Graph g(V);
for (int i = 0; i < E; i++) {
int u, v, w;
cout << "Enter edge (u, v) and weight (w): ";
cin >> u >> v >> w;
g.addEdge(u, v, w);
}
g.kruskals_mst();
return 0;
}