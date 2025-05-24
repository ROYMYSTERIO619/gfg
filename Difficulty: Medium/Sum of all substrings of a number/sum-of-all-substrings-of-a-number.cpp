class Solution {
  public:
    int sumSubstrings(string &s) {
        int n = s.size();
        long long total = 0;
        long long prev = 0;
        int mod = 1e9 + 7; // Not necessary here, but safe for larger constraints
        
        for (int i = 0; i < n; ++i) {
            int digit = s[i] - '0';
            long long curr = (prev * 10 + digit * (i + 1));
            total += curr;
            prev = curr;
        }
        
        return (int)total; // Safe cast because total fits in 32-bit int as guaranteed
    }
};
