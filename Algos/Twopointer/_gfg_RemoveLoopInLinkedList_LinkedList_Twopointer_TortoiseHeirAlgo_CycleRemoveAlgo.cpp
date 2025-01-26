#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
  public:
    // Function to remove a loop in the linked list
    void removeLoop(Node* head) {
        if (!head || !head->next) return; // No loop if list is empty or has one node.

        Node* slow = head;
        Node* fast = head;
        bool loopExists = false;

        // Detect loop using Floyd’s cycle-finding algorithm
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                loopExists = true;
                break;
            }
        }

        // If no loop exists, return
        if (!loopExists) return;

        // Reset slow to head to find the start of the loop
        slow = head;

        // If the loop starts at the head itself
        if (slow == fast) {
            // Move fast to the last node in the loop
            while (fast->next != slow) {
                fast = fast->next;
            }
            fast->next = nullptr; // Break the loop
            return;
        }

        // Move both pointers to find the start of the loop
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // Break the loop
        fast->next = nullptr;
    }
};

// Utility function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to create a loop in the linked list
void createLoop(Node* head, int pos) {
    if (pos == 0) return;

    Node* temp = head;
    Node* loopNode = NULL;
    int count = 1;

    // Traverse to the position where the loop should be created
    while (temp->next) {
        if (count == pos) {
            loopNode = temp;
        }
        temp = temp->next;
        count++;
    }

    // Create the loop
    temp->next = loopNode;
}

// Main function
int main() {
    // Creating a linked list
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);

    // Position to create a loop (1-based index, 2 means node with value 3)
    int pos = 2;
    createLoop(head, pos);

    Solution ob;

    // Remove the loop
    ob.removeLoop(head);

    // Print the linked list after removing the loop
    printList(head);

    return 0;
}
