#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
        int data;
        Node *next;
        Node(int val,Node* nextptr ):data(val),next(nextptr){}
        Node(int val): data(val), next(nullptr) {} // Initialize next to nullptr
    };


class Solution {
    public:
      Node* segregate(Node* head) {
          if (head == nullptr || head->next == nullptr) return head;
  
          // Dummy nodes for 0s, 1s, and 2s
          Node *zeroDummy = new Node(0), *oneDummy = new Node(0), *twoDummy = new Node(0);
          Node *zero = zeroDummy, *one = oneDummy, *two = twoDummy;
            //! above i have created 3 dummy nodes for 0,1,2 and allocated the memory for them dynamically. and then i have created 3 pointers zero,one,two which will point to the dummy nodes.

            //? in the end i am returning the next of the zeroDummy node which will be the head of the new linked list. since i am not moving the zeroDummy pointer and i am moving the zero pointer to the next node in the linked list. so the next of the zeroDummy will be the head of the new linked list.
          Node* curr = head;
          while (curr) {
              if (curr->data == 0) {
                  zero->next = curr;
                  zero = zero->next;
              } else if (curr->data == 1) {
                  one->next = curr;
                  one = one->next;
              } else {
                  two->next = curr;
                  two = two->next;
              }
              curr = curr->next;
          }
  
          //! Connect three sublists together
          zero->next = (oneDummy->next) ? oneDummy->next : twoDummy->next;
          one->next = twoDummy->next;
          two->next = nullptr; // Important to terminate the list
  
          Node* newHead = zeroDummy->next;
  
          // Free dummy nodes
          delete zeroDummy;
          delete oneDummy;
          delete twoDummy;
  
          return newHead;
      }
  };

class Solution2 {
    public:
      Node* segregate(Node* head) {
          Node* temp=head;
          int count[]={0,0,0};
            while(temp!=NULL){
                count[temp->data]++;
                temp=temp->next;
            }

            //! here i am reasigning/overwriting all the nodes of the linked list with 0,1,2. and i am using the count[] array to keep track of the number of 0s,1s,2s in the linked list. and then i am overwriting the nodes with 0,1,2 according to the count[] array.
            temp=head;
            int i=0;
            while(temp!=nullptr){
                if(count[i]==0){
                    i++;                // if the count[i]==0 then we increament the index. here i is the index of the array count[] which is used to store the count of 0,1,2 in the linked list.
                }
                else{
                    temp->data=i;
                    count[i]--;
                    temp=temp->next;
                }
            }
            return head; // return the head of the linked list.
      }
  };

  int main(){
    Solution obj;
    Solution2 obj2;
    Node*head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(2);
    head->next->next->next=new Node(1);
    head->next->next->next->next=new Node(2);
    head->next->next->next->next->next=new Node(0);
    head->next->next->next->next->next->next=new Node(2);
    head->next->next->next->next->next->next->next=new Node(2);


    
    auto res=obj.segregate(head);
    cout<<"The linked list after sorting is: "<<endl;
    while(res!=nullptr){
        cout<<res->data<<" ";
        res=res->next;
    }
    cout<<endl;


    Node*head2=new Node(1);
    head2->next=new Node(2);
    head2->next->next=new Node(2);
    head2->next->next->next=new Node(1);
    head2->next->next->next->next=new Node(2);
    head2->next->next->next->next->next=new Node(0);
    head2->next->next->next->next->next->next=new Node(2);
    head2->next->next->next->next->next->next->next=new Node(2);
    auto res2=obj2.segregate(head2);
    cout<<"The linked list after sorting is: "<<endl;
    while(res2!=nullptr){
        cout<<res2->data<<" ";
        res2=res2->next;
    }
    return 0;
  }