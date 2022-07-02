class Solution {
public:
    int maxArea(int hh, int w, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
        const int MOD = 1e9 + 7;

        sort(v.begin(),v.end());
        long int resh=h[0],resv=v[0];
        for(int i=1;i<h.size();i++){
            resh=max(resh,(long int)h[i]-h[i-1]);
            
        }
        for(int i=1;i<v.size();i++)
            resv=max(resv,(long int)v[i]-v[i-1]);
         resh=max(resh,(long int)hh-h[h.size()-1]);
         resv=max(resv,(long int)w-v[v.size()-1]);
        return (resh*resv)%MOD;
    }
   
};