class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>A,B;
        for(auto x: t)B[x]++;
        string ans="";
        int res=INT_MAX,i=0,j=0,count=0;
        while(j<s.size()){
            char ch=s[j];
            if(B.find(ch)!=B.end()){
                A[ch]++;
                if(A[ch]<=B[ch])
                    count++;
            }
            if(count>=t.length()){
                while(B.find(s[i])==B.end()  || A[s[i]]>B[s[i]]){
                    A[s[i]]--;
                    i++;
                }
                if(res>j-i+1){
                    ans=s.substr(i,j-i+1);
                    res=j-i+1;
                }
                // i++;
            }
            j++;
        }
        return ans;
    }
};