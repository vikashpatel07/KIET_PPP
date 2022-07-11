class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0,low=0;
        unordered_set<char>vis;
        for(int i=0;i<s.size();i++){
            if(vis.find(s[i])!=vis.end()){
                while(low!=i && s[low]!=s[i])vis.erase(s[low++]);
                vis.erase(s[low++]);
            }
            
            vis.insert(s[i]);
            res=max(res,i-low+1);
        }
        return res;
    }
};