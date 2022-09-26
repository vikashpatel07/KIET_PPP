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
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int len=0,res=0,maxi=0,sum=0;
            for(int j=i;j<min(n,i+k);j++){
                len++;
                maxi=max(maxi,arr[j]);
                sum=len*maxi+dp[j+1];
                res=max(res,sum);
            }
            dp[i]=res;
        }
        return dp[0];
        return solve(0,n,k,arr,dp);
    }
};