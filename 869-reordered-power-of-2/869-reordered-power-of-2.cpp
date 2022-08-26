class Solution {
public:
    string solve(int n){
        string res=to_string(n);
        sort(res.begin(),res.end());
        return res;
        
    }
    bool reorderedPowerOf2(int n) {
        string t=solve(n);
        for(int i=0;i<31;i++){
            if(t==solve(1<<i))return true;
        }
        return false;
    }
};