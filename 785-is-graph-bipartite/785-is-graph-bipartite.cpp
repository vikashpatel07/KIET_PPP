class Solution {
public:
    bool solve(int node,vector<int> &col,vector<int> adj[]){
        
        for(auto x: adj[node]){
            if(col[x]==-1){
               col[x]=1-col[node];
                if(solve(x,col,adj)==false)return false;
            }
            else if(col[x]==col[node])return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(auto x:graph[i]){
                adj[i].push_back(x);
            }
        }
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                col[i]=1;
                if(solve(i,col,adj)==false)return false;
            }
        }
        return true;
    }
};