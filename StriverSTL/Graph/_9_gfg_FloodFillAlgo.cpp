#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void dfs(vector<vector<int>>& image, int sr, int sc,int newColor,int oldColor,vector<vector<bool>>& vis){
            if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || vis[sr][sc] || image[sr][sc] != oldColor) {      //if the cell is out of bound or already visited or not equal to old color then return
                return;
            }
            image[sr][sc] = newColor;
            vis[sr][sc] = true;
            // 4 directions
            //this diretion is important to avoid stackoverflow error and also to avoid infinite loop
    
            //down
            dfs(image, sr + 1, sc, newColor, oldColor, vis);
            //up
            dfs(image, sr - 1, sc, newColor, oldColor, vis);
            //right
            dfs(image, sr, sc + 1, newColor, oldColor, vis);
            //left
            dfs(image, sr, sc - 1, newColor, oldColor, vis);
        }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int newColor) {

        int oldColor = image[sr][sc];
        if (oldColor == newColor) return image; // Prevent infinite loop

        vector<vector<bool>> vis(image.size(), vector<bool>(image[0].size(), false));
        dfs(image, sr, sc, newColor, oldColor, vis);
        return image;
    }
    
};


//? HERE IN BELOW SOLUTION. WE HAVE NOT USED THE VISITED ARRAY,SINCE THERE WAS NO NEED. AND WE HAVE COPIED THE IMAGE ARRAY TO newImage array. AND WE MARK THE OLDPIXEL TO NEW PIXEL AFTER VISITING AND ALSO CHECKING THAT IF THE PIXEL IS ALREADY NEW DONT VISIT. SO BECAUSE OF THIS WE DONT NEED THE VISITED ARRAY
 class Solution2{
    private:
        void dfs(int r,int c,vector<vector<int>>& newImage,int newColor,int oldColor,int dirx[],int diry[]){
            newImage[r][c]=newColor;
            int n=newImage.size();
            int m=newImage[0].size();
            for(int i=0;i<4;i++){
                int nRow=r+dirx[i];
                int nCol=c+diry[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<=m && newImage[nRow][nCol]!=newColor){
                    dfs(nRow,nCol,newImage,newColor,oldColor,dirx,diry);
                }
            }
        }
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int newColor) {

            int oldColor = image[sr][sc];
            if (oldColor == newColor) return image; // Prevent infinite loop
            int dirx[]={0,1,0,-1};
            int diry[]={1,0,-1,0};
            vector<vector<int>>newImage=image;          //! here i have created the copy of the image array. in real life it is not good to modify the array in place. We can also do it in the same array.
            dfs( sr, sc,newImage, newColor, oldColor,dirx,diry);
            return image;
        }
        
 };
int main(){
    Solution s;
    vector<vector<int>> images={{1,1,1},{1,1,0},{1,0,1}};
    int newColor=2;
    auto res=s.floodFill(images,0,0,newColor);
    for(auto x:res){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }


    cout<<endl;

    // #########################################################

    Solution2 s2;
    vector<vector<int>> images2={{1,1,1},{1,1,0},{1,0,1}};
    int newColor2=2;
    auto res2=s.floodFill(images2,0,0,newColor2);
    for(auto x:res2){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;

}