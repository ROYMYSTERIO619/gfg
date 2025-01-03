//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        int xorValue = 0;
        long count = 0;

        for (int num : arr) {
            xorValue ^= num;
            if (xorValue == k) {
                count++;
            }
            int desiredXor = xorValue ^ k;
            if (freq.find(desiredXor) != freq.end()) {
                count += freq[desiredXor];
            }
            freq[xorValue]++;
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends