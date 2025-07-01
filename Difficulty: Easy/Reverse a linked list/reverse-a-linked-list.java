// function Template for Java

/* linked list node class:

class Node {
    int data;
    Node next;
    Node(int value) {
        this.value = value;
    }
}

*/

class Solution {
    Node reverseList(Node head) {
        Node prev = null;
        Node current = head;
        Node next = null;

        while (current != null) {
            next = current.next;   // store next node
            current.next = prev;   // reverse the link
            prev = current;        // move prev to current
            current = next;        // move to next node
        }

        return prev; // new head of reversed list
    }
}
