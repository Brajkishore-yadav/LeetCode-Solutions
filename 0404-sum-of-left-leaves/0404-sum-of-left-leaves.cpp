/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   void sum(TreeNode* root,int &s,int t){
       if(root==NULL){
        return;
       }
       if(root->left ==NULL && root->right==NULL && t==1){
        s = s + root->val;
       }
       sum(root->left,s,1);
       sum(root->right,s,0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int s=0,t;
   sum(root,s,t);
    return s;
    }
};