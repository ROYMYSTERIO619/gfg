//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int left = 0, right = 0;
        multiset<int> window;  // Keeps track of elements in current window
        int maxLen = 0, startIdx = 0;

        while (right < arr.size()) {
            // Insert current element into multiset
            window.insert(arr[right]);

            // Check the min and max values in the current window
            while (*window.rbegin() - *window.begin() > x) {
                // If condition fails, remove the leftmost element and move left pointer
                window.erase(window.find(arr[left]));
                left++;
            }

            // Update the longest subarray if found
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                startIdx = left;
            }

            // Move right pointer
            right++;
        }

        // Return the longest valid subarray
        return vector<int>(arr.begin() + startIdx, arr.begin() + startIdx + maxLen);
    }
};



//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends