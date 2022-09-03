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

    int amountOfTime(TreeNode* root, int start) {
          unordered_map<TreeNode* ,TreeNode*>parent;
        markpar(root,parent);
        vector<int>res;
        unordered_map<TreeNode*,bool>vis;
        int cnt=0;
        queue<TreeNode*>qq;
        qq.push(root);
        TreeNode* temp;
        while(1){
            int n=qq.size();
            int f=0;
            for(int i=0;i<n;i++){
                auto x=qq.front();
                qq.pop();
                if(x->val==start){
                    temp=x;
                    f=1;
                    
                    break;
                }
                if(x->left)qq.push(x->left);
                if(x->right)qq.push(x->right);
            }
            if(f==1)break;
        }
        vis[temp]=true;
        queue<TreeNode*>q;
        q.push(temp);
        cnt=-1;
        while(!q.empty()){
             cnt++;
            if(q.size()==0)break;
           
            int n=q.size();
            for(int i=0;i<n;i++){
            auto x=q.front();
            q.pop();
                cout<<x->val<<" ";
           
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
            cout<<"-----"<<cnt<<"\n";
        }
        
        return cnt;
    }
};