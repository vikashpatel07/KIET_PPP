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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* res=root;
        if(depth==1){
            TreeNode * node=new TreeNode (val);
            node->left=root;
            return node;
        }
        while(!q.empty()){
            int n=q.size();
            depth--;
            if(depth==1){
                for(int i=0;i<n;i++){
                    auto temp=q.front();
                    auto l=temp->left,r=temp->right;
                    q.pop();
                    TreeNode * z=new TreeNode(val);
                    TreeNode* x=new TreeNode(val);
                    temp->left=z;
                    z->left=l;
                    temp->right=x;
                    x->right=r;
                    // cout<<temp->val<<" ";
                    // cout<<temp->left->val<<"->"<<z->left->val<<" ";
                    // cout<<temp->right->val<<"->"<<x->right->val<<"\n";
                }
                return res;
            }
            
            for(int i=0;i<n;i++){
                auto t=q.front();
                q.pop();
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
                // cout<<t->val<<" ";
            }
            // cout<<"\n";
        }
        return res;
        
    }
};