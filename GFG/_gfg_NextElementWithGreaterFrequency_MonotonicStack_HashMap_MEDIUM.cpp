#include <bits/stdc++.h>
using namespace std;    
class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n,-1);
        
        unordered_map<int,int> mp;
        for(int x : arr) {
            mp[x]++;
        }
        
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(!st.empty()){
                while(!st.empty() && mp[st.top()]<=mp[arr[i]]){
                    st.pop();
                }
                if(!st.empty()){
                    ans[i]=st.top();
                }
            }
            st.push(arr[i]);
        }
        return ans;
    }
};


int main(){
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 2, 1, 3};
    vector<int> result = obj.findGreater(arr);
    
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}