class Solution {
public:
    int binary_search(int start,int end,vector<int>&nums,int target){
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target)end=mid-1;
            else start=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int mini=0,n=nums.size();
        int start=0,end=nums.size()-1,ind;
        while(start<=end){
            int mid=start+(end-start)/2;
            int next=(mid+1)%n,prev=(mid+n-1)%n;
            if(nums[mid]<=nums[prev]  && nums[mid]<=nums[next]){
                ind=mid;
                break;
            }
            else if(nums[0]<=nums[mid])start=mid+1;
            else end=mid-1;
        }
        cout<<ind;
        int left=binary_search(0,ind-1,nums,target);
        int right=binary_search(ind,n-1,nums,target);
        if(left>-1)return left;
        else return right;
        return -1;
    }
};