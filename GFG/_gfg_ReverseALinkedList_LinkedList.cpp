#include <bits/stdc++.h>
using namespace std;


 struct Node
{
    int data;
    struct Node *next;
    
    Node(int val) : data(val), next(nullptr) {}
};

//! THIS IS A RECURSIVE SOLUTION TO REVERSE A LINKED LIST
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

//! THIS IS A ITERATIVE SOLTION TO REVERSE A LINKED LIST

class Solution2 {
    public:
    Node *reverseList(Node* head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        Node* prev=nullptr;
        Node* forward=nullptr;
        Node*curr=head;
        while(curr!=nullptr){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
};

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    Solution ob;
    Node *newhead = ob.reverseList(head);
    Node *temp=newhead;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;


    //! here i am reversing a reverse linkedlist
    Solution2 ob2;
    Node *newhead2 = ob2.reverseList(newhead);
    temp=newhead2;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return 0;


}