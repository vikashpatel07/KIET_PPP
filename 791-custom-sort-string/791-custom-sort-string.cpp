class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        for(auto x:s)mp[x]++;
        string res;
        for(int i=0;i<order.size();i++){
            if(mp.find(order[i])!=mp.end()){
                int n=mp[order[i]];
                while(n--){
                    res+=order[i];
                }
                mp[order[i]]=-1;
            }
        }
        for(auto x: mp){
            if(x.second>0){
                int n=x.second;
                while(n--)res+=x.first;
            }
        }
        return res;
    }
};