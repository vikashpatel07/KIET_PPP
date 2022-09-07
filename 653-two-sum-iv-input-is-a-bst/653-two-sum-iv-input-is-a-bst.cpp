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
class bst{
    stack<TreeNode*>st;
    bool reverse;
    public:
    bst(TreeNode* root,bool isreverse){
        reverse=isreverse;
        push(root);
    }
    void push(TreeNode* root){
        while(root){
            st.push(root);
           if(reverse)root=root->right;
           else root=root->left;
        }
    }
    int next(){
        auto temp=st.top();
        st.pop();
        if(!reverse)
        push(temp->right);
        else push(temp->left);
        return temp->val;
    }
    
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        bst l(root,false);
        bst r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k)return true;
            else if( i+j<k)i=l.next();
            else j=r.next();
                
        }
        return false;
    }
};