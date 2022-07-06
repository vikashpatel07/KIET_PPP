class Solution {
public:
   vector<int> res;
    bool solve(int ind,string s){
        int n=s.size();
        if(ind>=n && res.size()>=3)
            return true;
        
        int sz=res.size();
        if(s[ind]=='0')sz=1;
        else sz=10;
        
        for(int i=1;i<=sz && ind+i<=s.size();i++){
            long long num=stoll(s.substr(ind,i));
            if(num>INT_MAX)
                return false;
            int size=res.size();
           
            if(res.size()<=1 ||(long long)res[size-1]+(long long)res[size-2]==num){
            res.push_back(num);
            if(solve(ind+i,s))return true;
            res.pop_back();
            
    }
        }
        
        return false;
    }
    vector<int> splitIntoFibonacci(string num) {
        solve(0,num);
        return res;
    }
};