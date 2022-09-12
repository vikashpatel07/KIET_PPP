
class Solution {
public:
    using pi=pair<int,int>;
   vector<pi> adj[105];
vector<pi> ans;

bool static cmp(pi p1 ,pi p2)
{
    if(p1.first != p2.first)
        return p1.first < p2.first;
    
    return p1.second > p2.second;
}

void dijkstra(int src, int n, int distanceThreshold)
{
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    vector<int> distance(n, INT_MAX);
    
    distance[src] = 0;
    pq.push({0,src});
    
    while(! pq.empty())
    {
        int prev = pq.top().second;
        int prevDist = pq.top().first;
        pq.pop();
        
        for(auto it : adj[prev])
        {
            int next = it.first;
            int nextDist = it.second;
            if(distance[next] > distance[prev] + nextDist)
            {
                distance[next] = distance[prev] + nextDist;
                pq.push({distance[next], next});
            }
        }
    }
    
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(i != src && distance[i] <= distanceThreshold)
            cnt++;
    }
    
    ans.push_back({cnt,src});
    
}


int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];   
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    for(int i=0;i<n;i++)
    {
        dijkstra(i, n, distanceThreshold);
    }
    
    sort(ans.begin(),ans.end(),cmp);
    
    return ans[0].second;
    
}
};