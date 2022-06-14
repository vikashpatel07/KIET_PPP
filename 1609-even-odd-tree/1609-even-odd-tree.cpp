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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int cnt=0,f=0;
        while(!q.empty()){
            int n=q.size();
            int mini=INT_MIN,maxi=INT_MAX;
                for(int i=0;i<n;i++){
                auto x=q.front();
                q.pop();
                    if(f==0 && x->val%2){
                        if(x->val<=mini)return false;
                        mini=x->val;
                    }
                    else if(f==0 && x->val%2==0)return false;
                    else if(f==1 && x->val%2==0){
                        if(x->val>=maxi)return false;
                        maxi=x->val;
                    }
                    else if(f==1 && x->val%2) return false;
                    
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
            f=!f;
        }
        return true;
    }
};