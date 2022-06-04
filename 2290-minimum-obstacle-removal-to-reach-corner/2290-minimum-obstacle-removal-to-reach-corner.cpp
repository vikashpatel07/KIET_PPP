class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        using ti=tuple<int,int,int>;
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<ti,vector<ti>,greater<ti>>pq;
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<int>x={1,-1,0,0};
        vector<int>y={0,0,1,-1};
        pq.push({0,0,0});
        while(pq.size()){
            auto [a,b,c]=pq.top();
            pq.pop();
            dp[b][c]=a;
            for(int i=0;i<4;i++){
                int r=b+x[i];
                int cc=c+y[i];
                if(r<0 || r>=n || cc<0 || cc>=m )continue;
                if(dp[r][cc]>grid[r][cc]+a){
                dp[r][cc]=min(dp[r][cc],grid[r][cc]+a);
                pq.push({a+grid[r][cc],r,cc});
                }
            }
        }
        // for(auto x: dp){
        //     for(auto y: x){
        //         cout<<y<<" ";
        //     }
        //     cout<<"\n";
        // }
        return dp[n-1][m-1];
    }
};