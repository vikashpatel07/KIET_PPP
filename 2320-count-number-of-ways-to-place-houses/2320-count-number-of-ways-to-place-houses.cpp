class Solution {
public:
    int countHousePlacements(int n) {
        int p1=1,p2=1;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            int cur=(p1+p2)%mod;
            p2=p1;
            p1=cur;
        }
        return (1ll*p1*p1)%mod;
    }
};