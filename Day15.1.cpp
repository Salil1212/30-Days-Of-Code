// Exit Point in a Matrix
// EasyAccuracy: 50.0%Submissions: 23K+Points: 2
//  Done with winning Geekbits? Now win GfG Bag, GfG T-shirt & much more just by writing your experiences. Start Writing, Start Winning.
// banner
// Given a matrix of size n x m with 0’s and 1’s, you enter the matrix at cell (0,0) in left to right direction. Whenever you encounter a 0 you retain it in the same direction, else if you encounter a 1 you have to change the direction to the right of the current direction and change that 1 value to 0, you have to find out from which index you will leave the matrix at the end.

// Example 1:

// Input: 
// n = 3, m = 3
// matrix = {{0, 1, 0},
//           {0, 1, 1}, 
//           {0, 0, 0}}
// Output: 
// {1, 0}
// Explanation: 
// Enter the matrix at (0, 0) 
// -> then move towards (0, 1) ->  1 is encountered 
// -> turn right towards (1, 1)  -> again 1 is encountered 
// -> turn right again towards (1, 0) 
// -> now, the boundary of matrix will be crossed ->hence, exit point reached at 1, 0..
// Example 2:

// Input: 
// n = 1, m = 2
// matrix = {{0, 0}}
// Output: 
// {0, 1}
// Explanation: 
// Enter the matrix at cell (0, 0).
// Since the cell contains a 0, we continue moving in the same direction.
// We reach cell (0, 1), which also contains a 0. So, we continue moving in the same direction, we exit the matrix from cell (0, 1).
// Your Task:
// You don't need to read or print anything. Your task is to complete the function FindExitPoint() which takes the matrix as an input parameter and returns a list containing the exit point.

// Expected Time Complexity: O(n * m) where n = number of rows and m = number of columns.
// Expected Space Complexity: O(1)

// Constraints:
// 1 <= n, m <= 100

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

 vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        vector<int>ans;
        int i=0;
        int j=0;
        
        int dir=0;
        while(true){
            // dir +=(matrix[i][j])%4;
            
            dir = (dir+matrix[i][j])%4;
           if(matrix[i][j]==1){
               matrix[i][j]=0;
           }
            if(dir==0){
                j++;
            }
            else if(dir==1){
                i++;
            }
            else if(dir==2){
                j--;
            }
           else if(dir==3){
               i--;
           }
           if(i<0){
               i++;
               break;
               
               
           }
           else if(j<0){
               j++;
               break;
           }
           else if(i==n){
               i--;
               break;
           }
           else if(j==m){
               j--;
               break;
           }
           
           
        }
        ans.push_back(i);
        ans.push_back(j);
        return ans;
    }
int main(){
    int n=3;
    int m=3;
    vector<vector<int>>matrix={{0,1,0},{0,1,1},{0,0,0}};
    vector<int>ans=FindExitPoint(n,m,matrix);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
