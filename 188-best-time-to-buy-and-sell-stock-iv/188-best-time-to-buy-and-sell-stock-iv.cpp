class Solution {
public:
    
       int solve(int ind,int buy,vector<int> &prices,int count,vector<vector<vector<int>>> & dp)
    {
         if(count<=0)return 0;
        if(ind==prices.size())
            return 0;
        if(dp[ind][buy][count]!=-1)return dp[ind][buy][count];
        int profit=0;
        if(buy)
        {
            profit=max(-prices[ind]+solve(ind+1,0,prices,count,dp),solve(ind+1,1,prices,count,dp));
        }
        else
            profit=max(prices[ind]+solve(ind+1,1,prices,count-1,dp),
                       solve(ind+1,0,prices,count,dp));
        return dp[ind][buy][count]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
         int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,1,prices,k,dp);
    }
};