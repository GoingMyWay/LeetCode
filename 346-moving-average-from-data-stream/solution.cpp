class MovingAverage {
public:
    MovingAverage(int size) {
        max_size = size;
    }
    
    double next(int val) {
        if (q.size() == max_size) {
            int v = q.front(); q.pop();
            queue_sum -= v;
        }
        q.push(val);
        queue_sum += val;
        return (double) queue_sum / q.size();
    }
private:
    int max_size, queue_sum = 0;
    queue<int> q;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */