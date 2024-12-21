#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // code here
        for(auto &x:mat){
            reverse(x.begin(),x.end());
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(i>=j){
                    
                
                swap(mat[i][j],mat[j][i]);
                }
            }
        }
    }
};
int main(){
    Solution s;
    vector<vector<int>> v={{1,2,3},{4,5,6},{7,8,9}};
    s.rotateby90(v);
    for(auto &x:v){
        for(auto &y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}