class Solution {
public:
    int solve(char ch,string s,int k){
        int cnt=0,res=0;
        int i=0,n=s.size(),j=0;
        while(j<n){
            if(s[j]!=ch)cnt++;
            
            
                while(cnt>k){
                    if(s[i]!=ch){
                        cnt--;
                    }
                    i++;
                
                }
                
            
            res=max(res,j-i+1);
            j++;
            
            
        }
        cout<<res<<" ";
        return res;
    }
    int characterReplacement(string s, int k) {
        int res=0;
        for(int i=0;i<26;i++){
            res=max(res,solve(i+'A',s,k));
        }
        return res;
    }
};