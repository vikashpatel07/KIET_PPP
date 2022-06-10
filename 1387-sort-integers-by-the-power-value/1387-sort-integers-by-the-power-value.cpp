class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>v;
        for(int i=lo;i<=hi;i++){
            int cnt=0;
            int num=i;
            while(num!=1){
                if(num&1)num=num*3+1;
                else num/=2;
                cnt++;
            }
            v.push_back({cnt,i});
        }
        sort(v.begin(),v.end());
        return v[k-1].second;
    }
};