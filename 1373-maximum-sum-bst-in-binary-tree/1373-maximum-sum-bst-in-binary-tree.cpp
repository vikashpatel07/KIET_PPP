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

class node{
    public:
    int mini,maxi,sum;
    node(int mini,int maxi,int sum){
        this->mini=mini;
        this->maxi=maxi;
        this->sum=sum;
    }
};

class Solution {
public:
    int summ=0;
    
    node largest(TreeNode* root){
    if(!root)return node(INT_MAX,INT_MIN,0);
    
    auto left=largest(root->left);
    auto right=largest(root->right);
    if(left.maxi<root->val && right.mini>root->val)
    {
        summ=max(summ,left.sum+right.sum+root->val);
        return node(min(left.mini,root->val),max(right.maxi,root->val),left.sum+right.sum+root->val);
    }
    else
        return node(INT_MIN,INT_MAX,max(left.sum,right.sum));
}
    
    int maxSumBST(TreeNode* root) {
        auto temp=largest(root);
        return summ;
    }
};