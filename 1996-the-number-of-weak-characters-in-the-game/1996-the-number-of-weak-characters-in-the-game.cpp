class Solution {
public:
    bool static cmp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),cmp);
        int cnt=0;
        int n=p.size();
       int temp=INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(p[i][1]<temp)cnt++;
            temp=max(temp,p[i][1]);
        }
        return cnt;
    }
};