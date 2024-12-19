#include <iostream>
using namespace std;

const int N = 1e5; // Maximum size
int arr[N], seg[4 * N];

void build(int idx, int low, int high) {
    if (low == high) {
        seg[idx] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * idx + 1, low, mid);
    build(2 * idx + 2, mid + 1, high);
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

int query(int idx, int low, int high, int l, int r) {
    if (r < low || l > high) return 0;
    if (l <= low && high <= r) return seg[idx];
    int mid = (low + high) / 2;
    int left = query(2 * idx + 1, low, mid, l, r);
    int right = query(2 * idx + 2, mid + 1, high, l, r);
    return left + right;
}

void update(int idx, int low, int high, int pos, int val) {
    if (low == high) {
        seg[idx] = val;
        return;
    }
    int mid = (low + high) / 2;
    if (pos <= mid) update(2 * idx + 1, low, mid, pos, val);
    else update(2 * idx + 2, mid + 1, high, pos, val);
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

int main() {
    int n, q; // Number of elements and queries
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> arr[i];
    build(0, 0, n - 1);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            // Query range [l, r]
            int l, r;
            cin >> l >> r;
            cout << query(0, 0, n - 1, l, r) << endl;
        } else if (type == 2) {
            // Update position pos with value val
            int pos, val;
            cin >> pos >> val;
            update(0, 0, n - 1, pos, val);
        }
    }
    return 0;
}

