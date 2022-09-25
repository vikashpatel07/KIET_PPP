class MyCircularQueue {
public:
    vector<int>a;
    int s;
    MyCircularQueue(int k) {
        // a(k);
        s=k;
    }
    
    bool enQueue(int value) {
        if(a.size()<s){
            a.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(a.size()==0)return false;
       a.erase(a.begin());
        return true;
    }
    
    int Front() {
        if(a.size()==0)return -1;
        return a[0];
    }
    
    int Rear() {
       if(a.size()==0)return -1;
        return a.back();
    }
    
    bool isEmpty() {
        return a.empty();
    }
    
    bool isFull() {
        return a.size()==s;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */