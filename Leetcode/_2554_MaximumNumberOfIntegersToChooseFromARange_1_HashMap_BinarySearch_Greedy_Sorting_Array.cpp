#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int s=0;
        unordered_set<int>st(banned.begin(),banned.end());
        int count=0;
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end()){
                s+=i;
                count++;
                if(s>maxSum){
                    s-=i;
                    count--;
                }

            }

        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int>banned={1,6,5};
    int n=5;
    int maxSum=6;
    cout<<s.maxCount(banned,n,maxSum)<<endl;
    int abc=0;
    
}