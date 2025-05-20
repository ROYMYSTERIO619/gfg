/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to create a map of each node to its parent and find the target node
    void mapParents(Node* root, unordered_map<Node*, Node*>& parent, Node*& targetNode, int target) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front(); q.pop();
            if (curr->data == target) targetNode = curr;
            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent;
        Node* targetNode = nullptr;
        
        // Map all nodes to their parents
        mapParents(root, parent, targetNode, target);

        // BFS from the target node
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool burned = false;

            for (int i = 0; i < size; ++i) {
                Node* curr = q.front(); q.pop();

                // Left child
                if (curr->left && !visited[curr->left]) {
                    burned = true;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                // Right child
                if (curr->right && !visited[curr->right]) {
                    burned = true;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                // Parent
                if (parent[curr] && !visited[parent[curr]]) {
                    burned = true;
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }

            if (burned) time++;
        }

        return time;
    }
};
