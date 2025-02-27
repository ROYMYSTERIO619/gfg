//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    stack<int> s;
    stack<int> minStack;

public:
    // Constructor
    Solution() {}

    // Add an element to the top of the stack
    void push(int x) {
        s.push(x);
        // Push to minStack if it's the smallest
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    // Remove the top element from the stack
    void pop() {
        if (!s.empty()) {
            // If the top of both stacks is the same, pop from minStack
            if (s.top() == minStack.top()) {
                minStack.pop();
            }
            s.pop();
        }
    }

    // Returns the top element of the stack
    int peek() {
        if (s.empty()) return -1;
        return s.top();
    }

    // Finds the minimum element in the stack
    int getMin() {
        if (minStack.empty()) return -1;
        return minStack.top();
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends