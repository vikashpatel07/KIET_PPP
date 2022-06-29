struct Node{
    Node *link[2];
    void put(int num){
        link[num]=new Node();
    }
    Node* get(int num){
        return link[num];
    }
    bool containsKey(int num){
        return link[num];
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
                node=node->get(1-bit);
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>>temp;
        int i=0;
        for(auto x:queries){
            temp.push_back({x[1],{x[0],i++}});
        }
        Trie trie;
        sort(temp.begin(),temp.end());
        int n=nums.size();
        int sz=queries.size();
        vector<int>res(sz,0);
        int ind=0;
        for(auto x: temp){
           int bound=x.first;
            int num=x.second.first;
            int order=x.second.second;
            while(ind<n && nums[ind]<=bound){
                trie.insert(nums[ind++]);
            }
            if(ind==0)res[order]=-1;
            else
            res[order]=trie.getmax(num);
        }
        return res;
    }
};