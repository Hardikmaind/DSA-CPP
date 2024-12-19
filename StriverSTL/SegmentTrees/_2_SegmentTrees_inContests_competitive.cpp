#include <bits/stdc++.h>
using namespace std;

void buildTree(vector<int>& arr, vector<int>& segTree, int start, int end, int node) {
    if (start == end) {                         //* Leaf node
        segTree[node] = arr[start];             //* Store the value in the node
        return;                                 //* Return
    }
    //! HERE DIVIDE AND CONQUER STRATEGY IS USED 
    int mid = (start + end) / 2;                //* Calculate the mid
    buildTree(arr, segTree, start, mid, 2 * node + 1);                      //! Build left subtree
    buildTree(arr, segTree, mid + 1, end, 2 * node + 2);                    //! Build right subtree
    segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];          //! Store the result
}

int query(vector<int>& segTree, int start, int end, int l, int r, int node) {
    if (r < start || l > end) return 0;                             //! Out of range (No overlap)
    if (l <= start && end <= r) return segTree[node];               //! Completely inside the range (Total Overlap)             
    int mid = (start + end) / 2;                                     //! Calculate the mid   (Partial Overlap)
    int left = query(segTree, start, mid, l, r, 2 * node + 1);       //! Query left subtree
    int right = query(segTree, mid + 1, end, l, r, 2 * node + 2);   //! Query right subtree
    return left + right;                                    //! Return the result  ( Modify this line for other operations. for other coding problems  
}

void update(vector<int>& segTree, int start, int end, int idx, int value, int node) {
    if (start == end) {
        segTree[node] = value;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) {
        update(segTree, start, mid, idx, value, 2 * node + 1);
    } else {
        update(segTree, mid + 1, end, idx, value, 2 * node + 2);
    }
    segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];          //! Modify this line for other operations. for other coding problems
}   

int main() {
    int n = 6; // Size of the array
    vector<int> arr = {1, 3, 5, 7, 9, 11}; // Input array
    vector<int> segTree(4 * n, 0); // Segment tree array

    buildTree(arr, segTree, 0, n - 1, 0);

    cout << "Sum of range (1, 3): " << query(segTree, 0, n - 1, 1, 3, 0) << endl;

    update(segTree, 0, n - 1, 1, 10, 0);

    cout << "Sum of range (1, 3) after update: " << query(segTree, 0, n - 1, 1, 3, 0) << endl;

    return 0;
}
