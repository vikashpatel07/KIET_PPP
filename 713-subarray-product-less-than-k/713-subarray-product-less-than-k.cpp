class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res=0;
        int n=nums.size();
        int start=0;
        long long p=1;
        if(k<=1)return 0;
        for(int end=0;end<n;end++){
            p*=nums[end];
            while(p>=k){
                p/=nums[start++];
            }
            res+=end-start+1;
        }
        return res;
    }
};