class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        using pi=pair<int,pair<int,int>>;
        int ans=0;
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
        while(!pq.empty()){
            int wt=pq.top().first;
            int u=pq.top().second.first;
            int v=pq.top().second.second;
            pq.pop();
            ans=max(ans,wt);
            if(u==n-1 && v==m-1)return ans;
            
            if(h[u][v]==-1)continue;
            int ht=h[u][v];
            h[u][v]=-1;
            for(auto x: dir){
                int dx=u+x[0];
                int dy=v+x[1];
                if(dx>=0 && dx<n && dy>=0 && dy<m)
                    pq.push({abs(h[dx][dy]-ht),{dx,dy}});
            }
        }
        return 0;
        
    }
};