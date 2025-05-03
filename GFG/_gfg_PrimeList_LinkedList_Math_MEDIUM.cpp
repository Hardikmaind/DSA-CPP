#include <bits/stdc++.h>
using namespace std;




class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


class Solution {
    public:
    bool checkprime(int num) {
      if (num <= 1) return false;
      if (num <= 3) return true;
  
      if (num % 2 == 0 || num % 3 == 0) return false;
  
      for (int i = 5; i * i <= num; i += 6)
          if (num % i == 0 || num % (i + 2) == 0)
              return false;
  
      return true;
  }
    int nearestPrime(int n) {
          if (n <= 2) return 2;
      
          int lower = n, upper = n;
          
          while (!checkprime(lower)) lower--;
          while (!checkprime(upper)) upper++;
      
          if ((n - lower) <= (upper - n))
              return lower;
          else
              return upper;
  }
      Node *primeList(Node *head) {
          // code here
          Node* dummy=new Node(0);
          Node* ptr=dummy;
          ptr->next=head;
          while(ptr){
              if(!checkprime(ptr->val)){
                  ptr->val=nearestPrime(ptr->val);
              }
                  ptr=ptr->next;
          }
          return dummy->next;
          
      }
  };


  int main(){
    Node *head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(8);


    Solution sol;
    Node *result = sol.primeList(head);
    Node *current = result;
    while (current ) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
    return 0;
  }