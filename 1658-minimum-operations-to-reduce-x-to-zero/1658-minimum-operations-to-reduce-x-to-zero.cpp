class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
       int res=0,start=0,end=nums.size()-1,low=0;
        int sum=0;
        for(auto y: nums)sum+=y;
        if(sum<x)return -1;
        sum-=x;
        if(sum==0)return nums.size();
        int cur=0;
        while(start<=end){
            cur+=nums[start];
            if(cur>sum){
                while(cur>sum){
                    cur-=nums[low++];
                }
            }
            if(cur==sum)res=max(res,start-low+1);
            start++;
        }
        if(res==0)return -1;
        return (int)nums.size()-res;
        
    }
};