/*
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
}; */

class Solution {
  public:
    int maxLen = 0;
    int maxSum = 0;

    void dfs(Node* node, int currSum, int currLen) {
        if (!node) return;

        currSum += node->data;
        currLen++;

        if (!node->left && !node->right) { // If it's a leaf
            if (currLen > maxLen) {
                maxLen = currLen;
                maxSum = currSum;
            } else if (currLen == maxLen) {
                maxSum = max(maxSum, currSum);
            }
            return;
        }

        dfs(node->left, currSum, currLen);
        dfs(node->right, currSum, currLen);
    }

    int sumOfLongRootToLeafPath(Node *root) {
        dfs(root, 0, 0);
        return maxSum;
    }
};
