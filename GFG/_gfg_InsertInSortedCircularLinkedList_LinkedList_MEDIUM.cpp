#include <bits/stdc++.h>
using namespace std;
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
};
class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* newNode = new Node(data);

        // Case 1: Empty list
        if (head == nullptr) {
            newNode->next = newNode;
            return newNode;
        }

        Node* curr = head;

        // Case 2: Insert in correct sorted position
        while (true) {
            // Normal case: insert between two nodes
            if (curr->data <= data && data <= curr->next->data) {
                break;
            }

            // Edge case: insert before the smallest or after the largest
            if (curr->data > curr->next->data) { // End of list
                if (data >= curr->data || data <= curr->next->data) {
                    break;
                }
            }

            curr = curr->next;

            // If we looped back to head, break
            if (curr == head) {
                break;
            }
        }

        // Insert newNode after curr
        newNode->next = curr->next;
        curr->next = newNode;

        // Return new head: smallest element stays head
        return head->data < data ? head : newNode;
    }
};


int main(){
    Solution sol;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = head; // Making it circular

    int data = 2;
    Node* newHead = sol.sortedInsert(head, data);

    // Print the circular linked list
    Node* curr = newHead;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != newHead);
    
    return 0;
}