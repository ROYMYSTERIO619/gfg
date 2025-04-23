//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        int xor_all = 0;

        // Step 1: XOR all elements
        for (int num : arr) {
            xor_all ^= num;
        }

        // Step 2: Find rightmost set bit (this bit is different between the two unique numbers)
        int diff_bit = xor_all & -xor_all;

        int x = 0, y = 0;

        // Step 3: Divide elements into two groups and XOR separately
        for (int num : arr) {
            if (num & diff_bit)
                x ^= num; // group with the bit set
            else
                y ^= num; // group with the bit not set
        }

        // Step 4: Return the result in increasing order
        if (x < y)
            return {x, y};
        else
            return {y, x};
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

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends