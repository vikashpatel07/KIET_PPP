class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> adj[n];
        for(int i=0;i<p.size();i++){
            adj[p[i][1]].push_back(p[i][0]);
        }
        vector<int>ind(n,0);
        for(int i=0;i<n;i++){
            for(int x: adj[i]){
                ind[x]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(ind[i]==0)q.push(i);
        }
        vector<int>res;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            res.push_back(temp);
            for(auto x: adj[temp]){
                ind[x]--;
                if(ind[x]==0)
                    q.push(x);
            }
        }
        if(res.size()<n)return {};
        return res;
    }
};