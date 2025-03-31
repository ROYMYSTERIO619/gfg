//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPartitions(string &s) {
        unordered_map<char, int> lastPos;

        for (int i = 0; i < s.size(); i++) {
            lastPos[s[i]] = i;
        }

        int partitions = 0, maxLast = 0;

        for (int i = 0; i < s.size(); i++) {
            maxLast = max(maxLast, lastPos[s[i]]);
            if (i == maxLast) { 
                partitions++;
            }
        }

        return partitions;
    }
};



//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends