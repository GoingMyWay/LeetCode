class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
    }
    
    int popSmallest() {
        if (q.size() > 0) {
            int res = q.top(); q.pop();
            s.erase(res);
            return res;   
        } else {
            int res = currMin;
            currMin ++;
            return res;
        }
    }
    
    void addBack(int num) {
        if (num >= currMin || s.find(num) != s.end()) return;
        q.push(num);
        s.insert(num);
    }

private:
    int currMin = 1;
    struct compare {
        bool operator() (const int & a, const int & b) {
            return a > b;
        }
    };
    set<int> s;
    priority_queue<int, std::vector<int>, compare> q;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */