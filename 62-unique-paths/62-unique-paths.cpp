class Solution {
public:
    int solve(int m,int n,vector<vector<int>>& dp){
        if(m==0 && n==0)return 1;
        if(m<0 || n<0)return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        int left=solve(m,n-1,dp);
        int up=solve(m-1,n,dp);
        return dp[m][n]=left+up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1 && j==1){
                    dp[i][j]=1;
                    continue;
            }
                int left=dp[i][j-1];
                int up=dp[i-1][j];
                dp[i][j]=left+up;
            }
        }
            return dp[m][n];
    }
};