class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        topV = x;
    }
    
    int pop() {
        int size = q.size();
        while (size > 2) {
            q.push(q.front()); q.pop();
            size --;
        }
        topV = q.front(); q.pop();
        q.push(topV);
        int popOut = q.front(); q.pop();
        return popOut;
    }
    
    int top() {
        return topV;
    }
    
    bool empty() {
        return q.size() == 0;
    }
private:
    queue<int> q;
    int topV = 0;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */