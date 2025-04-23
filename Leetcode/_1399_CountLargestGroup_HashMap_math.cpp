#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void getsum_and_putintomap(int i,unordered_map<int,int>&hm){
            int sum=0;
            while(i>0){
                sum+=i%10;
                i=i/10;
            }
            hm[sum]++;
        }
        int countLargestGroup(int n) {
            if(n<=9){
                return n;
            }
            unordered_map<int,int>hm;
            for(int i=1;i<=n;i++){
                getsum_and_putintomap(i,hm);
            }
            int maxgrpwithlargestsize=0;
            for(auto &x:hm){
                maxgrpwithlargestsize=max(maxgrpwithlargestsize,x.second);
            }
            int count=0;
            for(auto &x:hm){
                if(x.second==maxgrpwithlargestsize){
                    count++;
                }
            }
            return count;
    
    
        }
    };

    int main(){
        Solution obj;
        cout<<obj.countLargestGroup(13);
        return 0;
    }