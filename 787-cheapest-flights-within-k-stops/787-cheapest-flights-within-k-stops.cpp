class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<f.size();i++){
            adj[f[i][0]].push_back({f[i][1],f[i][2]});
        }
       vector<long>dis(n,INT_MAX);
        dis[src]=0;
        for(int i=0;i<=k;i++){
            // for(int node=0;node<n;node++){
            //     for(auto x: adj[node]){
            //         if(dis[node]+x.second<dis[x.first])
            //             dis[x.first]=dis[node]+x.second;
            //     }
            // }
            
            vector<long>d(dis);
            
            for(auto x: f){
                d[x[1]]=min(d[x[1]],dis[x[0]]+x[2]);
            }
            dis=d;
        }
        
        return dis[dst]==INT_MAX?-1:dis[dst];
    }
};