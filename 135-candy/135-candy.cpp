class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum=0;
        vector<int> ans(ratings.size(),1);
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1])
                ans[i]=ans[i-1]+1;
        }
        for(int i=ratings.size()-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
                ans[i]=max(ans[i],ans[i+1]+1);
        }
        for(int i=0;i<ans.size();i++)
            sum+=ans[i];
        return sum;   
    }
};