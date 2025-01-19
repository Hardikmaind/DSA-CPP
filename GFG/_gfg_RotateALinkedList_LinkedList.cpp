#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // Your code here
        if(k==0)return head;
        int len=1;
        Node* temp=head;
        while(temp->next){
            temp=temp->next;
            len++;
        }
        k=k%len;
        if(k==0)
        {
            return head;
        }
            temp->next=head;
            Node* nwt=head;
            for(int i=1;i<k;i++)
            nwt=nwt->next;
            head=nwt->next;
            nwt->next=NULL;
            return head;
    }
};

int main(){
    Node* head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    head->next->next->next->next=new Node(50);
    int k=4;
    Solution ob;
    Node* newHead=ob.rotate(head,k);
    while(newHead){
        cout<<newHead->data<<" ";
        newHead=newHead->next;
    }
    return 0;

}