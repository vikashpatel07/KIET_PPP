class Solution {
public:
    vector<vector<string>>res;
    bool isok(string s,int ind,int i){
        while(ind<i){
            if(s[ind]!=s[i])
                return false;
            ind++;
            i--;
        }
        return true;
    }
    void solve(int ind,string s,vector<string>
& temp){
        if(ind==s.size()){
            res.push_back(temp);
            return ;
        }
        for(int i=ind;i<s.size();i++){
            if(isok(s,ind,i)){
                string p=s.substr(ind,i-ind+1);
                temp.push_back(p);
                solve(i+1,s,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        solve(0,s,temp);
        return res;
    }
};