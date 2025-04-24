#include <bits/stdc++.h>
using namespace std;

class Solution2
{
public:
    vector<int> singleNum(vector<int> &arr)
    {
        // Code here.

        //!   int map[1000000]={0};. cannot be used here. give segmentation fault
        unordered_map<int, int> map;
        for (auto &x : arr)
        {
            map[x]++;
        }
        vector<int> res;
        for (auto &x : arr)
        {
            if (map[x] == 1)
            {
                res.push_back(x);
            }
        }
        if (res[0] > res[1])
        {
            swap(res[0], res[1]);
        }
        return res;
    }
};

class Solution
{
public:
    vector<int> singleNum(vector<int> &nums)
    {
        int xorAll = 0;
        for (int num : nums)
        {
            xorAll ^= num;
        }

        // Get rightmost set bit (differentiating bit)
        int diffBit = xorAll & (-xorAll);

        int a = 0, b = 0;
        for (int num : nums)
        {
            if (num & diffBit)
                a ^= num;
            else
                b ^= num;
        }

        if (a > b)
            swap(a, b);
        return {a, b};
    }
};

class Solution3{
    public:
    vector<int> singleNum(vector<int> &nums){
        vector<int>res(2,0);
        int index=0;
        for(int i=0;i<nums.size();i++){
            bool found=false;
            for(int j=0;j<nums.size();j++){
                if(i!=j && nums[i]==nums[j]){
                    found=true;
                    break;
                }
            }
            if(!found){
                res[index++]=nums[i];
                if(index==2){
                    break;
                }
            }
            
        }
        if (res[0] > res[1]) {
            swap(res[0], res[1]);
        }
        return res;

    }
};

int main()
{
    //!=========================== tc is O(n) and SC is O(1)...This below code is more optimised
    Solution obj;
    vector<int> arr = {1, 2, 3, 2, 1, 4};
    auto res = obj.singleNum(arr);
    for (auto &x : res)
    {
        cout << x << " ";
    }
    cout << endl;
    
    //!=========================== tc is O(n) and SC is O(n)
    Solution2 obj2;
    vector<int> arr2 = {1, 2, 3, 2, 1, 4};
    auto res2 = obj2.singleNum(arr2);
    for (auto &x : res2)
    {
        cout << x << " ";
    }
    
    cout << endl;
    
    //!=========================== tc is O(n^2) and SC is O(1)
    Solution3 obj3;
    vector<int> arr3 = {1, 2, 3, 2, 1, 4};
    auto res3 = obj3.singleNum(arr3);
    for (auto &x : res3)
    {
        cout << x << " ";
    }
    return 0;
}
