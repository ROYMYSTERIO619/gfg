//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<bool> &visited) {
        visited[node] = true;
        for (int nbr : adj[node]) {
            if (!visited[nbr]) {
                dfs(nbr, adj, visited);
            }
        }
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Step 1: Create adjacency list
        vector<int> adj[V];
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Remove edge (c, d) temporarily
        for (auto it = adj[c].begin(); it != adj[c].end(); ++it) {
            if (*it == d) {
                adj[c].erase(it);
                break;
            }
        }
        for (auto it = adj[d].begin(); it != adj[d].end(); ++it) {
            if (*it == c) {
                adj[d].erase(it);
                break;
            }
        }

        // Step 3: Run DFS from c (or any node)
        vector<bool> visited(V, false);
        dfs(c, adj, visited);

        // Step 4: If d is not visited, edge is a bridge
        return !visited[d];
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends