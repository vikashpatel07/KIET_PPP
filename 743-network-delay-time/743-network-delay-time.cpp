class Solution {
public:
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<t.size();i++){
            adj[t[i][0]].push_back({t[i][1],t[i][2]});
        }
        vector<int>vis(n+1,0);
        using pi=pair<int,int>;
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        pq.push({0,k});
        int cost=0;
       int res=0;
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            vis[node]=1;
           res=max(res,wt);
            int cnt=0;
            for(int i=1;i<n+1;i++){
                if(vis[i])cnt++;
            }
            if(cnt==n)return res;
            for(auto x: adj[node]){
                if(!vis[x.first])
                pq.push({wt+x.second,x.first});
            }
            
            
        }
        return -1;
    }
};