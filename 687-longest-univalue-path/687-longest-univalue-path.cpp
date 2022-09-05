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
  
    int solve(TreeNode* root,int &res){
        if(!root)return 0;
        int left=solve(root->left,res);
        int right=solve(root->right,res);
        if(!root->left || root->val!=root->left->val)left=0;
        if(!root->right || root->val!=root->right->val)right=0;
        res=max(res,left+right);
        return max(left,right)+1;
        
    }
    int longestUnivaluePath(TreeNode* root) {
        int res=0;
        solve(root,res);
        return res;
    }
};