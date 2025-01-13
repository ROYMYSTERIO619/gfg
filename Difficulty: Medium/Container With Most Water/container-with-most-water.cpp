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
        if (n < 2) return 0; // No water can be contained with less than 2 lines

        int left = 0, right = n - 1; // Two pointers
        int max_area = 0; // To store the maximum area

        while (left < right) {
            // Calculate the current area
            int height = min(arr[left], arr[right]);
            int width = right - left;
            int current_area = height * width;

            // Update the maximum area
            max_area = max(max_area, current_area);

            // Move the pointer corresponding to the shorter line
            if (arr[left] < arr[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return max_area;
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