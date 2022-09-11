class Solution {
public:
    vector<vector<int>>dir={{-1,0},{0,-1},{0,1},{1,0}};
    void dfs(int i,int j, vector<vector<int>> &vis,vector<vector<int>> &h,int mid){
        int n=h.size();
        int m=h[0].size();
        if(!vis[i][j]){
            vis[i][j]=1;
           for(int d=0;d<4;d++){
               int x=i+dir[d][0];
               int y=j+dir[d][1];
               if(x>=0 && x<n && y>=0 && y<m && abs(h[i][j]-h[x][y])<=mid)
                   dfs(x,y,vis,h,mid);
           }
        }
    }
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size(),m=h[0].size();
        int start=0,end=1e9,ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            vector<vector<int>> vis(n,vector<int>(m,0));
            dfs(0,0,vis,h,mid);
            if(vis[n-1][m-1]){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};