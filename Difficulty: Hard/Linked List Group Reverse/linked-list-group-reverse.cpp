//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node* reverseKGroup(Node* head, int k) {
        if (!head || k == 1) return head; // If the list is empty or k = 1, no reversal needed

        Node* dummy = new Node(0); // Dummy node to handle the head easily
        dummy->next = head;

        Node *prevGroupEnd = dummy, *current = head;

        while (current) {
            Node* groupStart = current;
            Node* groupEnd = current;

            // Check if there are k nodes in the current group
            for (int i = 1; i < k && groupEnd->next; i++) {
                groupEnd = groupEnd->next;
            }

            // If the group has fewer than k nodes, no more reversal
            if (!groupEnd || (groupEnd->next == nullptr && k > 1 && groupStart->next == nullptr)) {
                break;
            }

            // Save the next group's starting node
            Node* nextGroupStart = groupEnd->next;

            // Reverse the current group
            groupEnd->next = nullptr; // Temporarily break the link
            prevGroupEnd->next = reverse(groupStart);

            // Connect the reversed group to the rest of the list
            groupStart->next = nextGroupStart;

            // Move the pointers for the next group
            prevGroupEnd = groupStart;
            current = nextGroupStart;
        }

        return dummy->next;
    }

  private:
    // Helper function to reverse a linked list
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* current = head;
        while (current) {
            Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

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
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends