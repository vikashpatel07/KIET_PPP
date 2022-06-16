void isPalindrome(string &s,int i,int j,int &l,int &r){
    int n=s.length();
    while(i>=0 and j<n){
        if(s[i]!=s[j])break;
        i--;j++;
    }
    l=i+1;r=j;
    return;
}
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int l=0,r=0;
        if(n==1)return s;
        string ans="";
        for(int i=0;i<n-1;i++){
            
            isPalindrome(s,i,i,l,r);
            string t=s.substr(l,r-l);
            if(t.length()>ans.length())
                ans=t;
            
            isPalindrome(s,i,i+1,l,r);
            t=s.substr(l,r-l);
            if(t.length()>ans.length())
                ans=t;
        }
        return ans;
    }
};