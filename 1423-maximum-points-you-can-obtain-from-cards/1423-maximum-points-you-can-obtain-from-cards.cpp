class Solution {
public:
    int maxScore(vector<int>& c, int k) {
      int sum=0;
        for(int i=0;i<k;i++)sum+=c[i];
        int res=sum;
        int start=k-1,end=c.size()-1;
        while(start>=0){
            sum-=c[start--];
            sum+=c[end--];
            res=max(res,sum);
        }
        return res;
    }
};