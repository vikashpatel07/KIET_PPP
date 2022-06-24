class Solution {
    public void nextPermutation(int[] nums) {
        int n=nums.length;
        int ind=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            Arrays.sort(nums);
        }
        else{
            int num=nums[ind];
            for(int i=n-1;i>=0;i--){
                if(nums[i]>num){
                    int temp=nums[i];
                    nums[i]=num;
                    nums[ind]=temp;
                    System.out.println(ind);
                    Arrays.sort(nums,ind+1,n);
                    break;
                }
            }
        }
    }
}