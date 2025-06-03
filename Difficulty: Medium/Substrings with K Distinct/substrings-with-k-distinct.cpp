class Solution {
  public:
    int countAtMostK(string& s, int k) {
        unordered_map<char, int> freq;
        int left = 0, right = 0, count = 0;
        
        for (right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            
            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }
            
            count += (right - left + 1);
        }
        
        return count;
    }
    
    int countSubstr(string& s, int k) {
        return countAtMostK(s, k) - countAtMostK(s, k - 1);
    }
};
