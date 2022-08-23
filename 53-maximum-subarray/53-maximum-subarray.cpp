class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0];
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            sum=max(sum,nums[i]);
            if(res<sum)res=sum;
            
        }
        return res;
    }
};