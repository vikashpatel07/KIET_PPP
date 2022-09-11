class Solution {
public:
    bool dfs(int node,vector<bool>  &vis,vector<bool> & safe,vector<int> adj[],vector<bool> &cur)
    {
        vis[node]=true;
       cur[node]=true;
       
       for(auto x: adj[node])
       {
           if(!vis[x])
           {
               if(dfs(x,vis,safe,adj,cur)==false)
                   return safe[node]=false;
           }
           else if(cur[x]==true)
               return safe[node]=false;
       }
        cur[node]=false;
        // return safe[node];
        return true;
    }
      
        
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
         unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
           
            for(auto x: graph[i])
            adj[i].push_back(x);
        }
        vector<int>res;
        vector<bool>vis(n,false);
        vector<bool>cur(n,false);
        vector<bool>safe(n,true);
        for(int i=0;i<n;i++)
        {
          if (!vis[i])
                dfs(i,vis,safe,adj,cur);
           
        }
        for(int i=0;i<n;i++)
        {
            if(safe[i])
                res.push_back(i);
        }
        
        return res;
        
    }
};