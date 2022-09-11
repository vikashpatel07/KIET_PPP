class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        vector<int>ind(n,0);
        for(int i=0;i<n;i++){
            for(auto x: graph[i]){
                adj[x].push_back(i);
                ind[i]++;
            }
        }
        queue<int>q;
        vector<int>res;
        
        for(int i=0;i<n;i++){
            if(ind[i]==0)q.push(i);
        }
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            res.push_back(temp);
            for(auto x: adj[temp]){
                ind[x]--;
                if(ind[x]==0)q.push(x);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};