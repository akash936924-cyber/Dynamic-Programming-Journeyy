// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// int main() {

//     int n = 9;

//     vector<vector<int>> adj(n + 1);

//     // Graph
//     adj[1] = {2, 8};
//     adj[2] = {1, 3, 4};
//     adj[3] = {2};
//     adj[4] = {2, 5};
//     adj[5] = {4, 6};
//     adj[6] = {5, 7};
//     adj[7] = {6, 8};
//     adj[8] = {1, 7, 9};
//     adj[9] = {8};

//     vector<int> vis(n + 1, 0);

//     queue<int> q;

//     // Starting node = 1
//     q.push(1);
//     vis[1] = 1;

//     while (!q.empty()) {

//         int node = q.front();
//         q.pop();

//         cout << node << " ";

//         for (int neighbour : adj[node]) {

//             if (!vis[neighbour]) {

//                 vis[neighbour] = 1;
//                 q.push(neighbour);
//             }
//         }
//     }

//     return 0;
// }


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int n, e;
    cin >> n >> e;

    vector<vector<int>> adj(n + 1);

    // Edges input
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cin >> start;

    vector<int> vis(n + 1, 0);
    queue<int> q;

    q.push(start);
    vis[start] = 1;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbour : adj[node]) {

            if (!vis[neighbour]) {
                vis[neighbour] = 1;
                q.push(neighbour);
            }
        }
    }

    return 0;
}