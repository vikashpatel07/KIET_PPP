class MinStack {
public:
    vector<pair<int,int>>a;
    int topp=-1;
  int mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(a.empty())a.push_back({val,val});
        else{
            a.push_back({val,min(a.back().second,val)});
        }
    }
    
    void pop() {
       a.pop_back();
    }
    
    int top() {
        return a.back().first;
    }
    
    int getMin() {
        return a.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */