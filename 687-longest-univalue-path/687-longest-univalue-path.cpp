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
    int res=0;
    int solve(TreeNode* root,TreeNode* temp){
        if(!root)return 0;
        int left=solve(root->left,root);
        int right=solve(root->right,root);
        res=max(left+right,res);
        if(temp && temp->val==root->val)return max(left,right)+1;
        else return 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        int x=solve(root,NULL);
        return res;
    }
};