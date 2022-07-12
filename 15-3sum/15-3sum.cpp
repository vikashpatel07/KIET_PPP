class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i==0 || nums[i]!=nums[i-1]){
                int start=i+1,end=nums.size()-1;
                while(start<end){
                    if(nums[start]+nums[end]+nums[i]==0){
                        res.push_back({nums[start]
                            ,nums[end],nums[i]});
                      while(start<end && nums[start]==nums[start+1])start++;
                         while(end>0 && nums[end]==nums[end-1])end--;
                        start++;
                        end--;
                    }
                     else if(nums[start]+nums[end]+nums[i]<0)
                         start++;
                    else end--;
                }
            }
        }
        return res;
    }
};