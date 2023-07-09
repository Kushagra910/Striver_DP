//Distance Of Nearest Cell Having 1 In A Binary Matrix CodeStudio

// You have been given a binary matrix 'MAT' containing only 0’s and 1’s of size N x M. You need to find the distance of the nearest cell having 1 in the matrix for each cell.
// The distance is calculated as |i1 – i2| + |j1 – j2|, where i1, j1 are the coordinates of the current cell and i2, j2 are the coordinates of the nearest cell having value 1.
// Note :
// You can only move in four directions which are : Up, Down, Left and Right.

// when you are at 1 and you say them to take 1 step they will reach all zeros that are
// at a distance one Or apparently i can say the nearest one for these zeros are at distance0 1 
// now again take one step and for these zero 1's is at 2 step away and so on..

 // So BFS is applied because we have to move level/ step wise

 // TC = O(n*m) + O(n*m*4)
 // SC = O(n*m) + O(n*m) = O(n*m)
 vector < vector < int > > nearest(vector< vector < int >> & mat, int n, int m) {
    // Write your code here.
    vector<vector<int>>dist(n,vector<int>(m,0));
    vector<vector<int>>vis(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 1){
                vis[i][j] = 1;
                q.push({{i,j},0});
            }
            else{
                vis[i][j] = 0;
            }
        }
    }

    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1}; 
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        dist[row][col] = steps;
        for(int i=0;i<4;i++){
            int nrow = row+delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0){
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, steps + 1});
            }
        }
    }
    return dist;
}


// In Leetcode 542 -O1 matrix is also the same problem 
// but we just have to find distance of nearest 1 for each cell
// just try to find zero and from that apply BFS in order to find the nearest 1
