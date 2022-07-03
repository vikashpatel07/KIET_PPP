class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int>a(n),b(n);;
        a[0]=1,b[0]=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                a[i]=1+b[i-1];
                b[i]=b[i-1];
            }
            else if(nums[i]<nums[i-1]){
                b[i]=1+a[i-1];
                a[i]=a[i-1];

            }
            else{
                b[i]=b[i-1];
                a[i]=a[i-1];
            }
        }
        return max(a[n-1],b[n-1]);
        
    }
};