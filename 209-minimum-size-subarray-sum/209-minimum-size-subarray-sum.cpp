class Solution {
public:
    int minSubArrayLen(int sum, vector<int>& nums) {
        int start=0,end=nums.size()-1,low=0;
        int cur=0,res=INT_MAX;
        while(start<=end){
            cur+=nums[start];
            if(cur>=sum){
                
                while(cur>=sum){
                    cur-=nums[low++];
                }
            res=min(res,start-low+2);

            }
            start++;
        }
        return res==INT_MAX?0:res;
    }
};