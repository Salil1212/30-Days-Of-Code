// 404. Sum of Left Leaves
// Easy

// 5189

// 293

// Add to List

// Share
// Given the root of a binary tree, return the sum of all left leaves.

// A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: 24
// Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
// Example 2:

// Input: root = [1]
// Output: 0
 

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// -1000 <= Node.val <= 1000

// Solution
#include<iostream>
using namespace std;

 struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){
        
    }
    TreeNode(int x){
       val=x; 
    }
    TreeNode(int x,TreeNode *left,TreeNode *right){
        val=x;
        left=NULL;
        right=NULL;
    }
};
class Solution {
public:
    int ans=0;
    int flag=0;
    void sumOf(TreeNode* root){
    
    if(!root->left && !root->right && flag){
        ans +=root->val;
    }
        if(root->left){
            flag=1;
            sumOf(root->left);
        }
        if(root->right){
            flag=0;
            sumOf(root->right);
        }
        
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        sumOf(root);
        return ans;
    }
};
int main(){
struct    TreeNode *n1=new TreeNode(1);
struct    TreeNode *n2=new TreeNode(2);
struct   TreeNode *n3=new TreeNode(3);
struct    TreeNode *n4=new TreeNode(4);
struct    TreeNode *n5=new TreeNode(5);
    n1->left=n2;
    n1->right=n3;
    n2->left=n4;
    n2->right=n5;
    Solution s=Solution();
    cout<<s.sumOfLeftLeaves(n1);
    return 0;
}