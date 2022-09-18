class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
        int n=h.size(),m=h[0].size();
        vector<vector<int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        using pi=pair<int,pair<int,int>>;
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        for(int i=0;i<m;i++){
            pq.push({h[0][i],{0,i}});
            pq.push({h[n-1][i],{n-1,i}});
            vis[0][i]=true;
            vis[n-1][i]=true;
        }
         for(int i=0;i<n;i++){
            pq.push({h[i][0],{i,0}});
            pq.push({h[i][m-1],{i,m-1}});
            vis[i][0]=true;
            vis[i][m-1]=true;
        }
        int res=0;
        while(!pq.empty()){
            auto z=pq.top();
            int height=z.first;
            int i=z.second.first;
            int j=z.second.second;
            pq.pop();
            for(auto x: dir){
                int row=i+x[0];
                int col=j+x[1];
                if(row>=0 && row<n && col>=0 && col<m && !vis[row][col]){
                    vis[row][col]=true;
                   
                    if(h[row][col]<height){
                         cout<<height-h[row][col]<<" ";
                        res+=height-h[row][col];
                    }
                    
                    pq.push({max(height,h[row][col]),{row,col}});
                }
            }
        }
        return res;
        
    }
};