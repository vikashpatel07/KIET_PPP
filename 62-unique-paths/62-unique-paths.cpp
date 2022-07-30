class Solution {
public:
    int uniquePaths(int m, int n) {
       int pr=m+n-2;
        int de=m-1;
        double res=1;
        for(int i=1;i<=de;i++)
        {
            res=res*(pr-de+i)/i;
        
        cout<<res<<"\n";
        }
        return (int)res;
    }
};