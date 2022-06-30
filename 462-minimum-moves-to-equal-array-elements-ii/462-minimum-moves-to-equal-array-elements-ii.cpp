class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int res=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=(n-1)/2;
        int left=mid-1,right=mid+1;
        while(left>=0 ||right<n){
            if(left>=0)
            res+=nums[mid]-nums[left--];
            if(right<n)
            res+=nums[right++]-nums[mid];
        }
        return res;
    }
};