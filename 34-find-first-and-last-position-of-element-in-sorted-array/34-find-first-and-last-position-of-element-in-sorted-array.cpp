class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res;
        int ind=-1;
        int start=0,end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                ind=mid;
                end=mid-1;
            }
            else if(nums[mid]>target)end=mid-1;
            else start=mid+1;
        }
        res.push_back(ind);
        start=0,end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
               ind=mid;
                start=mid+1;
            }
            else if(nums[mid]<target)start=mid+1;
            else end=mid-1;
        }
        res.push_back(ind);
        return res;
    }
};