class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        peek();
        int popOut = s2.top(); s2.pop();
        return popOut;
    }
    
    int peek() {
        if (s2.size() == 0) {
            while (s1.size() > 0) {
                s2.push(s1.top()); s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.size() == 0 && s2.size() == 0;
    }
private:
    stack<int> s1, s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */