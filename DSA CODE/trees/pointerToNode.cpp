#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* ptrToNode;  // Declaration of a pointer to Node
    Node node1;       // Declaration of a Node variable

    ptrToNode = &node1;  // Assigning the address of node1 to the pointer

    // Accessing data members of the node using the pointer
    ptrToNode->data = 42;
    ptrToNode->next = nullptr;
    cout<<ptrToNode->data;

    return 0;
}
