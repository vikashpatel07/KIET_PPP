class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        vector<int>temp(2);
        temp[0]=intervals[0][0];
        temp[1]=intervals[0][1];
        for(int i=0;i<intervals.size();i++){
            if(temp[1]>=intervals[i][0])
                temp[1]=max(temp[1],intervals[i][1]);
            else{
                res.push_back(temp);
                temp=intervals[i];
            }
        }
        res.push_back(temp);
        return res;
    }
};