class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int min) {
        int sum=0,temp=0,maxi=0;
        for(int i=0;i<c.size();i++){
            if(g[i]==0)sum+=c[i];
            else if(g[i]==1)temp+=c[i];
            if(i>=min && g[i-min]==1)temp-=c[i-min];
            maxi=max(maxi,temp);
        }
        return sum+maxi;
    }
};