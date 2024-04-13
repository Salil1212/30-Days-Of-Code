// 85. Maximal Rectangle
// Hard

// 10212

// 178

// Add to List

// Share
// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

// Example 1:


// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = [["0"]]
// Output: 0
// Example 3:

// Input: matrix = [["1"]]
// Output: 1
 

// Constraints:

// rows == matrix.length
// cols == matrix[i].length
// 1 <= row, cols <= 200
// matrix[i][j] is '0' or '1'.

// Solution



#include<iostream>
#include<bits/stdc++.h>
using namespace std;


 int findLargestAreaInHistogram(int n,vector<int>&rowHistogram){
        int area=0;
        for(int i=0;i<n;i++){
            int breadth=1;
            area=max(area,rowHistogram[i]*breadth);
            for(int j=i-1;j>=0;j--){
                if(rowHistogram[j]>=rowHistogram[i]){
                    breadth++;
                }
                else{
                    break;
                }
            }
            for(int j=i+1;j<n;j++){
                if(rowHistogram[j]>=rowHistogram[i]){
                    breadth++;
                }
                else{
                    break;
                }
            }
            area=max(area,rowHistogram[i]*breadth);
        }
        return area;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
      int n=matrix.size();
        int m=matrix[0].size();
        int area=0;
        
        vector<int>rowHistogram(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    rowHistogram[j]++;
                }
                else{
                    rowHistogram[j]=0;
                }
            }
            area=max(area,findLargestAreaInHistogram(m,rowHistogram));
        }
        return area;
        
    }
  
    int main(){
        vector<vector<char>>matrix;
        matrix.push_back({'1','0','1','0','0'});
        matrix.push_back({'1','0','1','1','1'});
        matrix.push_back({'1','1','1','1','1'});
        matrix.push_back({'1','0','0','1','0'});
        cout<<maximalRectangle(matrix);
        return 0;
        
    }