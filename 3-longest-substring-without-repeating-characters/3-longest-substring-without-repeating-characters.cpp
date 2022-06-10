class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int start=0,end=s.size()-1,low=0;
        int res=0;
        while(start<=end){
           if(mp.find(s[start])!=mp.end()){
              low=max(low,mp[s[start]]+1);
           }
           mp[s[start]]=start;
            res=max(res,start-low+1);
            start++;
        }
        return res;
    }
};