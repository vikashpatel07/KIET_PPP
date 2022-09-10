class Solution {
public:
    vector<string>res;
    void solve(string s,int n, int open ,int close){
        if(s.size()==2*n){
            res.push_back(s);
            return;
        }
        if(open<n){
            solve(s+="(",n,open+1,close);
            s.pop_back();
        }
          
        if(close<open){
            solve(s+=")",n,open,close+1);
            s.pop_back();
        }
            
    }
    vector<string> generateParenthesis(int n) {
        solve("",n,0,0);
        return res;
    }
};