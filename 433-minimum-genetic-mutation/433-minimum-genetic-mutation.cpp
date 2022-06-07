class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
      vector<char>temp={'A','C','G','T'};
        unordered_set<string>st(bank.begin(),bank.end());
        queue<string>q;
        int ans=0;
        q.push(start);
        while(!q.empty()){
           int n=q.size();
            for(int i=0;i<n;i++){
                 string t=q.front();
                q.pop();
                if(t==end)return ans;
                st.erase(t);
                for(int j=0;j<8;j++){
                    char c=t[j];
                    for(int k=0;k<4;k++){
                        t[j]=temp[k];
                        if(st.find(t)!=st.end())
                            q.push(t);
                    }
                    t[j]=c;
                }
            }
            ans++;
        }
        return -1;
    }
};