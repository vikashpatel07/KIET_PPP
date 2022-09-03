/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markpar(TreeNode* root,unordered_map<TreeNode* ,TreeNode*> &parent){
        queue<TreeNode*>q;
        if(root==NULL)return;
        q.push(root);
        while(q.empty()!=1){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto x=q.front();
                q.pop();
                if(x->left){
                    parent[x->left]=x;
                    q.push(x->left);
            }
                if(x->right){
                    parent[x->right]=x;
                    q.push(x->right);
                }
        }
    }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* ,TreeNode*>parent;
        markpar(root,parent);
        vector<int>res;
        unordered_map<TreeNode*,bool>vis;
        int cnt=0;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        while(!q.empty()){
            
            if(cnt==k)break;
            cnt++;
            int n=q.size();
            for(int i=0;i<n;i++){
            auto x=q.front();
            q.pop();
           
            if(x->left  && vis[x->left]==false){
                q.push(x->left);
                vis[x->left]=true;
            }
            if(x->right && vis[x->right]==false){
                q.push(x->right);
                vis[x->right]=true;
            }
            if(parent[x] && vis[parent[x]]==false){
                q.push(parent[x]);
                vis[parent[x]]=true;
            }
            }
        }
        while(q.empty()!=1){
            auto x= q.front();
            q.pop();
            res.push_back(x->val);
        }
        return res;
    }
};