#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            int l=0,r=0,maxfruits=0,n=fruits.size();
        
            unordered_map<int,int>map;
            while(r<n){
                map[fruits[r]]++;
    
                while (map.size() > 2) {
                    map[fruits[l]]--;
                    if (map[fruits[l]] == 0)
                        map.erase(fruits[l]);        
                    l++;
                }
    
                maxfruits = max(maxfruits, r - l + 1);
                r++;
    
                
                
            }
            return maxfruits;
        }
    };

    int main(){
        Solution s;
        vector<int>arr={0,1,2,2};
        cout<<s.totalFruit(arr)<<endl;
        return 0;
    }