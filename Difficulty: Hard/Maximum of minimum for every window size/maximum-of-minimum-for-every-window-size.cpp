//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, n); // Next Smaller Element
        vector<int> pse(n, -1); // Previous Smaller Element
        stack<int> s;
        
        // Finding PSE (Previous Smaller Element)
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                pse[i] = s.top();
            }
            s.push(i);
        }
        
        // Clear stack for NSE calculation
        while (!s.empty()) s.pop();
        
        // Finding NSE (Next Smaller Element)
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                nse[i] = s.top();
            }
            s.push(i);
        }
        
        // Result array to store maximum of minimums for every window size
        vector<int> res(n + 1, 0);
        
        // Calculate the length of the window in which each element is minimum
        for (int i = 0; i < n; i++) {
            int len = nse[i] - pse[i] - 1;
            res[len] = max(res[len], arr[i]);
        }
        
        // Fill the rest of the result array
        for (int i = n - 1; i >= 1; i--) {
            res[i] = max(res[i], res[i + 1]);
        }
        
        // Remove the first element as we need sizes from 1 to n
        res.erase(res.begin());
        
        return res;
    }
};





//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends