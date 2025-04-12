#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void helper(vector<vector<int>>& image,int sr,int sc,int newColor,int oldColor,vector<vector<bool>>&vis){
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || vis[sr][sc] || image[sr][sc] != oldColor) {      //if the cell is out of bound or already visited or not equal to old color then return
              return;
          }
          image[sr][sc] = newColor;
          vis[sr][sc] = true;
          // 4 directions
          //this diretion is important to avoid stackoverflow error and also to avoid infinite loop
  
          //down
          helper(image, sr + 1, sc, newColor, oldColor, vis);
          //up
          helper(image, sr - 1, sc, newColor, oldColor, vis);
          //right
          helper(image, sr, sc + 1, newColor, oldColor, vis);
          //left
          helper(image, sr, sc - 1, newColor, oldColor, vis);
        
    }
      vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                    int newColor) {
          // Code here
          int oldColor = image[sr][sc];
          if (oldColor == newColor) return image; // Prevent infinite loop
  
          vector<vector<bool>> vis(image.size(), vector<bool>(image[0].size(), false));
          helper(image, sr, sc, newColor, oldColor, vis);
          return image;
          
      }
  };

  int  main(){
    Solution s;
    vector<vector<int>>image={{1,1,1,0},{0,1,1,1},{1,0,1,1}};
    int sr=1;
    int sc=2;
    int newColor=2;
    auto res=s.floodFill(image,sr,sc,newColor);
    for(auto &x:res){
        for(auto &y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
  }