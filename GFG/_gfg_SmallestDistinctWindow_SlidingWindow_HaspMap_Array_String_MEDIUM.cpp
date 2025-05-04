#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
      int findSubString(string& str) {
          // code here
          int l=0,r=0,n=str.size();
          unordered_set<char>set;
          unordered_map<char,int>map;
          for(auto &x:str){
              set.insert(x);
          }
          int distinctEle=set.size();
          int minWindow=INT_MAX;
          while(r<n){
              map[str[r]]++;
              while(map.size()==distinctEle){
                  minWindow=min(r-l+1,minWindow);
                  map[str[l]]--;
                  if(map[str[l]]==0){
                      map.erase(str[l]);
                  }
                  l++;
              }
              r++;
              
          }
          return minWindow;
      }
  };

  int main(){
    Solution obj;
    string str = "geeksforgeeks";
    cout<< obj.findSubString(str) << endl; // Output: 7 (the smallest window is "eksforg")

    //test case 2
    str = "aabbcc";
    cout<< obj.findSubString(str) << endl; // Output: 6 (the smallest window is "aabbcc")

    
    
    return 0;

  }