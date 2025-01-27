//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

#include <iostream>
#include <unordered_map>

using namespace std;

// Doubly Linked List Node
class Node {
public:
    int key, value;
    Node* prev;
    Node* next;
    Node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
};

// LRUCache class
class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;  // Maps key to node
    Node* head;  // Head of the doubly linked list (most recently used)
    Node* tail;  // Tail of the doubly linked list (least recently used)

    // Remove a node from the doubly linked list
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Add a node right after the head (most recently used)
    void add(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    // Constructor for initializing the cache with the given capacity
    LRUCache(int cap) : capacity(cap) {
        head = new Node(0, 0);  // Dummy node for head
        tail = new Node(0, 0);  // Dummy node for tail
        head->next = tail;
        tail->prev = head;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;  // If the key is not found, return -1
        }
        Node* node = cache[key];
        remove(node);  // Remove the node from its current position
        add(node);     // Add it to the head (most recently used)
        return node->value;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // If the key already exists, update the value and move the node to the head
            Node* node = cache[key];
            node->value = value;
            remove(node);
            add(node);
        } else {
            // If the key does not exist, create a new node and add it to the cache
            if (cache.size() >= capacity) {
                // If the cache is full, remove the least recently used (tail node)
                Node* node = tail->prev;
                remove(node);
                cache.erase(node->key);
                delete node;
            }
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            add(newNode);
        }
    }
};

// Driver code to test the implementatioN

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends