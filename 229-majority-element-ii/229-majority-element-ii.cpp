class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>res;
        int count1=0,count2=0,cand1=-1,cand2=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==cand1)count1++;
            else if(nums[i]==cand2)count2++;
            else if(count1==0){
                cand1=nums[i];
                count1++;
               
            }
            else if(count2==0){
                cand2=nums[i];
                count2++;
            }
            
            else {
                count1--;
                count2--;
            }
        }
        int cnt=0,c=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==cand1)c++;
            else if(nums[i]==cand2)cnt++;
        }
        if(cnt>n/3)res.push_back(cand2);
        if(c>n/3)res.push_back(cand1);
        return res;
    }
};