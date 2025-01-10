//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> result;
        unordered_map<int, int> freqMap;
        int n = arr.size();

        // Initialize the frequency map for the first window
        for (int i = 0; i < k; ++i) {
            freqMap[arr[i]]++;
        }
        result.push_back(freqMap.size());

        // Slide the window across the array
        for (int i = k; i < n; ++i) {
            // Remove the first element of the previous window
            int elementToRemove = arr[i - k];
            freqMap[elementToRemove]--;
            if (freqMap[elementToRemove] == 0) {
                freqMap.erase(elementToRemove);
            }

            // Add the new element of the current window
            int elementToAdd = arr[i];
            freqMap[elementToAdd]++;

            // Store the count of distinct elements
            result.push_back(freqMap.size());
        }

        return result;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends