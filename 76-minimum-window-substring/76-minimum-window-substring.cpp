class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(auto x: t)mp[x]++;
        int res=INT_MAX,ind=0,i=0,j=0,count=0;
        while(j<s.size()){
            if(mp[s[j]]>0)count++;
            mp[s[j]]--;
            if(count==t.length()){
                while(i<j && mp[s[i]]<0){
                    mp[s[i]]++;
                    i++;
                }
                if(res>j-i+1){
                    res=j-i+1;
                    ind=i;
                }
                mp[s[i++]]++;
               
                count--;
                cout<<ind<<" ";
            }
            j++;
        }
         return res == INT_MAX ? "" : s.substr(ind, res);
    }
};