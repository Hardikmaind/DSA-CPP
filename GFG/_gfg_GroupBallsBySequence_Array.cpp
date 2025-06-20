#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        
      int n = arr.size();
      if(n%k!=0){
          return false ;
      }
      sort(arr.begin(),arr.end());
      unordered_map<int, int>mp;
      for(int i=0 ; i<n ; i++){
        mp[arr[i]]++;  
      }
      for(int i=0 ; i<n ; i++){
          if(mp[arr[i]]==0){
              continue;
          }
          for(int j=0 ; j<k ; j++){
             if(mp[arr[i]+j]==0) 
             return false ;
             mp[arr[i]+j]--;
          }
      }
      return true ;
    }
};

int main(){
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int k = 3;
    bool result = obj.validgroup(arr, k);
    cout << (result ? "True" : "False") << endl;
    return 0;

}