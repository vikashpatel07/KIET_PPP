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
class CBTInserter {
public:
    TreeNode* node;
    CBTInserter(TreeNode* root) {
        node=root;
    }
    
    int insert(int val) {
        queue<TreeNode*>q;
        
        q.push(node);
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            if(x->left)q.push(x->left);
            else{
                x->left=new TreeNode (val);
                return x->val;
            }
            if(x->right)q.push(x->right);
            else{
                x->right=new TreeNode (val);
                return x->val;
            }
        }
        return 0;
    }
    
    TreeNode* get_root() {
        return node;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */