#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val): data(val), next(NULL) {};
};


//! tc is O(n) and sc is O(n). we can optimize the below  solution more with O(1) space complexity.
class Solution2 {
    public:
      // Function to find the length of a loop in the linked list.
      int countNodesinLoop(Node *head) {
          unordered_map<Node*, int> mp;
          Node* ptr = head;
          while(ptr){
              if(mp[ptr]) break;
              mp[ptr] = ptr->data;
              ptr = ptr -> next;
          }
          int len = 0;
          if(ptr){
              Node* ptr2 = ptr;
              while(ptr2){
                  ptr2 = ptr2 -> next;
                  len++;
                  if(ptr2 == ptr) break;
              }
          }
          return len;
      }
  };


  class Solution {
    public:
      // Function to find the length of a loop in the linked list.
      int countNodesinLoop(Node *head) {
         int count=0;
         Node *slow = head;
         Node *fast = head;
         while(fast && fast->next){
             slow = slow->next;
             fast = fast->next->next;
             if(slow == fast){
                 Node *temp = slow;
                 do{
                     count++;
                     temp = temp->next;
                 }while(temp != slow);
                 return count;
             }
         }
         return 0; // No loop found
      }
  };

  int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; // Creating a loop

    Solution2 sol2;
    cout << "Length of loop: " << sol2.countNodesinLoop(head) << endl; // Output: 3
    Solution sol;
    cout << "Length of loop: " << sol.countNodesinLoop(head) << endl; // Output: 3

    return 0;
  }