#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;  // this is a pointer to the left child
    Node *right; // this is a pointer to the right child
    // Constructor
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Student
{
public:
    std::string name;
    int rollNumber;

    // Constructor initializing name and rollNumber
    Student(std::string studentName, int studentRollNumber) : name(studentName), rollNumber(studentRollNumber) {}
};

// You would call this function with the root of the tree to traverse all nodes in ascending order.
// Pointers are essential in tree data structures as they allow nodes to reference other nodes, enabling the creation of complex hierarchical structures. Understanding pointers is crucial for working with trees and other data structures in C++.
void inorder(Node *node)
{
    if (node == nullptr)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main()
{
    // s: Pointers are used to create and traverse trees. For example, to create a tree with three nodes, you might do the following:
    Node *root = new Node(1);  // Create root node with value 1
    root->left = new Node(2);  // Attach left child with value 2
    root->right = new Node(3); // Attach right child with value 3

    // To create a new node and assign its address to a pointer, you should use the new keyword to allocate memory for the node dynamically. Here's the correct way to do it:
    Node *newnode = new Node(4);
    // This line of code dynamically allocates memory for a new Node object with a data value of 4 and assigns the address of this new node to the root pointer. This is the standard way to create new nodes in a tree data structure when using pointers in C++.

    // Now here new Node(4); is an anonymous object right?

    // Yes, in the context of the statement Node* newnode = new Node(4);, new Node(4); creates a new Node object with a data value of 4 and returns a pointer to this newly created object. This object is indeed anonymous because it doesn't have a name (i.e., there's no variable name associated with it). The pointer newnode then holds the address of this anonymous object.

    // Now create a object which has name
    Node rootNode(10); // Creates a Node object named rootNode with data value 10
    // In this example, rootNode is the name of the object, and it is created on the stack. The Node constructor is called with the argument 10 to initialize the data member of the Node object.

    // Node rt= new Node(4);   is this correct

    // The statement Node rt = new Node(4); is almost correct, but there's a small error in syntax. In C++, when you use the new keyword to create an object, it returns a pointer to the newly allocated object. However, you are trying to assign this pointer to a non-pointer variable rt, which will cause a compilation error.

    // To correct this, you can either declare rt as a pointer:
    Node *rt = new Node(4);
    // Or, if you want rt to be a regular (non-pointer) object, you should create it without using new:
    Node rt2(4);    // Creates a Node object named rt2 with data value 4. it is a regular object on stack.










    // Creating object using constructor
    Student student1("Alice", 1); // Creates a Student object with name "Alice" and rollNumber 1

    // Accessing the data members of the object
    std::cout << "Student Name: " << student1.name << std::endl;
    std::cout << "Roll Number: " << student1.rollNumber << std::endl;

    return 0;

    return 0;
}
