//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        int result = 0;
        
        // Check every bit position (from 0 to 31)
        for (int i = 0; i < 32; ++i) {
            int bitCount = 0;
            
            for (int num : arr) {
                if (num & (1 << i)) {
                    bitCount++;
                }
            }

            // If bitCount % 3 is not 0, set that bit in result
            if (bitCount % 3 != 0) {
                result |= (1 << i);
            }
        }

        return result;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
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
        int ans = ob.getSingle(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends