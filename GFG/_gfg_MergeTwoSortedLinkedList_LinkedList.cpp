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
    Node* sortedMerge(Node* head1, Node* head2) {
        Node dummy(0), *tail = &dummy;
        while (head1 && head2) {
            tail->next = (head1->data <= head2->data) ? head1 : head2;
            tail = tail->next;
            if (head1->data <= head2->data) head1 = head1->next;
            else head2 = head2->next;
        }
        tail->next = head1 ? head1 : head2;
        return dummy.next;
    }
};



int main(){
    Node *head1 = new Node(5);
    head1->next = new Node(10);
    head1->next->next = new Node(15);
    head1->next->next->next = new Node(40);

    Node *head2= new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(20);

    Solution ob;
    Node *head = ob.sortedMerge(head1, head2);
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
    


}