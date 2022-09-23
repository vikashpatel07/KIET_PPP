class Solution {
public:
    int concatenatedBinary(int n) {
        long long int res=0;
        int mod=1e9+7;
        for(int i=1;i<=n;i++)
        {
            int j=0;
            int ii=i;
            while(ii!=0)
            {
              
                    j++;
                ii=ii>>1;
            }
          res=((res<<(j))%mod+i)%mod;
        }
        return res;
    }
};