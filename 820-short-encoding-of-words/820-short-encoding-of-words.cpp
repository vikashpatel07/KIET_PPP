class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
         sort(words.begin(),words.end(),[](auto &a,auto &b)
         {
             return a.size()>b.size();
         });
    
    unordered_map<string,bool>mp;
    
    int length=0;
    for(auto it:words)
    {
        if(mp.find(it)==mp.end())
        {
            length+=it.size()+1;
            for(int i=0;i<it.size();i++)
                mp[it.substr(i)]=true;
        }
    }
    return length;
    }
};