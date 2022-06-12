class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>mp;
        // for(auto x: nums)mp[x]++;
        int start=0,end=nums.size()-1,low=0,res=INT_MIN;
        int sum=0;
        while(start<=end){
            if(mp.find(nums[start])==mp.end()){
                mp[nums[start]]=1;
                sum+=nums[start];
            }
            else{
                while(mp.find(nums[start])!=mp.end()){
                    mp.erase(nums[low]);
                    sum-=nums[low];
                    low++;
                }
                sum+=nums[start];
                mp[nums[start]]=1;
            }
            start++;
            res=max(res,sum);
        }
        return res;
    }
};