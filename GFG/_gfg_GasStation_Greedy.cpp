#include <bits/stdc++.h>
using namespace std;

/*You are required to complete this method*/
class Solution {
    public:
      int startStation(vector<int> &gas, vector<int> &cost) {
         
          int total=0;
          int req=0;
          for(int i=0;i<cost.size();i++){
              req+=cost[i];
              total+=gas[i];
          }
          if(total < req) return -1;
          int ans=0;
          int currgas=0;
          for(int i=0;i<gas.size();i++){
              currgas+=gas[i]-cost[i];
              if(currgas<0) {
                  ans=i+1;
                  currgas=0;
              }
          }
          return ans;
      }
  };

  
  int main(){
        vector<int> gas = {4, 5, 7, 4};
        vector<int> cost = {6, 6, 3, 5};
        Solution obj;
        int result = obj.startStation(gas, cost);
        cout << result << endl; // Output: 1
  }