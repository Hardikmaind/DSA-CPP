#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
  Node*reverse(Node*root){
      Node*ptr=NULL;
        while(root)
        {
            Node*nxt=root->next;
            root->next=ptr;
            ptr=root;
            root=nxt;
        }
        return ptr;
  }
    Node* addTwoLists(Node*num1, Node*num2)
    {
        Node* rev1=reverse(num1);
        Node* rev2=reverse(num2);
        Node*res=new Node(-1);
        int carry=0;
        Node*ptr=res;
        while(rev1&&rev2)
        {
            int ele=rev1->data+rev2->data+carry;
            ptr->next=new Node(ele%10);
            carry=ele/10;
            rev1=rev1->next;
            rev2=rev2->next;
            ptr=ptr->next;
            
        }
        while(rev1)
        {
            int ele=rev1->data+carry;
            ptr->next=new Node(ele%10);
            carry=ele/10;
            rev1=rev1->next;
            ptr=ptr->next;
        }
        while(rev2)
        {
            int ele=rev2->data+carry;
            ptr->next=new Node(ele%10);
            carry=ele/10;
            rev2=rev2->next;
            ptr=ptr->next;
        }
        while(carry)
        {
            ptr->next=new Node(carry%10);
            carry/=10;
        }
        Node*ans=reverse(res->next);
        while(ans->data==0)
        ans=ans->next;
        return ans;
    }
};

int main(){
    Solution s;
    Node* head1 = new Node(1);
    head1->next = new Node(2);

    Node* head2 = new Node(1);
    head2->next = new Node(2);

    Node* res = s.addTwoLists(head1, head2);
    while(res){
        cout<<res->data<<" ";
        res = res->next;
    }
    return 0;
}