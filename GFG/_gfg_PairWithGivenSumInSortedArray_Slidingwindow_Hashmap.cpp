#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int left=0,right=arr.size()-1;
        int res =0;
        while(left < right){
            int sum = arr[right] + arr[left];
            if(sum == target){
                int cnt1=0,cnt2=0;
                int elem1=arr[left],elem2=arr[right];
                while(elem1 == arr[left] && left <= right){
                    cnt1++;
                    left++;    
                }
                while(elem2 == arr[right] && left <= right){
                    cnt2++;
                    right--;
                }
                if(elem1 == elem2) 
                    res += (cnt1 * (cnt1 - 1))/2;
                else
                    res += (cnt1 * cnt2);
            } else if(sum > target){
                right--;
                
            } else{
                left++;
            }
        }
        return res;
    }
    int countPairs2(vector<int> &arr, int target) {
        // Complete the function
         multiset<int> st;
        int count=0;
        for(auto &x:arr){
            int complement = target - x;
            int setcount=st.count(complement);
            if (setcount > 0) {     
                count+=setcount;
            }
            st.insert(x);
        }
       
        return count;
    }
     int countPairs3(vector<int> &arr, int target) {
        // Complete the function
        int ans = 0;
        int n = arr.size();
        unordered_map<int ,int> mp;
        for(int i=0;i<n;i++){
            int k = target - arr[i];
            if(mp.find(k) != mp.end()) ans += mp[k];
            mp[arr[i]]++;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1, 1, 1, 1};
    int target = 2;
    cout<<s.countPairs(arr,target)<<endl;


    vector<int> arr2 = {-1, 1, 5, 5, 7};
    int target2 = 6;
    cout<<s.countPairs2(arr2,target2)<<endl;
    
    vector<int> arr3 = {1, 1, 1, 1};
    int target3 = 2;
    cout<<s.countPairs3(arr3,target3)<<endl;

    return 0;
}