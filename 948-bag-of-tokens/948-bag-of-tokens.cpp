class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int power) {
        sort(t.begin(),t.end());
        int n=t.size();
       int i=0,j=n-1;
        int res=0,score=0;
        while(i<=j){
            if(t[i]<=power){
                power-=t[i];
                score++;
                i++;
            }
            else if(score>0){
                power+=t[j];
                j--;
                score--;
            }
            else i++;
            res=max(res,score);
        }
        return res;
    }
};