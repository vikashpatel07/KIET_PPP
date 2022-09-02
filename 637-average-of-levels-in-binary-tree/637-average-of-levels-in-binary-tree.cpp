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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        queue<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            int sz = st.size();
            double sum = 0 , cnt=0;
            for(int i=0;i<sz;i++){
                TreeNode* tmp = st.front();
                st.pop();
                sum+=tmp->val;
                cnt++;
                if(tmp->left) st.push(tmp->left);
                if(tmp->right) st.push(tmp->right);
            }
            res.push_back(sum/cnt);
        }
        return res;
    }
};