class Solution {
public:
    vector<int>parent;
    int findpar(int i){
        if(parent[i]==i)return i;
        return parent[i]=findpar(parent[i]);
    }
    
    void unionnode(int a,int b){
        int p1=findpar(a);
        int p2=findpar(b);
        if(p1!=p2)parent[p1]=p2;
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        
        for(auto e: equations){
            if(e[1]=='=')unionnode(e[0]-'a',e[3]-'a');
        }
        for(auto e: equations){
            if(e[1]=='!' && (findpar(e[0]-'a')==findpar(e[3]-'a')))
                return false;
        }
        return true;
    }
};