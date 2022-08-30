class Solution {
public:
    
    vector<vector<int>>res;
    
    void solve(int ind,int n,vector<int> &nums,vector<int> &temp,int target){
    
            if(target==0)res.push_back(temp);
           
        
        
        for(int i=ind;i<n;i++){
            if(i!=ind && nums[i-1]==nums[i])continue;
            if(nums[i]<=target){
                temp.push_back(nums[i]);
                solve(i+1,n,nums,temp,target-nums[i]);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        int n=c.size();
        sort(c.begin(),c.end());
        vector<int>temp;
        solve(0,n,c,temp,target);
        return res;
    }
};