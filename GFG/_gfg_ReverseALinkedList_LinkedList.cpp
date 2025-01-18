#include <bits/stdc++.h>
using namespace std;


 struct Node
{
    int data;
    struct Node *next;
    
    Node(int val) : data(val), next(nullptr) {}
};


class Solution {
  public:
     Node* reverse(Node* head)
   {
       if(head==nullptr || head->next==nullptr)
       return head;
       
       Node* node=reverse(head->next);
       head->next->next=head;
       head->next=nullptr;
       return node;
   }
    Node* reverseList(struct Node* head) {
        // code here
        
        if(head==nullptr)
        return head;
        
       return reverse(head);
        // return head;
    }
};

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    Solution ob;
    Node *newhead = ob.reverseList(head);
    while(newhead){
        cout<<newhead->data<<" ";
        newhead = newhead->next;
    }
    cout<<endl;
    return 0;


}