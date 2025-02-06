//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



class Solution {
    unordered_map<int, int> inorderMap; // To store the indices of inorder elements
    int preIndex = 0; // Index to keep track of preorder traversal

    // Helper function to build the tree
    Node* buildTreeHelper(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        // Get the current root from preorder
        int rootVal = preorder[preIndex++];
        Node* root = new Node(rootVal);

        // If the node has no children
        if (inStart == inEnd) return root;

        // Find the index of the root in inorder traversal
        int inIndex = inorderMap[rootVal];

        // Build left and right subtrees
        root->left = buildTreeHelper(inorder, preorder, inStart, inIndex - 1);
        root->right = buildTreeHelper(inorder, preorder, inIndex + 1, inEnd);

        return root;
    }

public:
    // Function to build the tree from given inorder and preorder traversals
    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        inorderMap.clear();
        preIndex = 0;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return buildTreeHelper(inorder, preorder, 0, inorder.size() - 1);
    }

    // Function to print postorder traversal
    void printPostorder(Node* node) {
        if (node == nullptr) return;
        printPostorder(node->left);
        printPostorder(node->right);
        cout << node->data << " ";
    }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends