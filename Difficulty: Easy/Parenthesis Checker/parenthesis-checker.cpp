//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBalanced(string& s) {
        stack<char> st;

        // Map to check corresponding closing brackets
        unordered_map<char, char> bracketMap = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char ch : s) {
            // If it's an opening bracket, push to stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            // If it's a closing bracket
            else if (ch == ')' || ch == '}' || ch == ']') {
                // Check if stack is non-empty and top matches the required opening bracket
                if (!st.empty() && st.top() == bracketMap[ch]) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        // If stack is empty, all brackets were matched
        return st.empty();
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends