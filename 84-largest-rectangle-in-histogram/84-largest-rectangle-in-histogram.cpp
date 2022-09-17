class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int>left(n,0),right(n,n-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()]>=h[i])st.pop();
            if(!st.empty())left[i]=st.top()+1;
            st.push(i);
        }
        stack<int>s;
         for(int i=n-1;i>=0;i--){
            while(!s.empty() && h[s.top()]>=h[i])s.pop();
            if(!s.empty())right[i]=s.top()-1;
            s.push(i);
        }
        int res=0;
        for(int i=0;i<n;i++){
            res=max(res,(right[i]-left[i]+1)*h[i]);
        }
        return res;
    }
};