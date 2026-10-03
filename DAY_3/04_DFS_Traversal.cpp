#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;

void dfs(int node) {

    // Current node ko visited mark karo
    vis[node] = 1;

    // Node print karo
    cout << node << " ";

    // Current node ke saare neighbours dekho
    for (int neighbour : adj[node]) {

        // Agar neighbour visited nahi hai
        if (!vis[neighbour]) {

            // Us neighbour par DFS chalao
            dfs(neighbour);
        }
    }
}

int main() {

    int n, e;

    // Number of nodes and edges
    cin >> n >> e;

    // Adjacency list
    adj.resize(n + 1);

    // Graph input
    for (int i = 0; i < e; i++) {

        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Starting node
    int start;
    cin >> start;

    // Visited array
    vis.resize(n + 1, 0);

    // DFS
    dfs(start);

    return 0;
}