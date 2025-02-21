//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <stack>
#include <string>
using namespace std;

class Solution {
  public:
    int maxLength(string& s) {
        stack<int> st;
        st.push(-1); // Base case for first valid substring
        
        int maxLength = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i); // Push index of '('
            } else {
                st.pop(); // Pop the last '(' or base index
                
                if (!st.empty()) {
                    // Calculate length of current valid substring
                    maxLength = max(maxLength, i - st.top());
                } else {
                    // No matching '(', push current index as base for next substring
                    st.push(i);
                }
            }
        }
        
        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends