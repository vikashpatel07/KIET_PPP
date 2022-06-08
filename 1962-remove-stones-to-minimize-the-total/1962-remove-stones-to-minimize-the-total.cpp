class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int res=0;
        int sum=0;
        for(auto x: piles){
            pq.push(x);
            sum+=x;
        }
        while(k--){
            int x=pq.top();
            pq.pop();
            sum-=x/2;
            pq.push(x-x/2);
        }
        return sum;
    }
};