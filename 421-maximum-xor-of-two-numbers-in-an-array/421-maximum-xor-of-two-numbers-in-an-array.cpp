struct Node{
    Node* link[2];
    
    bool containsKey(int num){
        return link[num];
    }
    Node* get(int num){
        return link[num];
    }
    void put(int num){
        link[num]=new Node();
    }
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit);
            }
            node=node->get(bit);
        }
    }
    int getmax(int num){
        Node* node=root;
        int maxnum=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containsKey(1-bit)){
                maxnum=maxnum|(1<<i);
                node=node->get(!bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxnum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto x: nums){
            trie.insert(x);
        }
        int res=0;
        for(auto x: nums){
            int temp=trie.getmax(x);
            res=max(res,temp);
        }

        return res;
    }
};