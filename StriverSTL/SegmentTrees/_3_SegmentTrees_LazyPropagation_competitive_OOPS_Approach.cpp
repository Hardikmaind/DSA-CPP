#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
public:
    vector<int> tree, lazy;
    int n;

    // Constructor
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);  // Segment Tree array
        lazy.resize(4 * n, 0);  // Lazy array
    }

    // Update the tree with a lazy propagation approach
    void update(int node, int start, int end, int l, int r, int val) {
        // If there is any pending update, apply it first
        if (lazy[node] != 0) {
            // Apply the lazy value to the node
            tree[node] += (end - start + 1) * lazy[node];

            // If not a leaf node, propagate the lazy value to the children
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }

            // Clear the lazy value
            lazy[node] = 0;
        }

        // No overlap
        if (start > end || start > r || end < l) return;

        // Total overlap
        if (start >= l && end <= r) {
            tree[node] += (end - start + 1) * val;
            if (start != end) {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }
            return;
        }

        // Partial overlap
        int mid = (start + end) / 2;
        update(2 * node + 1, start, mid, l, r, val);
        update(2 * node + 2, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    // Query the tree
    int query(int node, int start, int end, int l, int r) {
        // Apply any pending updates
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        // No overlap
        if (start > end || start > r || end < l) return 0;

        // Total overlap
        if (start >= l && end <= r) return tree[node];

        // Partial overlap
        int mid = (start + end) / 2;
        int left = query(2 * node + 1, start, mid, l, r);
        int right = query(2 * node + 2, mid + 1, end, l, r);
        return left + right;
    }
};

int main() {
    int n = 10;  // Size of the array
    SegmentTree segTree(n);

    // Update values in range [2, 5] by adding 3
    segTree.update(0, 0, n - 1, 2, 5, 3);

    // Query the sum in the range [1, 4]
    cout << "Sum in range [1, 4]: " << segTree.query(0, 0, n - 1, 1, 4) << endl;

    // Update values in range [4, 6] by adding 2
    segTree.update(0, 0, n - 1, 4, 6, 2);

    // Query the sum in the range [1, 6]
    cout << "Sum in range [1, 6]: " << segTree.query(0, 0, n - 1, 1, 6) << endl;

    return 0;
}
