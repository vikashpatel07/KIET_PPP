class Solution {
public:
    bool checkValidString(string s) {
      int st=0,op=0,cl=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')op++;
            else if(s[i]=='*')st++;
            else cl++;
            if(cl-op>st)return false;
        }
        op=0,cl=0,st=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(')op++;
            else if(s[i]=='*')st++;
            else cl++;
            if(op-cl>st)return false;
        }
        return true;
    }
};