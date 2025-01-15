//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<long long, int> prefixSum; // Stores prefix sum and its first occurrence index
        long long currentSum = 0;
        int maxLength = 0;

        for (int i = 0; i < arr.size(); i++) {
            currentSum += arr[i];

            // Check if the current sum equals k
            if (currentSum == k) {
                maxLength = i + 1; // Subarray starts from the beginning
            }

            // Check if currentSum - k exists in the prefix sum map
            if (prefixSum.find(currentSum - k) != prefixSum.end()) {
                maxLength = max(maxLength, i - prefixSum[currentSum - k]);
            }

            // Store the current sum in the map if not already present
            if (prefixSum.find(currentSum) == prefixSum.end()) {
                prefixSum[currentSum] = i;
            }
        }

        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends