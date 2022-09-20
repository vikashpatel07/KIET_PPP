class StockSpanner {
public:
    using pi=pair<int,int>;
    stack<pi>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty() || st.top().first>price)st.push({price,1});
        else{
            int cnt=1;
            while(!st.empty() && st.top().first<=price){
                cnt+=st.top().second;
                st.pop();
            }
            st.push({price,cnt});
        }
        return st.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */