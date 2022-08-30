class Solution {
public:
    vector<vector<int>>res;
    
    void solve(int ind,int n,vector<int>&nums, vector<int> &temp){
        res.push_back(temp);
        for(int i=ind;i<n;i++){
            if(i!=ind && nums[i-1]==nums[i])continue;
            temp.push_back(nums[i]);
            solve(i+1,n,nums,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        sort(nums.begin(),nums.end());
        solve(0,n,nums,temp);
        return res;
    }
};