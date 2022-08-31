class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<int>num;
        int fact=1;
        for(int i=1;i<=n;i++){
            num.push_back(i);
            if(i==n)break;
            fact*=i;
        }
        k--;
        while(n){
           res+=to_string(num[k/fact]);
            int rem=k%fact;
            num.erase(num.begin()+k/fact);
            n--;
            if(n==0)return res;
            fact/=n;
            k=rem;
            
            
        }
        return res;
        
        
    }
};