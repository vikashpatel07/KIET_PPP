class MinStack {
public:
    vector<int>a,b;
    MinStack() {
        
    }
    
    void push(int val) {
        a.push_back(val);
        if(b.empty() || b.back()>=val)
            b.push_back(val);
    }
    
    void pop() {
        if(b.back()==a.back())b.pop_back();
        a.pop_back();
    }
    
    int top() {
        return a.back();
    }
    
    int getMin() {
        return b.back();
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