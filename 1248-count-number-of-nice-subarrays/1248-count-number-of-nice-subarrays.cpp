class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
          unordered_map<int, int> m;
         int n = nums.size();
        int res = 0;
        int a = 0;
        m[0] = 1;
        for (int i = 0; i < n; ++i) {
            a += (nums[i]%2);
            res += m[a-k];
            m[a]++;
        }
        return res;
    }
};