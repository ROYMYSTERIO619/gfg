//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> firstSeen;
        int prefix = 0, maxLen = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > k) prefix += 1;
            else prefix -= 1;

            if (prefix > 0) maxLen = i + 1;
            else {
                if (firstSeen.find(prefix - 1) != firstSeen.end()) {
                    maxLen = max(maxLen, i - firstSeen[prefix - 1]);
                }
            }

            if (firstSeen.find(prefix) == firstSeen.end()) {
                firstSeen[prefix] = i;
            }
        }

        return maxLen;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends