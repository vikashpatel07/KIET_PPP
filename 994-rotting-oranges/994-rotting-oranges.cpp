class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        using pi=pair<int,int>;
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        queue<pi>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)vis[i][j]=true;
                else if(grid[i][j]==2){
                    vis[i][j]=true;
                    q.push({i,j});
                }
            }
        }
        int res=0;
        while(!q.empty()){
              int cnt=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++)
                    if(vis[i][j]==true)cnt++;
            }
            cout<<cnt<<" "<<res<<"\n";
            if(cnt==n*m)return res;
            res++;
            int nn=q.size();
            for(int a=0;a<nn;a++){
            auto temp=q.front();
            int x=temp.first;
            int y=temp.second;
            q.pop();
            for(auto z : dir){
                int xx=x+z[0];
                int yy=y+z[1];
                if(xx>=0 && xx<n && yy>=0 && yy<m && vis[xx][yy]==false){
                    vis[xx][yy]=true;
                    if(grid[xx][yy]!=0)
                    q.push({xx,yy});
                }
            }
            }
        }
        int cnt=0;
           for(int i=0;i<n;i++){
                for(int j=0;j<m;j++)
                    if(vis[i][j]==true)cnt++;
            }
        if(cnt==n*m)return res;
        return -1;
    }
};