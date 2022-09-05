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
    int res=INT_MAX;
    int solve(TreeNode* root,TreeNode* a){
        if(!root)return 0;
        int left=solve(root->left,a);
        int right=solve(root->right,a);
        if(root==a){
           if(left==0)res=right+1;
            else if(right==0)res=left+1;
            else res=min(left,right)+1;
        }
        if(left==0)return right+1;
        if(right==0)return left+1;
        return min(left,right)+1;
    }
    int minDepth(TreeNode* root) {
        int x=solve(root,root);
        return x;
    }
};