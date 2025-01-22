//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
public:
    // Helper function to pad the shorter list with leading zeros
    Node* padList(Node* head, int padLength) {
        for (int i = 0; i < padLength; ++i) {
            Node* newNode = new Node(0);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }

    // Helper function to recursively add two lists
    Node* addListsHelper(Node* num1, Node* num2, int& carry) {
        // Base case: if both nodes are null, return null
        if (!num1 && !num2) return nullptr;

        // Recursively add the next digits
        Node* nextResult = addListsHelper(num1->next, num2->next, carry);

        // Add current digits and carry
        int sum = num1->data + num2->data + carry;
        carry = sum / 10;
        int digit = sum % 10;

        // Create a new node for the current digit
        Node* newNode = new Node(digit);
        newNode->next = nextResult;

        return newNode;
    }

    // Main function to add two lists
    Node* addTwoLists(Node* num1, Node* num2) {
        // Calculate lengths of both lists
        int len1 = 0, len2 = 0;
        Node* temp1 = num1, *temp2 = num2;

        while (temp1) {
            ++len1;
            temp1 = temp1->next;
        }
        while (temp2) {
            ++len2;
            temp2 = temp2->next;
        }

        // Pad the shorter list with leading zeros
        if (len1 < len2) num1 = padList(num1, len2 - len1);
        else if (len2 < len1) num2 = padList(num2, len1 - len2);

        // Initialize carry and add the two lists
        int carry = 0;
        Node* result = addListsHelper(num1, num2, carry);

        // If there's a carry left, add it as a new node
        if (carry > 0) {
            Node* newNode = new Node(carry);
            newNode->next = result;
            result = newNode;
        }

        // Remove leading zeros from the result
        while (result && result->data == 0 && result->next) {
            Node* temp = result;
            result = result->next;
            delete temp;
        }

        return result;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends