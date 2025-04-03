//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
#include <queue>
#include <utility> // for std::pair

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        std::queue<std::pair<int, int>> q;
        int freshCount = 0;

        // Initialize the queue with all rotten oranges and count fresh oranges
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 2) {
                    q.push({i, j});
                } else if (mat[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        // Directions for adjacent cells (up, down, left, right)
        std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int time = 0;

        // BFS to rot the oranges
        while (!q.empty() && freshCount > 0) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                std::pair<int, int> current = q.front();
                q.pop();
                int x = current.first; // Get the x coordinate
                int y = current.second; // Get the y coordinate

                // Check all four directions
                for (auto& dir : directions) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    // Check if the new position is valid and has a fresh orange
                    if (newX >= 0 && newX < n && newY >= 0 && newY < m && mat[newX][newY] == 1) {
                        mat[newX][newY] = 2; // Rot the fresh orange
                        q.push({newX, newY}); // Add to queue
                        freshCount--; // Decrease the count of fresh oranges
                    }
                }
            }
            time++; // Increment time after processing all rotten oranges at this level
        }

        // If there are still fresh oranges left, return -1
        return freshCount == 0 ? time : -1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends