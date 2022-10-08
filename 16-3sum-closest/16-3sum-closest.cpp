class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=0,d=INT_MAX,ans;
        
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
               sum=nums[i]+nums[j]+nums[k];
                if(sum-target==0)return sum;
                else if(sum>target)k--;
                else j++;
                 if(abs(target-sum)<d){
                        d=abs(target-sum);
                        ans=sum;
                    }
                }                
            }
        
        return ans;
        
    }
};