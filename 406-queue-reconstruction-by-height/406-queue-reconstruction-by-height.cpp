class Solution {
public:
    bool static cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),cmp);
        int ind=0;
        int n=p.size();
        vector<vector<int>>res;
       for(int i=0;i<n;i++){
           int idx = p[i][1];
            res.insert(res.begin() + idx, p[i]);
       }
        return res;
    }
};