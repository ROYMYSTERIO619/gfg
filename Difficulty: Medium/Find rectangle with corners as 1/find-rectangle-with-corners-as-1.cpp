class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        unordered_set<string> seen;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m - 1; ++j) {
                if (mat[i][j] == 1) {
                    for (int k = j + 1; k < m; ++k) {
                        if (mat[i][k] == 1) {
                            // create a unique key for the column pair
                            string key = to_string(j) + "," + to_string(k);
                            if (seen.count(key)) return true;
                            seen.insert(key);
                        }
                    }
                }
            }
        }
        return false;
    }
};
