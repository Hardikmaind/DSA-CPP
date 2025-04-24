#include <bits/stdc++.h>
using namespace std;

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
	        this->data = data;
	        this->next = NULL;
        }
    };

Node* reverse(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* node=reverse(head->next);
    head->next->next=head;
    head->next=nullptr;
    return node;
}
Node* modifyLL(Node* head) 
{
	// Write your code here.
    if(head==nullptr ||head->next==nullptr){
        return head;
    }
    Node* fast=head;
    Node* slow=head;
    Node* prev=nullptr;
    while(fast && fast->next){
         fast=fast->next->next;
         prev=slow;
         slow=slow->next;

    }
    prev->next=nullptr;
    /*Yes, prev is just a pointer.
    But it’s a pointer to a real node in the same list that head traverses.
    So when you set prev->next = nullptr, you are modifying the real list, effectively breaking the list into two parts.


*/
    
    Node *secondHalf=reverse(slow);

    Node* first=head;
    Node* dummy=new Node(-1);
    Node*curr=dummy;
    while(first || secondHalf){
       if(first){
           curr->next=first;
           curr=curr->next;
           first=first->next;
       }
       if(secondHalf){
           curr->next=secondHalf;
           curr=curr->next;
           secondHalf=secondHalf->next;
       }
    }
    return dummy->next;

}

int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    head->next->next->next->next->next->next=new Node(7);
    head->next->next->next->next->next->next->next=new Node(8);
    head->next->next->next->next->next->next->next->next=new Node(9);
    Node* newHead=modifyLL(head);
    while(newHead){
        cout<<newHead->data<<" ";
        newHead=newHead->next;
    }
    cout<<endl;
    return 0;

}
