//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
#include <string>

class Solution {
  public:
    int countSubstring(std::string &s) {
        std::vector<int> freq(26, 0); // Frequency array for 'a' to 'z'

        // Count frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        int count = 0;

        // Calculate substrings for each character
        for (int f : freq) {
            count += (f * (f + 1)) / 2;
        }

        return count;
    }
};



//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.countSubstring(str) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends