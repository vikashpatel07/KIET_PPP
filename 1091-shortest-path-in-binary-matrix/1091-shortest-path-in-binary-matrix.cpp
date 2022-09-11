class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        vector<vector<int>>d;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i==0 && j==0)continue;
                d.push_back({i,j});
            }
        }
        
        if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;
        q.push({0,0});
        vis[0][0]=true;
        int res=0;
        while(!q.empty()){
            int size=q.size();
            res++;
            for(int i=0;i<size;i++){
                 int x=q.front().first;
                 int y=q.front().second;
                q.pop();
                 if(x==n-1 && y==m-1)return res;
                
                for(int j=0;j<d.size();j++){
                    int xd=x+d[j][0];
                    int yd=y+d[j][1];
                    
                    if(xd>=0 && xd<n && yd>=0 && yd<m && grid[xd][yd]==0  && vis[xd][yd]==false){
                        vis[xd][yd]=true;
                        q.push({xd,yd});
                    }
                }
            }
            
        }
        return -1;
    }
};