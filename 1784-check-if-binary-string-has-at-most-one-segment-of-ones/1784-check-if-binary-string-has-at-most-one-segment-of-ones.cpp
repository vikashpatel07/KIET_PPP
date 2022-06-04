class Solution {
public:
    bool checkOnesSegment(string s) {
        int flag=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                if(flag)return false;
            }
            else
                flag=1;
        
    }
            return true;
    }
};