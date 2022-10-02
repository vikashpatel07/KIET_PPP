class Solution {
public:
   const int mod=1e9+7;
    int solve(int n,int k,int tar,vector<vector<int>>& dp){
        if(tar<0)return 0;
        if(n==0){
            if(tar==0)
                return 1;
            return 0;
        }
        if(dp[n][tar]!=-1)return dp[n][tar];
        int maxi=0;
        for(int i=1;i<=k;i++){
            if(i<=tar)
           maxi=(maxi%mod+solve(n-1,k,tar-i,dp))%mod;
        }
        return dp[n][tar]=maxi;

    }
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                int maxi=0;
                for(int m=1;m<=k;m++){
                    if(j-m>=0)
                    maxi=(maxi%mod+dp[i-1][j-m])%mod;
                }
                dp[i][j]=maxi;
            }
        }
        return dp[n][target];
    }
};