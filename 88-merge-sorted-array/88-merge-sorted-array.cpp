class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
        for(int i=0;i<m;i++){
            if(n==0)break;
            if(nums1[i]>nums2[0]){
                swap(nums1[i],nums2[0]);
            
                int num=nums2[0];
                int j=1;
                while(j<n && nums2[j]<num){
                    nums2[j-1]=nums2[j];
                    j++;
                }
                nums2[j-1]=num;
                
              
            }
        }
        int i=m, j=0;
        
        while(j<n)nums1[i++]=nums2[j++];
    }
};