// 623. Add One Row to Tree
// Medium

// 3456

// 259

// Add to List

// Share
// Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

// Note that the root node is at depth 1.

// The adding rule is:

// Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
// cur's original left subtree should be the left subtree of the new left subtree root.
// cur's original right subtree should be the right subtree of the new right subtree root.
// If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.
 

// Example 1:


// Input: root = [4,2,6,3,1,5], val = 1, depth = 2
// Output: [4,1,1,2,null,null,6,3,1,5]
// Example 2:


// Input: root = [4,2,null,3,1], val = 1, depth = 3
// Output: [4,2,null,1,1,3,null,null,1]
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// The depth of the tree is in the range [1, 104].
// -100 <= Node.val <= 100
// -105 <= val <= 105
// 1 <= depth <= the depth of tree + 1
// Accepted
// 251,924
// Submissions
// 396,002


#include<iostream>
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
  void solve(TreeNode* root,int val,int depth,int level){
        if(!root|| level>depth){
            return ;
        }
        if(level==depth-1){
            TreeNode* temp1=new TreeNode(val,root->left,NULL);
            TreeNode* temp2=new TreeNode(val,NULL,root->right);
            root->left=temp1;
            root->right=temp2;
        }
        solve(root->left,val,depth,level+1);
        solve(root->right,val,depth,level+1);
        
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
      TreeNode * r;
        if(depth==1){
            TreeNode* temp=new TreeNode(val,root,NULL);
            return temp;
        }
        r=root;
        solve(root,val,depth,1);
        return r;
        
    }
    void printTree(TreeNode* root){
        if(root){
            printTree(root->left);
            cout<<root->val<<" ";
            printTree(root->right);
        }
    }
int main(){
     struct TreeNode *n1=new TreeNode(4);
    struct TreeNode *n2=new TreeNode(2);
    struct TreeNode *n3=new TreeNode(6);
    struct TreeNode *n4=new TreeNode(3);
    struct TreeNode *n5=new TreeNode(1);
    struct TreeNode *n6=new TreeNode(5);
  
    n1->left=n2;
    n1->right=n3;
    n2->left=n4;
    n2->right=n5;
    n3->left=n6;
      printTree(n1);
    cout<<endl;
    TreeNode* ans=addOneRow(n1,1,2);
    printTree(ans);
    
    return 0;
}