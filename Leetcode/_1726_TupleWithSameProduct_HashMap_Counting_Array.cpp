#include <bits/stdc++.h>
using namespace std;
/*import java.util.HashMap;

class Solution {
    public int tupleSameProduct(int[] nums) {
        var hm = new HashMap<Integer, Integer>();

        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                int product = nums[i] * nums[j];
                hm.put(product, hm.getOrDefault(product, 0) + 1);
            }
        }

        int count = 0;
        for (int freq : hm.values()) {
            if (freq > 1) {
                count += (freq * (freq - 1) / 2) * 8; // Each tuple has 8 permutations
            }
        }

        return count;
    }
}
 */

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>hm;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int prod=nums[i]*nums[j];
                hm[prod]++;
            }
        }
        int count=0;
        for(auto freq:hm){                  //! freq is a pair and freq.first is the product and freq.second is the frequency of that product
            if(freq.second>1){
                count+=(freq.second*(freq.second-1)/2)*8;
            }
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int> nums={1,2,4,5,10};
    cout<<s.tupleSameProduct(nums);
    return 0;
}