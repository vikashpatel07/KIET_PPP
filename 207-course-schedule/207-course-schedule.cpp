class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
       vector<int>adj[n];
        for(int i=0;i<p.size();i++){
            // adj[p[i][0]].push_back(p[i][1]);
            adj[p[i][1]].push_back(p[i][0]);
        }
        vector<int>ind(n,0);
        for(int i=0;i<n;i++){
            for(auto x: adj[i]){
                ind[x]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(ind[i]==0)q.push(i);
        }
        vector<int>vis(n,0);
        vector<int>res;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            res.push_back(x);
            vis[x]=1;
            for(auto it: adj[x]){
                if(!vis[it])ind[it]--;
                if(ind[it]==0)q.push(it);
            }
            
        }
        return res.size()==n;
    }
};