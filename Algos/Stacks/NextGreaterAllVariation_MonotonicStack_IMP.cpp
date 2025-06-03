#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterLeft(const vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] <= nums[i]) {
            st.pop();
        }
        if (!st.empty()) res[i] = nums[st.top()];
        st.push(i);
    }
    return res;
}
vector<int> nextGreaterRight(const vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && nums[st.top()] <= nums[i]) {
            st.pop();
        }
        if (!st.empty()) res[i] = nums[st.top()];
        st.push(i);
    }
    return res;
}
vector<int> nextSmallerLeft(const vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }
        if (!st.empty()) res[i] = nums[st.top()];
        st.push(i);
    }
    return res;
}
vector<int> nextSmallerRight(const vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }
        if (!st.empty()) res[i] = nums[st.top()];           
        st.push(i);
    }
    return res;
}
int main() {
    vector<int> arr = {2, 1, 5, 6, 2, 3};

    auto print = [](const vector<int>& v) {
        for (int x : v) cout << x << " ";
        cout << endl;
    };

    cout << "Next Greater Left: "; print(nextGreaterLeft(arr));
    cout << "Next Greater Right: "; print(nextGreaterRight(arr));
    cout << "Next Smaller Left: "; print(nextSmallerLeft(arr));
    cout << "Next Smaller Right: "; print(nextSmallerRight(arr));

    return 0;
}
