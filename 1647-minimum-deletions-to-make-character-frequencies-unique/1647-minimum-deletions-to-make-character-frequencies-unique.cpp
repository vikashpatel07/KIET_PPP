class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
      vector<int>a;
        for(auto x:s)mp[x]++;
        for(auto x: mp)a.push_back(x.second);
        sort(a.begin(),a.end(),greater<int>());
        int freq[100001]={0};
        int res=0,count=a[0];
        for(int i=1;i<a.size();i++){
           if(count==0)res+=a[i];
            else if(count==a[i]){
                res++;
                count=a[i]-1;
            }
            else if(count<a[i]){
                res+=abs(count-a[i])+1;
                count--;
            }
            else count=a[i];
            
        }
        return res;
        
    }
};