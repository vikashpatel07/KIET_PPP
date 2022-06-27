class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
     
        for(int i=0;i<nums.size();i++){
             vector<int>temp,sorted;
            temp=nums;
            auto it=temp.begin()+i;
            temp.erase(it);
            sorted=temp;
            sort(sorted.begin(),sorted.end());
            for(int j=0;j<temp.size();j++){
                if(temp[j]!=sorted[j])break;
                if(j>0 && temp[j]==temp[j-1])break;
                if(j==temp.size()-1)return true;
            }
        }
        return false;
    }
};