#include <bits/stdc++.h>
using namespace std;

class Solution {
    public :    
        int findUnique(vector<int>& nums) {         //! tc is O(n) and sc is O(1).
            int res=0;
            for(auto &x:nums){
                res^=x;
            }
            return res;
        }
};

int main() {
    Solution obj;
    vector<int> nums = {2, 30, 2, 15, 20, 30, 15};
    cout << obj.findUnique(nums) << endl;
    return 0;
}

/*Great question!

To solve this problem in O(n) time and O(1) auxiliary space, here's your hint:

Think about bitwise XOR ( ^ ).

Why XOR?
a ^ a = 0 for any number a

a ^ 0 = a

XOR is commutative and associative, meaning the order of operations doesn’t matter.

So if you XOR all elements of the array, the duplicate elements will cancel out (because x ^ x = 0), and only the unique element will remain. */