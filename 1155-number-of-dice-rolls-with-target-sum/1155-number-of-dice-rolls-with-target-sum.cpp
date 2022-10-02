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
        // int a=solve(n,k,target);
        
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp);
    }
};