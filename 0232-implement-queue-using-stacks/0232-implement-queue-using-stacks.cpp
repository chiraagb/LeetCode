class MyQueue {
public:
    // O(1) || ~O(n)
    stack<int>ip;
    stack<int>op;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        ip.push(x);
    }
    
    int pop() {
        if(op.empty()){
            while(!ip.empty()){
                op.push(ip.top());
                ip.pop();
            }
        }
        int res = op.top();
        op.pop();
        return res;
        
    }
    
    int peek() {
        if(op.empty()){
            while(!ip.empty()){
                op.push(ip.top());
                ip.pop();
            }
        }
        return op.top();
    }
    
    bool empty() {
        return op.empty() && ip.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */