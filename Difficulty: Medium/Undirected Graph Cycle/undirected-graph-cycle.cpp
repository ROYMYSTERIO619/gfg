//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Find with path compression
    int find(int u, vector<int>& parent) {
        if (parent[u] != u)
            parent[u] = find(parent[u], parent);
        return parent[u];
    }

    // Union by rank
    bool unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        int pu = find(u, parent);
        int pv = find(v, parent);

        if (pu == pv) return true; // Cycle detected

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> parent(V);
        vector<int> rank(V, 0);

        // Initialize parent of each node to itself
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        // Process all edges
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (unionSet(u, v, parent, rank)) {
                return true; // Cycle found
            }
        }

        return false; // No cycle
    }
};



//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends