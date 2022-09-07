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
    TreeNode* solve(vector<int>&pr,int &ind,int bound){
        if(ind==pr.size() || pr[ind]>bound)return NULL;
        TreeNode* root=new TreeNode(pr[ind++]);
        root->left=solve(pr,ind,root->val);
        root->right=solve(pr,ind,bound);
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int i=0;
        return solve(pre,i,INT_MAX);
        
    }
};