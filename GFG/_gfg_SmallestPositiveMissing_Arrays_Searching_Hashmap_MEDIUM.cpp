#include <bits/stdc++.h>
using namespace std;


//! tc is O(n) and sc is O(1) for the first solution
class Solution{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        // Place each number nums[i] at the correct index nums[i] - 1
        for (int i = 0; i < n; i++)
        {
            while (
                nums[i] > 0 &&
                nums[i] <= n &&
                nums[nums[i] - 1] != nums[i])
            {
                int correctIdx = nums[i] - 1;
                // swap nums[i] <-> nums[nums[i] - 1]
                int temp = nums[i];
                nums[i] = nums[correctIdx];
                nums[correctIdx] = temp;
            }
        }

        // Now, the first index i where nums[i] != i+1 is the missing number
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }

        return n + 1; // all 1..n present, so missing is n+1
    }
};

//! tc is O(n) and sc is O(n) for the second solution using unordered_set
class Solution2{
    public:
    int missingNumber(vector<int> &arr){
        
        unordered_set<int>set;
        for(auto & x:arr){
            set.insert(x);
        }
        for(int i=1;i<100001;i++){
            if(set.find(i)==set.end()){
              return i; 
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3, 4, -1, 1};
    cout << "The smallest positive missing number is: " << sol.missingNumber(nums) << endl;

    Solution2 sol2;
    cout << "Using unordered_set, the smallest positive missing number is: " << sol2.missingNumber(nums) << endl;

    return 0;
}