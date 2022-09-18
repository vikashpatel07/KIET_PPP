class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1,lmax=0,rmax=0;
        int res=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(lmax>height[left])res+=lmax-height[left];
                else lmax=height[left];
                left++;
            }
            else{
                if(rmax>height[right])
                    res+=rmax-height[right];
                else
                    rmax=height[right];
                right--;
            }
        }
        return res;
    }
};