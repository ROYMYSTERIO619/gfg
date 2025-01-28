//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findPermutation(string &s) {
        vector<string> result;
        string current;
        vector<bool> visited(s.size(), false);

        // Sort the string to handle duplicates
        sort(s.begin(), s.end());

        // Helper function for backtracking
        function<void()> backtrack = [&]() {
            if (current.size() == s.size()) {
                result.push_back(current);
                return;
            }

            for (int i = 0; i < s.size(); i++) {
                // Skip visited characters
                if (visited[i]) continue;

                // Skip duplicates
                if (i > 0 && s[i] == s[i - 1] && !visited[i - 1]) continue;

                // Include this character
                visited[i] = true;
                current.push_back(s[i]);

                // Recurse
                backtrack();

                // Backtrack
                current.pop_back();
                visited[i] = false;
            }
        };

        // Start backtracking
        backtrack();

        return result;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends