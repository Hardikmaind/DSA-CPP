#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        if (!head) return nullptr;

        // Step 1: Clone nodes and insert them after original nodes
        Node* current = head;
        while (current) {
            Node* clone = new Node(current->data);
            clone->next = current->next;
            current->next = clone;
            current = clone->next;
        }

        // Step 2: Set random pointers for the cloned nodes
        current = head;
        while (current) {
            if (current->random) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        // Step 3: Separate the cloned list from the original list
        Node* original = head;
        Node* cloneHead = head->next;
        Node* clone = cloneHead;

        while (original) {
            original->next = original->next->next;
            if (clone->next) {
                clone->next = clone->next->next;
            }
            original = original->next;
            clone = clone->next;
        }

        return cloneHead;
    }   
};
int main() {
    Solution obj;

    // Create the original linked list
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(9);

    // Set up random pointers
    head->random = head->next->next;                    // 1 -> 5
    head->next->random = head->next->next;               // 3 -> 5
    head->next->next->random = nullptr;           // 5 -> NULL
    head->next->next->next->random = head->next->next; // 9 -> 5

    // Clone the linked list
    Node* clonedList = obj.cloneLinkedList(head);

    // Function to print a linked list with random pointers
    auto printList = [](Node* node) {
        while (node) {
            cout << "Node: " << node->data;
            if (node->random) {
                cout << ", Random: " << node->random->data;
            } else {
                cout << ", Random: NULL";
            }
            cout << endl;
            node = node->next;
        }
    };

    // Print the original linked list
    cout << "Original List:" << endl;
    printList(head);

    // Print the cloned linked list
    cout << "Cloned List:" << endl;
    printList(clonedList);

    return 0;
}
