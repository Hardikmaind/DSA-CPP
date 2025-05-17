#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int p0 = 0, curr = 0, p2 = nums.size() - 1;
        while (curr <= p2) {
            if (nums[curr] == 0) {
                std::swap(nums[curr], nums[p0]);
                curr++;
                p0++;
            } else if (nums[curr] == 2) {
                std::swap(nums[curr], nums[p2]);
                p2--;
            } else {
                curr++;
            }
        }
    }
};

class Solution1 {
public:
    void sortColors(std::vector<int>& nums) {
        int c0 = 0, c1 = 0, c2 = 0;
        for (int num : nums) {
            if (num == 0) c0++;
            else if (num == 1) c1++;
            else c2++;
        }
        int i = 0;
        for (; i < c0; ++i) nums[i] = 0;
        for (; i < c0 + c1; ++i) nums[i] = 1;
        for (; i < c0 + c1 + c2; ++i) nums[i] = 2;
    }
};

int main(){
    Solution s;
    std::vector<int> nums = {2, 0, 2, 1, 1, 0};
    s.sortColors(nums);
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    

    Solution1 s1;

    std::vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    s1.sortColors(nums1);
    for (int num : nums1) {
        std::cout << num << " ";
    }
    return 0;
}
