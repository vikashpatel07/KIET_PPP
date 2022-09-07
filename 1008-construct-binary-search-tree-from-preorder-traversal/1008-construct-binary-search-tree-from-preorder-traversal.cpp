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
    TreeNode* solve(vector<int> &pr,int pstart,int pend,vector<int> &in,int instart,int inend,unordered_map<int,int>&mp){
        if(pstart>pend || instart>inend)return NULL;
        int len=mp[pr[pstart]];
        TreeNode* root=new TreeNode(pr[pstart]);
        int left=len-instart;
        root->left=solve(pr,pstart+1,pstart+left,in,instart,len-1,mp);
        root->right=solve(pr,pstart+left+1,pend,in,len+1,inend,mp);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pr) {
        vector<int>in;
        in=pr;
        sort(in.begin(),in.end());
        unordered_map<int,int>mp;
        for(int i=0;i<in.size();i++)
            mp[in[i]]=i;
        return solve(pr,0,pr.size()-1,in,0,in.size()-1,mp);
    }
};