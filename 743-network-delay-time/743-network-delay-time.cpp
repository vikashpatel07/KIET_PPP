class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using pi=pair<int,int>;
        vector<pi> adj[n+1];
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        for(int i=0;i<n-1;i++){
            for(auto node: times){
                int u=node[0];
                int v=node[1];
                int wt=node[2];
                if(dis[u]!=INT_MAX && dis[u]+wt<dis[v])
                    dis[v]=dis[u]+wt;
            }
        }
        int res=0;
        for(int i=1;i<=n;i++){
            if(dis[i]==INT_MAX)return -1;
            res=max(res,dis[i]);
        }
        return res;
    }
};