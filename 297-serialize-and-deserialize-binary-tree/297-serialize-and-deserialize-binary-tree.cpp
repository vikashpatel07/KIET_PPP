/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res="";
        queue<TreeNode*>q;
        if(!root)return res;
        q.push(root);
        while(!q.empty()){
            auto x=q.front();
            q.pop();
           
            
            if(x==NULL)res+="#,";
            if(x!=NULL){
            res+=to_string(x->val)+",";
            q.push(x->left);
            q.push(x->right);
            }
            
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        stringstream ss(data);
        string str;
        getline(ss,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            getline(ss,str,',');
            if(str=="#"){
                node->left=NULL;
            }
            else{
                TreeNode* left=new TreeNode(stoi(str));
                node->left=left;
                q.push(left);
            }
            getline(ss,str,',');
             if(str=="#"){
                node->right=NULL;
            }
            else{
                TreeNode* right=new TreeNode(stoi(str));
                node->right=right;
                q.push(right);
            }
            
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));