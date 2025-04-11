
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // ! exact tc is O(2n) and sc is O(n)
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
        //! this below is more efficient than above and exact tc is O(n) and sc is O(1)
        int totalFruit2(vector<int>& fruits) {
            int l=0,r=0,maxfruits=0,n=fruits.size();
        
            unordered_map<int,int>map;
            while(r<n){
                map[fruits[r]]++;
    
                if (map.size() > 2) {           //! this is the optimization step, here i removed the while loop. HERE NO NEED TO SHRINK THE WINDOW  SIZE BELOW MAXFRUITS
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
        cout<<s.totalFruit2(arr)<<endl;
        return 0;
    }