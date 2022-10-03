class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int res=0;
        int n=colors.size();
        for(int i=0;i<n-1;i++){
            int j=i+1;
            int sum=time[i],maxi=time[i];
            while(j<n  && colors[j]==colors[j-1]){
                sum+=time[j];
                maxi=max(maxi,time[j]);
                j++;
            }
            res+=sum-maxi;
            i=j-1;
        }
        return res;
    }
};