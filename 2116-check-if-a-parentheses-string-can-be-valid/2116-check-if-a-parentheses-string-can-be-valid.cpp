class Solution {
public:
    bool canBeValid(string s, string l) {
        int un=0,op=0,cl=0;
        if(s.size()%2==1)return false;
        for(int i=0;i<s.size();i++){
            if(l[i]=='0')un++;
            else if (s[i]=='(')op++;
            else cl++;
            if(cl-op>un)return false;
        }
        un=0,op=0,cl=0;
        for(int i=s.size()-1;i>=0;i--){
            if(l[i]=='0')un++;
            else if(s[i]=='(')op++;
            else cl++;
            if(op-cl>un)return false;
        }
        return true;
    }
};