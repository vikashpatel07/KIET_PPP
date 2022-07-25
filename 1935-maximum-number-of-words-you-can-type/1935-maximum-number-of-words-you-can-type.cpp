class Solution {
public:
    int canBeTypedWords(string text, string b) {
        
        unordered_map<char,int>mp;
        for(auto x: b)mp[x]++;
        stringstream s(text);
        string word;
        int res=0,f=0;
        while(s>>word){
            for(int i=0;i<word.size();i++){
                if(mp.find(word[i])!=mp.end())
                    f=1;
            }
            if(f==0)res++;
            f=0;
        }
        return res;
    }
};