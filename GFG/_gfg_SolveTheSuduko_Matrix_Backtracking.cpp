#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    bool solved(vector<vector<int>> &mat, int r, int c, vector<vector<bool>> &rows, vector<vector<bool>> &cols,vector<vector<vector<bool>>> &box){
        // move to next row
        if(c==9)
            return solved(mat,r+1,0,rows,cols,box);
        // every other row is filled successfully
        if(r==9)
            return true;
        // if vacant cell move forward
        if(mat[r][c]!=0)
            return solved(mat,r,c+1,rows,cols,box);
        
        // put 1-9 possible values
        for(int k=1; k<10; k++){
            // if k in row, col or box, don't put it in cell
            if(rows[r][k] || cols[c][k] || box[r/3][c/3][k] )
                continue;
                
            // set K as present, in current row, col and (3x3) box
            rows[r][k]= true;
            cols[c][k]= true;
            box[r/3][c/3][k]= true;
            // set cell as k
            mat[r][c]=k;
            
            // once solved don't try other numbers... 
            // if backtracks then matrix values will change (passed by reference)
            if(solved(mat,r,c+1,rows,cols,box))
                return true;
            
            // reset k from row, col, box if putting k didn't solve sudoku
            rows[r][k]= false;
            cols[c][k]= false;
            box[r/3][c/3][k]= false;
            
        }
        
        // reset cell if nothing works
        mat[r][c]=0;
        return false;
    }
    
  
    // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        
        // rows or cols[i][k] checks if k is present in i th row or col
        vector<vector<bool>> rows(9,vector<bool>(10,false));
        vector<vector<bool>> cols(9,vector<bool>(10,false));
        // box[i][j][k]  checks if k is present in i,j box of size 3x3
        vector<vector<vector<bool>>> box(3,vector<vector<bool>>(3,vector<bool>(10,false)));
       
       // initialize above for already present values
       for(int i=0; i<9; i++){
           for(int j=0; j<9; j++){
               int k = mat[i][j];
               if(k){
                   rows[i][k]= true;
                   cols[j][k]= true;
                   box[i/3][j/3][k]= true;
               }
           }
       }
       
        solved(mat,0,0,rows,cols,box);
    }
};

int main(){
    Solution s;
    vector<vector<int>> mat = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 8, 6, 3, 0, 0}
    };

    s.solveSudoku(mat);
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}