/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;
        if(root==NULL)return res;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>temp;
            int n=q.size();
            for(int i=0;i<n;i++){
                auto x=q.front();
                q.pop();
                temp.push_back(x->val);
                for(auto y: x->children){
                    q.push(y);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};