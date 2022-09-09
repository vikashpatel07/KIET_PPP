class Solution {
public:
    bool solve(int node,vector<int> &col,vector<int> adj[]){
        queue<int>q;
        col[node]=1;
        q.push(node);
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            for(auto y: adj[x]){
                if(col[y]==-1){
                    q.push(y);
                    col[y]=1-col[x];
                }
                else if(col[x]==col[y])return false;
            }
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
                if(solve(i,col,adj)==false)return false;
            }
        }
        return true;
    }
};