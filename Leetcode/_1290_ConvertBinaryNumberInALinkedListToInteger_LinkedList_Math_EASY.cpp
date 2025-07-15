#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
  class ListNode {
    public:
      int val;
      ListNode* next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode* next) : val(x), next(next) {}
  };
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        while (head != nullptr) {
            result = (result << 1) | head->val;
            head = head->next;
        }
        return result;
    }
};

int main(){
    // create a linked list and test the function here if needed

    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);
    Solution solution;
    int decimalValue = solution.getDecimalValue(head);
    cout << "Decimal Value: " << decimalValue << endl; // Output should be 5 for 101 in binary
    // Clean up the linked list
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;


}