//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    struct TrieNode {
        TrieNode* child[2] = {nullptr, nullptr};
    };
    
    void insert(TrieNode* root, int num) {
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!root->child[bit]) {
                root->child[bit] = new TrieNode();
            }
            root = root->child[bit];
        }
    }

    int getMaxXor(TrieNode* root, int num) {
        int maxXor = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int oppBit = 1 - bit;
            if (root->child[oppBit]) {
                maxXor |= (1 << i);
                root = root->child[oppBit];
            } else {
                root = root->child[bit];
            }
        }
        return maxXor;
    }

    int maxXor(vector<int> &arr) {
        TrieNode* root = new TrieNode();
        int result = 0;

        for (int num : arr) {
            insert(root, num);
        }

        for (int num : arr) {
            result = max(result, getMaxXor(root, num));
        }

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

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends