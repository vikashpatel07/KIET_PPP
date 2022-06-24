class Solution {
    public int maxProfit(int[] prices) {
        int profit=0;
        int maxi=prices[0];
        for(int i=1;i<prices.length;i++){
            if(prices[i]-maxi>profit)profit=prices[i]-maxi;
            else if(prices[i]<maxi)maxi=prices[i];
        }
        return profit;
    }
}