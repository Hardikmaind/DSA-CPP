#include <bits\stdc++.h>
using namespace std;
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, cur, next;
        for (int num : arr) {
            next.clear();
            next.insert(num);
            for (int x : cur) {
                next.insert(x | num);
            }
            cur = next;
            res.insert(cur.begin(), cur.end());
        }
        return res.size();
    }
};

int main(){
    Solution s1;
    vector<int>arr={1,2,4};
    auto res=s1.subarrayBitwiseORs(arr);
    cout<<res<<endl;
    return 0;
}