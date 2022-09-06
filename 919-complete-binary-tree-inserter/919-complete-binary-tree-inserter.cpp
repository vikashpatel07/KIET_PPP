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
        int k=0,cnt=0;
        vector<TreeNode*>temp;
        while(!q.empty()){
            int n=q.size();
            
            int z=(int)(pow(2,k));
            
            if(z==n){
                k++;
                temp.clear();
                for(int i=0;i<n;i++){
                    auto x=q.front();
                    temp.push_back(x);
                    q.pop();
                    if(x->left)q.push(x->left);
                    if(x->right)q.push(x->right);
                }
            }
            else{
                for(int j=0;j<temp.size();j++){
                    if(!temp[j]->left){
                        temp[j]->left=new TreeNode(val);
                        return temp[j]->val;
                    }
                    else if(!temp[j]->right){
                        temp[j]->right=new TreeNode(val);
                    return temp[j]->val;
                }
                }
            }
            
            
            if(q.size()==0){
                 temp[0]->left=new TreeNode(val);
                return temp[0]->val;
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