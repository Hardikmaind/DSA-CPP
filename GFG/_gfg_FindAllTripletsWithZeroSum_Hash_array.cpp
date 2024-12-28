#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        vector<vector<int>> ans;
        for(int i=0;i<arr.size();i++){
            unordered_map <int,vector<int>> hm;
            for(int j=i+1;j<arr.size();j++){
                int sum=(arr[i]+arr[j])*-1;
                if(hm.count(sum)>0){
                    for(int k:hm[sum]){
                        vector<int> vec={i,j,k};
                        sort(vec.begin(),vec.end());
                        ans.push_back(vec);
                    }
                }
                hm[arr[j]].push_back(j);
                
            }
        }
        return ans;
    }
};


//! This is Solution 2. tc is O(n^2) and sc is O(n)
class Solution2 {
public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        vector<vector<int>> ans;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> hm; // Store value and index for quick lookup
            for (int j = i + 1; j < n; j++) {
                int sum = -(arr[i] + arr[j]);
                if (hm.count(sum)) {
                    vector<int> triplet = {arr[i], arr[j], sum};
                    sort(triplet.begin(), triplet.end()); // Sort the triplet for consistency
                    if (find(ans.begin(), ans.end(), triplet) == ans.end()) { // Avoid duplicates
                        ans.push_back(triplet);
                    }
                }
                hm[arr[j]] = j; // Add the current number to the map
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> arr={0, -1, 2, -3, 1};
    vector<vector<int>> ans=s.findTriplets(arr);
    for(auto x:ans){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    Solution2 s2;
     vector<int> arr2={0, -1, 2, -3, 1};
    vector<vector<int>> ans2=s.findTriplets(arr2);
    for(auto x:ans2){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

}