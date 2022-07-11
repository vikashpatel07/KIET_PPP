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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>>temp;
         vector<int>res;
        if(!root)return res;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()>0){
            int n=q.size();
            vector<int>data;
            for(int i=0;i<n;i++){
                auto front=q.front();
                data.push_back(front->val);
                q.pop();
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
            }
            temp.push_back(data);
        }
       
        for(int i=0;i<temp.size();i++){
            res.push_back(temp[i].back());
        }
        return res;
    }
};