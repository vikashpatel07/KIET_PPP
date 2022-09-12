#define ll long long
#define pll pair<ll, ll>
class Solution {
public:
    
    int countPaths(int n, vector<vector<int>>& r) {
        vector<pll> adj[n];
        for(int i=0;i<r.size();i++){
            adj[r[i][0]].push_back({r[i][1],r[i][2]});
            adj[r[i][1]].push_back({r[i][0],r[i][2]});
        }
        priority_queue<pll,vector<pll>,greater<pll>>pq;
        pq.push({0,0});
        vector<long long>dis(n,LONG_MAX),way(n);
        dis[0]=0;
        way[0]=1;
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
           
            pq.pop();
             if(wt>dis[node])continue;
            for(auto x: adj[node]){
                int v=x.first;
                int di=x.second;
                if(dis[node]+di<dis[v]){
                    dis[v]=dis[node]+di;
                    way[v]=way[node];
                    pq.push({dis[v],v});
                }
                else if(dis[v]==dis[node]+di){
                    way[v]=(way[v]+way[node])%(int)(1e9+7);
                }
            }
        }
        return way[n-1];
    }
};