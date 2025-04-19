#include <bits/stdc++.h>
using namespace std;



class Solution {
    public:
      vector<int> makeBeautiful(vector<int> arr) {
          // code here
          stack<int>st;
          for(auto &x:arr){
              if(!st.empty() && ((st.top()>=0 && x<0)||(st.top()<0 && x>=0))){
                  st.pop();
              }else{
                  
              st.push(x);
              }
          }
          vector<int>res;
          while(!st.empty()){
              res.push_back(st.top()); st.pop();
          }
          reverse(res.begin(),res.end());
          return res;
      }
  };

  
  int main(){
    Solution obj;
    vector<int> arr={-2,-3,-1,0,1,2,3,4,5};
    vector<int> res=obj.makeBeautiful(arr);
    for(auto x:res){
        cout<<x<<" ";
    }
    return 0;
  }