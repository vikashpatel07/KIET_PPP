class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
      vector<int>a;
        for(auto x:s)mp[x]++;
        for(auto x: mp)a.push_back(x.second);
        sort(a.begin(),a.end(),greater<int>());
        int freq[100001]={0};
        int res=0;
        for(int i=0;i<a.size();i++){
            if(freq[a[i]]==1){
                int j=a[i],flag=0;
                while(freq[j]!=0){
                    j--;
                    if(j==-1){
                        flag=1;
                        break;
                    }
                    // cout<<"v  ";
                }
                if(flag)res+=a[i];
                else{
                    res+=a[i]-j;
                    freq[j]=1;
                    }
            
            }
            else freq[a[i]]=1;
        }
        return res;
        
    }
};