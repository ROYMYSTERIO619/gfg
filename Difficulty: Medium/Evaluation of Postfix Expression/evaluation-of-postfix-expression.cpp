//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evaluate(vector<string>& arr) {
        stack<int> st;
        
        // Traverse through each token in the array
        for (string& token : arr) {
            // If the token is an operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop the top two elements
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                // Apply the operator and push the result back
                if (token == "+") {
                    st.push(a + b);
                } else if (token == "-") {
                    st.push(a - b);
                } else if (token == "*") {
                    st.push(a * b);
                } else if (token == "/") {
                    st.push(a / b);  // Division rounds towards zero in C++
                }
            }
            // Otherwise, the token is an operand (integer)
            else {
                st.push(stoi(token));
            }
        }
        
        // The result is the only element left in the stack
        return st.top();
    }
};





//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends