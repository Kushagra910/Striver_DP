// 733. Flood Fill


// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
// You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
// Return the modified image after performing the flood fill.

// Done by BFS Approach
// SC = O(n*m) + O(n*m) + O(n*m) = O(n*m)
// TC = O(n*m) + O(n*m*4)
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>ans = image;
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0)); // no need
        q.push({sr,sc});
        vis[sr][sc] = color;
        ans[sr][sc] = color;
        int initialColor = image[sr][sc];
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++){
                int nrow = row+delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && (image[nrow][ncol] == initialColor)&& vis[nrow][ncol] != color){
                    vis[nrow][ncol] = color; // no need
                    ans[nrow][ncol] = color;
                    q.push({nrow,ncol});
                }
            }
        }
        return ans;
    }
};