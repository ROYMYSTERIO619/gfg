//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
#include <queue>
#include <climits>
#include <tuple>

using namespace std;

class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        int k = arr.size(); // Number of lists

        // Min-heap: stores {value, row index, col index}
        typedef tuple<int, int, int> T;
        priority_queue<T, vector<T>, greater<T>> minHeap;

        int currentMax = INT_MIN;

        // Initialize the heap with the first element of each list
        for (int i = 0; i < k; i++) {
            int val = arr[i][0];
            minHeap.push(make_tuple(val, i, 0));
            currentMax = max(currentMax, val);
        }

        int rangeStart = 0, rangeEnd = INT_MAX;

        while (true) {
            T top = minHeap.top();
            minHeap.pop();

            int minVal = get<0>(top);
            int row = get<1>(top);
            int col = get<2>(top);

            // Update the smallest range
            if (currentMax - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = currentMax;
            }

            // If more elements are present in the same row
            if (col + 1 < arr[row].size()) {
                int nextVal = arr[row][col + 1];
                minHeap.push(make_tuple(nextVal, row, col + 1));
                currentMax = max(currentMax, nextVal);
            } else {
                // One list exhausted
                break;
            }
        }

        return {rangeStart, rangeEnd};
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends