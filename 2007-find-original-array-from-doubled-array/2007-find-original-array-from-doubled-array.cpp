class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int>mp;
        for(int i=0;i<changed.size();i++){
            mp[changed[i]]++;
        }
        sort(changed.begin(),changed.end());
        vector<int>res;
        // for(auto x: mp)cout<<x.first<<" "<<x.second<<"\n";
        for(int i=0;i<changed.size();i++){
            if(changed[i]==0 && mp[changed[i]]%2==0 && mp[changed[i]]!=0){
                res.push_back(0);
                mp[changed[i]]-=2;
            }
            else if(changed[i]==0)continue;
            else{
            
             if(mp.find(changed[i]*2)!=mp.end()){
                if(mp[changed[i]]==0)continue;
                if(mp[changed[i]*2]==0)continue;
                
                mp[changed[i]]--;
                mp[changed[i]*2]--;
               res.push_back(changed[i]); 
                             
            }
        }
        }
        if(res.size()*2==changed.size())
        return res;
        return {};
        
    }
};