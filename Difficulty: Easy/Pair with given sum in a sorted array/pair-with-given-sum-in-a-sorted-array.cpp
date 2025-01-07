//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
#include <vector>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        int count = 0;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == target) {
                // Count duplicates if arr[left] and arr[right] have multiples
                if (arr[left] == arr[right]) {
                    int freq = right - left + 1;
                    count += (freq * (freq - 1)) / 2; // Combination of freq elements
                    break;
                } else {
                    int leftCount = 1, rightCount = 1;
                    
                    // Count duplicates for arr[left]
                    while (left < right && arr[left] == arr[left + 1]) {
                        left++;
                        leftCount++;
                    }
                    
                    // Count duplicates for arr[right]
                    while (left < right && arr[right] == arr[right - 1]) {
                        right--;
                        rightCount++;
                    }
                    
                    count += leftCount * rightCount;
                    left++;
                    right--;
                }
            } else if (sum < target) {
                left++; // Increase the sum
            } else {
                right--; // Decrease the sum
            }
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
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends