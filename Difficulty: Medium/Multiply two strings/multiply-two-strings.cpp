//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string multiplyStrings(string& s1, string& s2) {
        // Handle if any number is zero
        if (s1 == "0" || s2 == "0") return "0";
        
        // Check signs
        bool negative = false;
        if (s1[0] == '-') {
            negative = !negative;
            s1 = s1.substr(1);
        }
        if (s2[0] == '-') {
            negative = !negative;
            s2 = s2.substr(1);
        }

        // Remove leading zeros
        while (s1.length() > 1 && s1[0] == '0') s1.erase(0, 1);
        while (s2.length() > 1 && s2[0] == '0') s2.erase(0, 1);

        int n = s1.size(), m = s2.size();
        vector<int> result(n + m, 0);

        // Multiply each digit
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int sum = mul + result[i + j + 1];

                result[i + j] += sum / 10;
                result[i + j + 1] = sum % 10;
            }
        }

        // Convert vector to string
        string ans;
        for (int num : result) {
            if (!(ans.empty() && num == 0)) { // Skip leading zeros
                ans.push_back(num + '0');
            }
        }
        
        if (ans.empty()) return "0";
        if (negative) ans = '-' + ans;

        return ans;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends