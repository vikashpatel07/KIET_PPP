class Solution {
public:
    vector<vector<int>>res;
    
    void solve(int i,int n,vector<int> & nums,vector<int> & temp,int target){
        if(i==n){
            if(target==0)
            res.push_back(temp);
            return;
        }
        
            if(nums[i]<=target){
                temp.push_back(nums[i]);
                solve(i,n,nums,temp,target-nums[i]);
                temp.pop_back();
            }
            solve(i+1,n,nums,temp,target);
        
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        int n=c.size();
        vector<int>temp;
        solve(0,n,c,temp,target);
        return res;
    }
};