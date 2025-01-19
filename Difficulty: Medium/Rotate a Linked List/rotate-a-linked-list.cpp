//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if (!head || k == 0) return head; // Edge cases: empty list or no rotation

        // Step 1: Count the number of nodes in the list
        Node* temp = head;
        int length = 1; // Count the head node
        while (temp->next) {
            temp = temp->next;
            length++;
        }

        // Step 2: Handle cases where k >= length
        k = k % length;
        if (k == 0) return head; // No rotation needed

        // Step 3: Traverse to the (k-th) node
        Node* newTail = head;
        for (int i = 1; i < k; i++) {
            newTail = newTail->next;
        }

        // Step 4: Adjust the links
        Node* newHead = newTail->next; // The (k+1)-th node becomes the new head
        newTail->next = nullptr;       // Break the list at the k-th node
        temp->next = head;             // Connect the old tail to the old head

        return newHead;
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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
        cout << "~\n";
    }
    return 1;
}

// } Driver Code Ends