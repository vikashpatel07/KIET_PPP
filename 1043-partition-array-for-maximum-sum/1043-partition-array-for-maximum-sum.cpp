class Solution {
public:
    int solve(int i,int n,int k,vector<int> &a,vector<int> &dp){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int l=0,maxi=INT_MIN,sum=0,ans=0;
        for(int j=i;j<min(n,i+k);j++){
             l++;
             maxi=max(maxi,a[j]);
            sum=l*maxi+solve(j+1,n,k,a,dp);
            ans=max(ans,sum);
           
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return solve(0,n,k,arr,dp);
    }
};