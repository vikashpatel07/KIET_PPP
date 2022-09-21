class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        long long int even=0,odd=0;
        for(auto x:nums){
            if(x&1)odd+=x;
            else even+=x;
        }
        vector<int>res;
        for(int i=0;i<q.size();i++){
            // for(auto x: nums)cout<<x<<" ";
            // cout<<"->"<<even<<" ";
            if(q[i][0]%2 && nums[q[i][1]]%2){
               
                nums[q[i][1]]+=q[i][0];
                 even+=nums[q[i][1]];
            }
            else if(q[i][0]%2 && nums[q[i][1]]%2==0){
                even-=nums[q[i][1]];
                nums[q[i][1]]+=q[i][0];
               
            }
             else if(abs(q[i][0])%2==0 && nums[q[i][1]]%2==0){
                 even+=q[i][0];
                nums[q[i][1]]+=q[i][0];
              
            }
            else if(q[i][0]%2==0 && nums[q[i][1]]%2){
               
                nums[q[i][1]]+=q[i][0];
               
            }
            // cout<<even<<"\n";
            res.push_back(even);
            
        }
        return res;
    }
};