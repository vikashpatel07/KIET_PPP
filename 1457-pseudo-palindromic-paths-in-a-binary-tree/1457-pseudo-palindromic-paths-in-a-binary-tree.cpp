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
    unordered_map<int,int>mp;
    int res=0;
    void solve(TreeNode* root){
        mp[root->val]++;
        if(root->left==NULL && root->right==NULL){
          int cnt=0;
           for(auto x: mp){
               if(x.second%2)cnt++;
           }
            if(cnt<=1)res++;
           
           
        }
        
        if(root->left)
        solve(root->left);
        if(root->right)
        solve(root->right);
       mp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
       
        solve(root);
        return res;
    }
};