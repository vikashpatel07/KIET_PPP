class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>a;
        while(n){
            int rem=n%10;
            a.push_back(rem);
            n/=10;
        }
        reverse(a.begin(),a.end());
       
        int ind=-1,m=a.size();
        int i=m-2;
        while(i>=0){
            if(a[i]<a[i+1]){
                ind=i;
                break;
            }
            i--;
        }
        // cout<<ind<<"\n";
        if(ind==-1)return -1;
        for(int i=m-1;i>=0;i--){
            if(a[i]>a[ind]){
                swap(a[ind],a[i]);
                sort(a.begin()+ind+1,a.end());
                break;
            }
        }
         // for(auto x: a)cout<<x<<" ";
        long long res=0;
        for(int i=0;i<m;i++){
            res=10*res+a[i];
        }
        if(res<INT_MIN || res> INT_MAX)return -1;
        return (int)res;
    }
};