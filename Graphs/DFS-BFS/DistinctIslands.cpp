// Distinct Islands CodeStudio

//You are given a two-dimensional array/list of integers consisting of 0s and 1s. In the list, 1 represents land and 0 represents water.
// The task is to find the number of distinct islands where a group of connected 1s(horizontally or vertically) forms an island.
// Note:
// Two islands are considered to be the same if and only if one island is equal to another(not rotated or reflected) i.e if we can translate one island on another without rotating or reflecting then it would be considered as the same islands. 
// For Example:
// 1 1 0
// 0 0 1
// 0 0 1

// Storing these structures in a set data structure 
// and using the Base concept for compairing lists in which structure are stored

// You have to follow order, like if dfs is Applied so stick to it through out the question

// USING DFS

// set length at max it can store all these elements so n x m
// TC = O(n*m*log(n x m)) + O(n*m*4) overall dfs 
// SC = O(n*m) overall
#include <bits/stdc++.h>
void dfs(int row,int col,vector<vector<int>>&vis,int** arr,vector<pair<int,int>>&vec,int row0,int col0,int n,int m){
    vis[row][col] = 1;
    vec.push_back({row-row0,col-col0});
    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1};
    for(int i=0;i<4;i++){
        int nrow = row+delrow[i];
        int ncol = col + delcol[i];
        if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and arr[nrow][ncol] == 1){
            dfs(nrow,ncol,vis,arr,vec,row0,col0,n,m);
        }
    }
}

int distinctIslands(int** arr, int n, int m)
{
    //Write your code here
    vector<vector<int>>vis(n,vector<int>(m,0));
    set<vector<pair<int,int>>>st;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] and arr[i][j] == 1){
                vector<pair<int,int>>vec;
                dfs(i,j,vis,arr,vec,i,j,n,m);
                st.insert(vec);
            }
        }
    }
    return st.size();
}


