#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

//tc is O(m*n) and sc is(m+n)=? sc can be optimised to O(1);
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool>row(matrix.size(),false);
        vector<bool>col(matrix[0].size(),false);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(!matrix[i][j]){
                    row[i]=true;
                    col[j]=true;
                }
            }
        }

         for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(row[i] || col[j]){
                    matrix[i][j]=0;
                }
            }
        }
       
    }
};


//! below is more optimised code with tc O(m*n) and sc O(1);
class Solution2{
    public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zeroinFirstCol = false;
        for (int row = 0; row < matrix.size(); row++) {
            if (matrix[row][0] == 0) zeroinFirstCol = true;
            for (int col = 1; col < matrix[0].size(); col++) {
                if (matrix[row][col] == 0) {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }

        for (int row = matrix.size() - 1; row >= 0; row--) {
            for (int col = matrix[0].size() - 1; col >= 1; col--) {
                if (matrix[row][0] == 0 || matrix[0][col] == 0) {
                    matrix[row][col] = 0;
                }
            }
            if (zeroinFirstCol) {
                matrix[row][0] = 0;
            }
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    s.setZeroes(matrix);
    for(auto i:matrix){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    Solution2 s2;
    vector<vector<int>> matrix2 = {{1,1,1},{1,0,1},{1,1,1}};
    s2.setZeroes(matrix2);
    for(auto i:matrix2){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}