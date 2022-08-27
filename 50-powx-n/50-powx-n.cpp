class Solution {
public:
    double myPow(double x, int n) {
        double res= 1.0;
        long long temp=n;
        if(n<0)temp*=-1;
        while(temp){
            if(temp&1){
                res*=x;
                temp--;
        }
        else{
            x*=x;
            temp/=2;   
        
        }
        }
        if(n<0)res=(1.0)/res;
        return res;
    }
};