class NumArray {
public:
    vector<int>temp;
    NumArray(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            temp.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        int sum=0;
        if(left==0)return temp[right];
        else return temp[right]-temp[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */