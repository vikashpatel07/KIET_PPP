class Solution {
public:
    int fib(int n) {
        vector<int> a(n+1);
        for(int i=0;i<=n;i++){
            if(i==0)a[i]=0;
            if(i==1)a[i]=1;
            if(i>1)
            a[i]=a[i-1]+a[i-2];
        }
        return a[n];
    }
};