class Solution {
public:
    vector<vector<int>>res;
    void solve(vector<int> &nums,vector<int> &vis,vector<int>&temp){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i]==0){
                vis[i]=1;
                temp.push_back(nums[i]);
                solve(nums,vis,temp);
                vis[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>vis(n,0);
        vector<int>temp;
        solve(nums,vis,temp);
        return res;
    }
};