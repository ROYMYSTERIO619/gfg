//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int node, int &time, vector<int> adj[], vector<bool> &visited,
             vector<int> &disc, vector<int> &low, vector<int> &parent,
             vector<bool> &isArticulation) {

        visited[node] = true;
        disc[node] = low[node] = time++;
        int childCount = 0;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                parent[neighbor] = node;
                childCount++;

                dfs(neighbor, time, adj, visited, disc, low, parent, isArticulation);

                low[node] = min(low[node], low[neighbor]);

                // Articulation condition for non-root node
                if (parent[node] != -1 && low[neighbor] >= disc[node])
                    isArticulation[node] = true;

                // Special case for root node
                if (parent[node] == -1 && childCount > 1)
                    isArticulation[node] = true;
            }
            else if (neighbor != parent[node]) {
                low[node] = min(low[node], disc[neighbor]);
            }
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(V, false);
        vector<int> disc(V), low(V), parent(V, -1);
        vector<bool> isArticulation(V, false);

        int time = 0;

        // Call DFS for all disconnected components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, time, adj, visited, disc, low, parent, isArticulation);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (isArticulation[i])
                result.push_back(i);
        }

        if (result.empty()) return {-1};
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends