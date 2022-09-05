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
    int solve(TreeNode* root){
        if(!root)return 0;
        int left=solve(root->left);
        int right=solve(root->right);
        res+=abs(left-right);
        return left+right+root->val;
    }
    int findTilt(TreeNode* root) {
       int x=solve(root);
        return res;
    }
};