//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodedString(string &s) {
        stack<int> numStack;
        stack<string> strStack;
        string currentStr = "";
        int num = 0;
        
        for (char ch : s) {
            if (isdigit(ch)) {
                // If it's a digit, calculate the complete number
                num = num * 10 + (ch - '0');
            } 
            else if (ch == '[') {
                // Push current number and current string to stacks
                numStack.push(num);
                strStack.push(currentStr);
                // Reset for the next segment
                num = 0;
                currentStr = "";
            } 
            else if (ch == ']') {
                // Pop the repeat count
                int repeatTimes = numStack.top(); numStack.pop();
                // Repeat the current string
                string temp = "";
                for (int i = 0; i < repeatTimes; i++) {
                    temp += currentStr;
                }
                // Pop the last string and combine with the repeated part
                currentStr = strStack.top() + temp;
                strStack.pop();
            } 
            else {
                // It's a character, append to currentStr
                currentStr += ch;
            }
        }
        
        return currentStr;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends