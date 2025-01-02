//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> prefixSumCount; 
        int count = 0;
        int prefixSum = 0;
        prefixSumCount[0] = 1;

        for (int num : arr) {
            prefixSum += num;

            
            if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[prefixSum - k];
            }
            prefixSumCount[prefixSum]++;
        }

        return count;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends