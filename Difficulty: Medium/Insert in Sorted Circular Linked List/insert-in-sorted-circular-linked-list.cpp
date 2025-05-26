/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // Create the new node to be inserted.
        Node* newNode = new Node(data);
        
        // If the list is empty, create a self-pointing node.
        if(head == NULL){
            newNode->next = newNode;
            return newNode;
        }
        
        Node* curr = head;
        
        // Traverse the list until the correct position is found.
        while(true) {
            // Case 1: Normal insertion between two nodes.
            if(curr->data <= data && data <= curr->next->data) {
                break;
            }
            
            // Case 2: At the pivot where the list transitions from maximum to minimum.
            if(curr->data > curr->next->data) {
                // Insertion comes either after the maximum or before the minimum.
                if(data >= curr->data || data <= curr->next->data)
                    break;
            }
            
            curr = curr->next;
            
            // If we have looped the entire list, break.
            if(curr == head)
                break;
        }
        
        // Insert the new node after curr.
        newNode->next = curr->next;
        curr->next = newNode;
        
        // Update head if the new node is the new smallest element.
        if(data < head->data)
            head = newNode;
        
        return head;
    }
};
