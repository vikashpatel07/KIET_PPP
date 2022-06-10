class Solution {
public:
    bool static cmp(string &a ,string &b){
      return a+b<b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>v;
        for(auto x: nums){
            string s=to_string(x);
            v.push_back(s);
        }
        sort(v.begin(),v.end(),cmp);
        
        string res;
        for(int i=v.size()-1;i>=0;i--){
            res+=v[i];
        }
        if(res[0]=='0')return "0";
        return res;
    }
};