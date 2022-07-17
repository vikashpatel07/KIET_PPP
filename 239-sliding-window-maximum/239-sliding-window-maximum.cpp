class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        list<int>li;
        int low=0;
        for(int i=0;i<nums.size();i++){
            if(li.empty())li.push_back(nums[i]);
            else{
                while(!li.empty() && li.back()<nums[i])li.pop_back();
                li.push_back(nums[i]);
            }
            
            
            if(i+1>=k){
                res.push_back(li.front());
                if(nums[low]==li.front())
                    li.pop_front();
                low++;
            }
        }
        return res;
    }
};