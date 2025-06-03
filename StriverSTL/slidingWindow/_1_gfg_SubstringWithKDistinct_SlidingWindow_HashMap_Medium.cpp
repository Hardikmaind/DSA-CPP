#include <bits/stdc++.h>
using namespace std;

// this kind of problem is solved using using the pattern 2
// Question 1: No of subarrays  with sum =k. 
// here the condition is constant that we want sum =k. and not sum<k. so in this quesiton it is tough to understand whether to expand or shrink the window


// so we break the problem into two parts.
// 1. we will find the number of subarrays with sum <=k.
// 2. we will find the number of subarrays with sum <=k-1.
// 3. we will subtract the two to get the number of subarrays with sum =k.

class Solution {
  public:
  int countAtMostK(string &s,int k){
      int count=0;
        int l=0,r=0;
        
        unordered_map<char,int>hm;
        int n=s.size();
        while(r<n){
            hm[s[r]]++;
            while(hm.size()>k){
                hm[s[l]]--;
                if(hm[s[l]]==0){
                    hm.erase(s[l]);
                }
                l++;
            }
            
                count+=r-l+1;
            
            r++;
            
            
        }
        return count;
  }
    int countSubstr(string& s, int k) {
        // code here.
        return countAtMostK(s, k) - countAtMostK(s, k - 1);
    }
};


int main(){
    Solution obj;
    string s = "abc";
    int k = 2;
    int result = obj.countSubstr(s, k);
    cout << "Count of substrings with exactly " << k << " distinct characters: " << result << endl;
    return 0;
}