class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_map<char,int>mp;
        int low=0,res=0;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                low=max(mp[s[i]]+1,low);
                mp[s[i]]=i;
            }
            else{
                mp[s[i]]=i;
            }
            cout<<low<<" ";
            res=max(res,i-low+1);
            // cout<<res<<" ";
                
        }
        return res;
        
    }
};