//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            // Pop elements from stack while the stack is not empty and the current price is greater than stack's top price
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            
            // If stack is empty, then price[i] is greater than all previous prices
            span[i] = st.empty() ? (i + 1) : (i - st.top());
            
            // Push this element's index to stack
            st.push(i);
        }
        
        return span;
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
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends