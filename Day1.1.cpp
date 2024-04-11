// Problem Statement
// Given an integer number n, which is a decimal representation of Gray Code. 
// Find the binary equivalent of the Gray Code & return the decimal representation of the binary equivalent.
// Example 1:

// Input: 
// n = 4
// Output: 
// 7
// Explanation:
// Given 4, its gray code =  110.
// Binary equivalent of the gray code 110 is 100.
// Return 7 representing gray code 100.
// Example 2:

// Input: 
// n = 15
// Output: 
// 10
// Explanation:
// Given 15 representing gray code 1000.
// Binary equivalent of gray code 1000 is 1111.
// Return 10 representing gray code 1111 
// ie binary 1010.
// Your Task: 
// You don't need to read input or print anything. Your task is to complete the function grayToBinary() which accepts an integer n as an input parameter and returns decimal representation of the binary equivalent of the given gray code.

// Expected Time Complexity: O(log (n)).
// Expected Auxiliary Space: O(1).

// Constraints:
// 0 <= n <= 108


// Solution:

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
   
int grayToBinary(int n){
        
if(n==0) return 0;
string ans="";
string temp="";
int num=n;
while(num>0){
int rem=num%2;
num /=2;
temp +=to_string(rem);
}
for(int i=temp.size()-1;i>=0;i--){
    ans +=temp[i];
        }
    
string val;
val.push_back(ans[0]);
int prev=val[0]-'0';
for(int i=1;i<ans.size();i++){
        val += to_string((ans[i]-'0')^ prev);
        prev=val[i]-'0';
        }
  
int value=0;
reverse(val.begin(),val.end());
for(int i=0;i<val.size();i++){
int x=val[i]-'0';
value +=x*pow(2,i);
    
}

return value;
}
   
int main(){
        cout<<grayToBinary(15);
        return 0;
    }