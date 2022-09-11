class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
       vector<pair<int,int>>temp;
        for(int i=0;i<speed.size();i++){
            temp.push_back({eff[i],speed[i]});
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(rbegin(temp),rend(temp));
        long ans=0,z=0;
        for(int i=0;i<temp.size();i++){
            z+=temp[i].second;
            pq.push(temp[i].second);
            if(pq.size()>k){
                z-=pq.top();
                pq.pop();
            }
            ans=max(ans,z*temp[i].first);
        }
    
    return ans % (int)(1e9 + 7);
}
};