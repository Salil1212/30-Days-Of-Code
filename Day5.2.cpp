// 129. Sum Root to Leaf Numbers
// Medium

// 7852

// 136

// Add to List

// Share
// You are given the root of a binary tree containing digits from 0 to 9 only.

// Each root-to-leaf path in the tree represents a number.

// For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
// Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

// A leaf node is a node with no children.

 

// Example 1:


// Input: root = [1,2,3]
// Output: 25
// Explanation:
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Therefore, sum = 12 + 13 = 25.
// Example 2:


// Input: root = [4,9,0,5,1]
// Output: 1026
// Explanation:
// The root-to-leaf path 4->9->5 represents the number 495.
// The root-to-leaf path 4->9->1 represents the number 491.
// The root-to-leaf path 4->0 represents the number 40.
// Therefore, sum = 495 + 491 + 40 = 1026.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// 0 <= Node.val <= 9
// The depth of the tree will not exceed 10.


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
int ans=0;

    void sumNum(TreeNode* root,int value){
        if(!root){
            
            return ;
        }
        if(!root->left && !root->right){
            value=value*10+root->val;
            ans +=value;
            return ;
        }
        if(root->left)sumNum(root->left,value*10+root->val);
        if(root->right)sumNum(root->right,value*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        int value=0;
        sumNum(root,value);
        return ans;
    }
int main(){
    struct TreeNode *n1=new TreeNode(1);
    struct TreeNode *n2=new TreeNode(2);
    struct TreeNode *n3=new TreeNode(3);
    n1->left=n2;
    n1->right=n3;
    cout<<sumNumbers(n1);
    return 0;
}