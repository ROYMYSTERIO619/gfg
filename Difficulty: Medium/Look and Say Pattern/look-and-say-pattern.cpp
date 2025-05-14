//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        if (n == 1) return "1"; // Base case

        string prev = countAndSay(n - 1); // Recursively get the (n-1)th term
        string result = "";

        int count = 1;
        for (int i = 1; i < prev.size(); i++) {
            if (prev[i] == prev[i - 1]) {
                count++; // Increment count if the same digit continues
            } else {
                result += to_string(count) + prev[i - 1]; // Append count and digit
                count = 1; // Reset count for the new digit
            }
        }
        result += to_string(count) + prev.back(); // Append the last counted digit

        return result;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends