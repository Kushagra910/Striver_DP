// 130. Surrounded Regions

// Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// observation - if O is at a boundary then itself and all other 'O' connected to him can never be converted and if these
// 'O' are no where  connected to the boundary so thereby they are bound to be surrounded

// Apply DFS

// TC = O(N)+ O(M) + O(N*M*4) --> 2 forloop + dfs at worst case when all are 'O'
// SC = O(N*M) + O(N*M) -> Auxiliary Space + vis => O(N*M)
class Solution {

private:

    bool isValid(int row,int col,vector<vector<char>>&board,int n,int m,vector<vector<int>>&vis){
        if(row>=0 and row<n and col>=0 and col<m and !vis[row][col] and board[row][col] == 'O'){
            return true;
        }
        return false;
    }
    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1};
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&board,int n,int m){
        vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(isValid(nrow,ncol,board,n,m,vis)){
                dfs(nrow,ncol,vis,board,n,m);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            // Traverse first col
            if(!vis[i][0]  and board[i][0] == 'O'){
                dfs(i,0,vis,board,n,m);
            }
            // Traverse last column
            if(!vis[i][m-1] and board[i][m-1] == 'O'){
                dfs(i,m-1,vis,board,n,m);
            }
        }
        for(int j=0;j<m;j++){
            // Traverse first row
            if(!vis[0][j]  and board[0][j] == 'O'){
                dfs(0,j,vis,board,n,m);
            }
            // Traverse last row
            if(!vis[n-1][j] and board[n-1][j] == 'O'){
                dfs(n-1,j,vis,board,n,m);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};