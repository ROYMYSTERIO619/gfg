//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        // Create a 2D DP table
        // dp[i][j] will be true if there is a subset of arr[0..i-1] with sum equal to j
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        
        // If sum is 0, then the answer is true (empty subset)
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;
        
        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                // If current element is greater than the sum, skip it
                if (arr[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    // Include or exclude the current element
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
        
        return dp[n][sum];
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends