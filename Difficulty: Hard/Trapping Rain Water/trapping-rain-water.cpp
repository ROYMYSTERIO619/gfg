//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        if (n < 3) return 0; // No water can be trapped if there are less than 3 blocks

        int left = 0, right = n - 1; // Two pointers
        int left_max = 0, right_max = 0; // Track the maximum heights from both ends
        int water_trapped = 0;

        while (left <= right) {
            if (arr[left] <= arr[right]) {
                if (arr[left] >= left_max) {
                    left_max = arr[left]; // Update left max
                } else {
                    water_trapped += left_max - arr[left]; // Calculate trapped water
                }
                ++left;
            } else {
                if (arr[right] >= right_max) {
                    right_max = arr[right]; // Update right max
                } else {
                    water_trapped += right_max - arr[right]; // Calculate trapped water
                }
                --right;
            }
        }

        return water_trapped;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends