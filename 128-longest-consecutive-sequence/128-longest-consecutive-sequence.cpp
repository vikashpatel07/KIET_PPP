class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x: nums)mp[x]++;
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]-1)==mp.end()){
                int temp=1;
                int num=nums[i]+1;
                while(mp.find(num)!=mp.end()){
                    temp++;
                    num++;
                }
                res=max(res,temp);
            }
        }
        return res;
    }
};