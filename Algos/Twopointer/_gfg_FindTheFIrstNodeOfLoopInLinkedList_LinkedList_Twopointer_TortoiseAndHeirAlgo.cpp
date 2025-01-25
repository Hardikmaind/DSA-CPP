#include <bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

};
class Solution {
  public:
    Node* findFirstNode(Node* head) {
        // your code here
        Node* slow=head;
        Node* fast=head;
        bool flag=0;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                flag=1;
                break;
            }
        }
        if(flag==0){
            return nullptr;
        }else{
            
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }

            return slow; // the starting point of the cycle.
        }
    }
};

int main(){
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next;

    Solution ob;
    Node* res = ob.findFirstNode(head);
    cout<<res->data<<endl;



    Node *head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(2);
    head1->next->next->next = new Node(4);

    Node *res2=ob.findFirstNode(head1);
    cout <<(res2 != nullptr ? res2->data : -1) << endl;

    return 0;
}