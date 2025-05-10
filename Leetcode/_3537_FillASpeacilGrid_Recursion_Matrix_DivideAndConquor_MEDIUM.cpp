#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void fillGrid(vector<vector<int>>&res,int row,int col,int size,int &count){
        if(size==1){
            res[row][col]=count++;
            return;
        }
        int half = size / 2;

        fillGrid(res, row, col + half, half, count);

        fillGrid(res, row + half, col + half, half, count);

        fillGrid(res, row + half, col, half, count);

        fillGrid(res, row, col, half, count);
    }
    vector<vector<int>> specialGrid(int n) {
        int m=pow(2,n);

        vector<vector<int>>res(m,vector<int>(m,0));
        int count=0;
        fillGrid(res,0,0,m,count);
        return res;

    }
};


int main(){
    Solution obj;
    int n=3;
    vector<vector<int>>result=obj.specialGrid(n);
    for(auto &row:result){
        for(auto &ele:row){
            cout<<ele<<" ";
        }
        cout<<endl;
    }   
    return 0;
}