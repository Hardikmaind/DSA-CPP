
#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    // Custom struct
    struct Ele {
        int a; // Value from nums
        int i; // Index in nums
        int l; // Left index
        int r; // Right index

        // Constructor for convenience
        Ele(int a, int i, int l, int r) : a(a), i(i), l(l), r(r) {}
    };
    // Custom comparator for priority queue (min-heap based on value `a`)
    struct CompareEle {
        bool operator()(const Ele& t1, const Ele& t2) {
            if (t1.a == t2.a) {
                return t1.i > t2.i; // If values are equal, prioritize smaller index
            }
            return t1.a > t2.a; // Smaller value has higher priority
        }
    };
    long long findScore(vector<int>& nums) {
        priority_queue<Ele, vector<Ele>, CompareEle> pq;

        unordered_set<int> visited;

        for (int i = 0; i < nums.size(); i++) {
            pq.push(Ele(nums[i], i, i == 0 ? -1 : i - 1, i == nums.size() - 1 ? -1 : i + 1));
        }
        long long sum = 0;
        while (!pq.empty()) {
            Ele obj = pq.top();
            pq.pop();
            if (visited.count(obj.i) == 0) {
                sum += obj.a;
                visited.insert(obj.i);
                if (obj.l != -1) visited.insert(obj.l);
                if (obj.r != -1) visited.insert(obj.r);
                }
        }
        return sum;
    }
};
int main(){
    Solution s;
    vector<int> nums = {2,1,3,4,5,2};
    cout << s.findScore(nums) << endl;
    return 0;

}