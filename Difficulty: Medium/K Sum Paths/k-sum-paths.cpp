//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
public:
    int countPaths(Node* root, int k, long long currentSum, unordered_map<long long, int>& prefixSumCount) {
        if (!root) return 0;

        currentSum += root->data;
        int count = 0;

        // Check if there's a prefix sum that satisfies the condition
        if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
            count += prefixSumCount[currentSum - k];
        }

        // Include the current sum in the prefix map
        prefixSumCount[currentSum]++;

        // Recur for left and right subtrees
        count += countPaths(root->left, k, currentSum, prefixSumCount);
        count += countPaths(root->right, k, currentSum, prefixSumCount);

        // Backtrack: remove the current sum from the map
        prefixSumCount[currentSum]--;

        return count;
    }

    int sumK(Node* root, int k) {
        unordered_map<long long, int> prefixSumCount;
        prefixSumCount[0] = 1; // For paths starting directly from the root
        return countPaths(root, k, 0, prefixSumCount);
    }
};

//{ Driver Code Starts.

int main() {
    string tc;
    getline(cin, tc);
    int t = stoi(tc);

    while (t--) {
        string s, ch;
        getline(cin, s);
        Node *root = buildTree(s);

        string key;
        getline(cin, key);
        int k = stoi(key);
        Solution ob;
        cout << ob.sumK(root, k) << "\n";
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends