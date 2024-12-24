#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        for(int i=0;i<mat.size();i++){
            int l=0;
            int r=mat[0].size()-1;
            
            if(mat[i][0]<=x && x<=mat[i][mat[0].size()-1]){
                while(l<=r){
                int mid=l+(r-l)/2;
                    if(mat[i][mid]==x){
                        return true;
                    }else if(mat[i][mid]<x){
                        l=mid+1;
                        
                    }else{
                        r=mid-1;
                    }
                }
            }
        }
        return false;
    }
};
int main(){

    Solution s;
    vector<vector<int>> mat={{1,5,9},{14,20,21},{30,34,43}};
    auto res=s.searchMatrix(mat,14);
    cout<<res<<endl;
}