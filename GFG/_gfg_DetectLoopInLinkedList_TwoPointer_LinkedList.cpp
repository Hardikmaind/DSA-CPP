#include <bits/stdc++.h>
using namespace std;

// https://cp-algorithms.com/others/tortoise_and_hare.html


struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

};
class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        Node* slow=head;
        Node* fast=head;
        while(fast != nullptr && fast->next != nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if (slow == fast) {
                return true;
            }
            
        }
        return false;
        
    }
};

int main(){
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = head->next;

    Solution obj;
    cout<<boolalpha<<obj.detectLoop(head)<<endl;
    return 0;
}