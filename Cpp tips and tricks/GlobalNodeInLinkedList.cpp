#include <bits/stdc++.h>
using namespace std;


    struct Node
    {
        int data;
        struct Node* next;          //! this is also ok and works fine. And just Node* next; is also fine.

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;                 //! here we have declared head globally so that we can access it in main function also.

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
          if(!head || !head->next) return head;

        Node *prev = NULL;
        Node *curr = head;
        
        int it = 0;
        while(curr && it < k){
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            it++;
        }
        
        
        head->next = reverseKGroup(curr,k);
        return prev;
    }
};

int main(){
    // ! since head is declared globally, so no need to create a new head here with the syntax Node *head = new Node(1);
        head= new Node(1);
        head->next= new Node(2);
        head->next->next= new Node(2);
        head->next->next->next= new Node(4);
        head->next->next->next->next= new Node(5);
        head->next->next->next->next->next= new Node(6);
        head->next->next->next->next->next->next= new Node(7);
        head->next->next->next->next->next->next->next= new Node(8);
        int k=4;
        Solution ob;
        Node *new_head = ob.reverseKGroup(head, k);
        while(new_head){
            cout<<new_head->data<<" ";
            new_head = new_head->next;
        }
    return 0;
}