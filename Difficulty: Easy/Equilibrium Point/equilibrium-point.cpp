//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        long long totalSum = 0, leftSum = 0;

        // Calculate the total sum of the array
        for (int num : arr) {
            totalSum += num;
        }

        // Traverse the array and check for equilibrium index
        for (int i = 0; i < arr.size(); i++) {
            if (leftSum == totalSum - leftSum - arr[i]) {
                return i; // Equilibrium index found
            }
            leftSum += arr[i];
        }

        return -1; // No equilibrium index found
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends