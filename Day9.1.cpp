// 200. Number of Islands
// Medium
// Topics
// Companies
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.



#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 void islands(vector<vector<char>>&grid,vector<vector<int>>&visited,int i,int j){
        visited[i][j]=1;
        if(i-1>=0 && grid[i-1][j]=='1' && visited[i-1][j]!=1){
            islands(grid,visited,i-1,j);
        }
        if(i+1<grid.size() && grid[i+1][j]=='1' && visited[i+1][j]!=1){
            islands(grid,visited,i+1,j);
        }
        if(j-1>=0 && grid[i][j-1]=='1' && visited[i][j-1]!=1){
            islands(grid,visited,i,j-1);
        }
        if(j+1<grid[0].size() && grid[i][j+1]=='1' && visited[i][j+1]!=1){
            islands(grid,visited,i,j+1);
        }

    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count=0; 
        // return count;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if( grid[i][j]=='1' && visited[i][j]!=1){
                    count += 1;
                    islands(grid,visited,i,j);
                    
                }
            }
        }
        return count;
    }
int main(){
    vector<vector<char>>grid={{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    cout<<"The number of islands "<<numIslands(grid);
    
    return 0;
}
