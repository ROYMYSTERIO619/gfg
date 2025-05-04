//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        int n = str.size();
        unordered_set<char> unique_chars(str.begin(), str.end());
        int total_unique = unique_chars.size();

        unordered_map<char, int> window_count;
        int min_len = n + 1;
        int start = 0, count = 0;

        for (int end = 0; end < n; ++end) {
            window_count[str[end]]++;

            // Count the character only if it's the first time in window
            if (window_count[str[end]] == 1) {
                count++;
            }

            // Try to shrink the window
            while (count == total_unique) {
                min_len = min(min_len, end - start + 1);
                window_count[str[start]]--;

                if (window_count[str[start]] == 0) {
                    count--;
                }
                start++;
            }
        }

        return min_len;
    }
};



//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends