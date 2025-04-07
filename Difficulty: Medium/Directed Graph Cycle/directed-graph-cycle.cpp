//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(int node, vector<int> graph[], vector<bool> &visited, vector<bool> &inPath) {
        visited[node] = true;
        inPath[node] = true;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, graph, visited, inPath)) return true;
            }
            else if (inPath[neighbor]) {
              
                return true;
            }
        }

        inPath[node] = false;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> graph[V];
        
        // Create adjacency list
        for (auto edge : edges) {
            int from = edge[0];
            int to = edge[1];
            graph[from].push_back(to);
        }

        vector<bool> visited(V, false);
        vector<bool> inPath(V, false); 
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, graph, visited, inPath)) return true;
            }
        }

        return false;
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
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends