class Solution {
public:
    int maxProduct(vector<int>& nums) {
       vector<int>pref;
        int p=1;
        int res=INT_MIN;
        for(auto x: nums){
            p*=x;
            res=max(res,p);
            // pref.push_back(p);
            if(p==0)p=1;
            
        }
        p=1;
        for(int i=nums.size()-1;i>=0;i--){
              p*=nums[i];
            res=max(res,p);
            // pref.push_back(p);
            if(p==0)p=1;
        }
        return res;
        
    }
};