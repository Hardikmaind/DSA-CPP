#include <iostream>
#include <stack>
#include <vector>

struct Node {
    int data;
    int leftIndex;
    int rightIndex;
    Node(int val, int left = -1, int right = -1) : data(val), leftIndex(left), rightIndex(right) {}
};

void inorderTraversal(const std::vector<Node>& tree, int rootIndex) {
    if (rootIndex == -1) return;

    std::stack<int> stack;
    int current = rootIndex;

    while (current != -1 || !stack.empty()) {
        while (current != -1) {
            stack.push(current);
            current = tree[current].leftIndex;
        }

        current = stack.top();
        stack.pop();

        std::cout << tree[current].data << " ";

        current = tree[current].rightIndex;
    }
}

int main() {
    std::vector<Node> tree = {
        Node(1, 1, 2),   // Root
        Node(2, 3, 4),   // Left child of 1
        Node(3, -1, -1), // Right child of 1
        Node(4, -1, -1), // Left child of 2
    };

    inorderTraversal(tree, 0); // Start traversal from the root
    return 0;
}
