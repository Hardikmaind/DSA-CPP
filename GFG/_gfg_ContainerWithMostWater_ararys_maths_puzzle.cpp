#include<bits/stdc++.h>
using namespace std;

class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        // int mx=0;
        
        int l=0;
        int r=arr.size()-1;
        int tmx=0;
        
        while(l<r){
            
        
        int a= (r-l)*min(arr[l],arr[r]);
            tmx =max(a,tmx);
             
            if(arr[l]<arr[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return  tmx;
        
    }
};


int main(){
    Solution ob;
    vector<int> arr = {2, 1, 8, 6, 4, 6, 5, 5};
    cout<<ob.maxWater(arr)<<endl;

}