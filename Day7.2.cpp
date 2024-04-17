// 988. Smallest String Starting From Leaf
// Medium

// 2132

// 307

// Add to List

// Share
// You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

// Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

// As a reminder, any shorter prefix of a string is lexicographically smaller.

// For example, "ab" is lexicographically smaller than "aba".
// A leaf of a node is a node that has no children.

 

// Example 1:


// Input: root = [0,1,2,3,4,3,4]
// Output: "dba"
// Example 2:


// Input: root = [25,1,3,1,3,0,2]
// Output: "adz"
// Example 3:


// Input: root = [2,2,1,null,1,0,null,0]
// Output: "abc"
 

// Constraints:

// The number of nodes in the tree is in the range [1, 8500].
// 0 <= Node.val <= 25
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(){
         val=0;
         left=NULL;
         right=NULL;
     }
     TreeNode(int x){
         val=x;
         left=NULL;
         right=NULL;
     }
     TreeNode(int x, TreeNode *left, TreeNode *right) {
         val=x;
         left=NULL;
         right=NULL;
     }
 };
  void smallLeaf(TreeNode* root,string str,vector<string>&ans){
      if (!root->left && !root->right) { // Leaf node
        str += char(97 + root->val);
        reverse(str.begin(), str.end()); // Reverse the string
        ans.push_back(str);
        return;
    }
    str += char(97 + root->val);
    if (root->left)
        smallLeaf(root->left, str, ans);
    if (root->right)
        smallLeaf(root->right, str, ans);
        
        
        
    }
    string smallestFromLeaf(TreeNode* root) {
        string str="";
      vector<string>ans;
        smallLeaf(root,str,ans);
        str=ans[0];
        for(int i=1;i<ans.size();i++){
            if(str>ans[i]){
                str=ans[i];
            }
        }
        return str;
    }
int main(){
   struct TreeNode *n1=new TreeNode(0);
    struct TreeNode *n2=new TreeNode(1);
    struct TreeNode *n3=new TreeNode(2);
    struct TreeNode *n4=new TreeNode(3);
    struct TreeNode *n5=new TreeNode(4);
    struct TreeNode *n6=new TreeNode(3);
    struct TreeNode *n7=new TreeNode(4);
  
    n1->left=n2;
    n1->right=n3;
    n2->left=n4;
    n2->right=n5;
    n3->left=n6;
    n3->right=n7;
      
cout<<smallestFromLeaf(n1);
    return 0;
}