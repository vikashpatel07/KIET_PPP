class Solution {
public:
    bool check(vector<int>&a){
        if(a[0]==0)return false;
        int  num=0;
        int m=a.size();
        for(int i=0;i<m;i++){
            num=10*num+a[i];
        }
        while(num>0 && (num&1)==0)
            num>>=1;
        if(num==1)return true;
        return false;
        }
    bool permutation(vector<int> &a,int start){
        if(start==a.size())return check(a);
        for(int i=start;i<a.size();i++){
            swap(a[start],a[i]);
            if(permutation(a,start+1))
                return true;
            swap(a[start],a[i]);
        }
        return false;
    }
    bool reorderedPowerOf2(int n) {
        string temp=to_string(n);
        int m=temp.size();
        vector<int>a(m);
        for(int i=0;i<m;i++){
            a[i]=temp[i]-'0';
        }
        return permutation(a,0);
        
    }
};