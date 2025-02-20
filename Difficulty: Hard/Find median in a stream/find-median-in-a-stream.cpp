//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // Max-Heap for the lower half
        priority_queue<int> maxHeap;
        
        // Min-Heap for the upper half
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        vector<double> medians;
        
        for (int num : arr) {
            // Step 1: Add number to Max-Heap
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }
            
            // Step 2: Rebalance the heaps
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            
            // Step 3: Calculate the median
            if (maxHeap.size() > minHeap.size()) {
                medians.push_back(maxHeap.top());
            } else {
                double median = (maxHeap.top() + minHeap.top()) / 2.0;
                medians.push_back(median);
            }
        }
        
        return medians;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends