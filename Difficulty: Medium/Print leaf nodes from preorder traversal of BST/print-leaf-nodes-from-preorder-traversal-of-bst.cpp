class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        vector<int> leaf;
        int i = 0;
        findLeaves(preorder, i, INT_MIN, INT_MAX, leaf);
        return leaf;
    }

  private:
    void findLeaves(vector<int>& pre, int& i, int min, int max, vector<int>& leaf) {
        if (i >= pre.size() || pre[i] < min || pre[i] > max)
            return;

        int val = pre[i++];
        int indexBeforeLeft = i;
        
        // Left subtree: values < val
        findLeaves(pre, i, min, val - 1, leaf);
        // Right subtree: values > val
        findLeaves(pre, i, val + 1, max, leaf);
        
        // If no left or right subtree values were processed, it's a leaf
        if (i == indexBeforeLeft)
            leaf.push_back(val);
    }
};
