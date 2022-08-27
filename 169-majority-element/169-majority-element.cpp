class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=0,count=1;
        int cand=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==cand){
                count++;
            }
            else
                count--;
            if(count==0){
                cand=nums[i];
                count=1;
            }
        }
        return cand;
    }
};