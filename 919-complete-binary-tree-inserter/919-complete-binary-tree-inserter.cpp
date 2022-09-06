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
    vector<TreeNode*>temp;
    CBTInserter(TreeNode* root) {
        temp.push_back(root);
        for(int i=0;i<temp.size();i++){
            if(temp[i]->left)temp.push_back(temp[i]->left);
            if(temp[i]->right)temp.push_back(temp[i]->right);
        }
    }
    
    int insert(int val) {
        int n=temp.size();
        TreeNode* node=new TreeNode(val);
        temp.push_back(node);
        if(n%2)temp[(n-1)/2]->left=node;
        else temp[(n-1)/2]->right=node;
        return temp[(n-1)/2]->val;
        
    }
    
    TreeNode* get_root() {
        return temp[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */