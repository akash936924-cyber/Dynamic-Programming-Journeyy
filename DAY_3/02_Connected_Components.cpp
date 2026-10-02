#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;

void dfs(int node) {
    vis[node] = 1;

    for (int neighbour : adj[node]) {
        if (!vis[neighbour]) {
            dfs(neighbour);
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    vis.resize(n + 1, 0);

    // Graph input
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int components = 0;

    // Har node ko check karo
    for (int i = 1; i <= n; i++) {

        if (!vis[i]) {
            components++;
            dfs(i);
        }
    }

    cout << components << endl;

    return 0;
}