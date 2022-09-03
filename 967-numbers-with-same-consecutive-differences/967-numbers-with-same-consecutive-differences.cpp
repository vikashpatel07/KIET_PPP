class Solution {
public:
    vector<int>res;
    void solve(int n,int k,vector<int>& temp){
        if(temp.size()==n){
            int num=0;
            for(int i=0;i<n;i++){
                num=num*10+temp[i]%10;
            }
            res.push_back(num);
            return ;
        }
        for(int i=0;i<10;i++){
            if(abs(temp.back()-i)==k){
                temp.push_back(i);
                solve(n,k,temp);
                temp.pop_back();
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        
        for(int i=1;i<10;i++){
            vector<int>temp;
            temp.push_back(i);
            solve(n,k,temp);
            
        }
        return res;
    }
};