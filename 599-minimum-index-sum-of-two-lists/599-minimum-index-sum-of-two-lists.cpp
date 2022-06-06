class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int>mp1;
      for(int i=0;i<list1.size();i++){
          mp1[list1[i]]=i;
      }
        vector<pair<int,string>>res;
        for(int i=0;i<list2.size();i++ ){
            if(mp1.find(list2[i])!=mp1.end()){
                res.push_back({i+mp1[list2[i]],list2[i]});
            }
        }
        sort(res.begin(),res.end());
       vector<string>ans;
        for(int i=0;i<res.size();i++){
            if(i>0){
                if(res[i].first!=res[i-1].first)return ans;
            }
             ans.push_back(res[i].second);
        }
        return ans;
    }
};