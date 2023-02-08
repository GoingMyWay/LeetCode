static int inum = 10;
using line = pair<int, int>;
int distance(const line & a) {
    // 返回中点和两个端点最近的距离
    int len = (a.second - a.first) / 2;
    if (a.first == -1) {
        return a.second;
    }
    if (a.second == inum) {
        return inum - 1- a.first;
    }
    return len;
};

struct comp {
    bool operator()(const line & a, const line & b) const {
        int distA = distance(a);
        int distB = distance(b);
        // 如果长度相等，那就取index小的
        if(distA == distB) {
            return a.first < b.first;
        }
        // 根据线段长度，从大到小排序
        return distA > distB;
    };
};

class ExamRoom {
public:

    int N; // 记录座位总数量

    set<line, comp> pq; //根据线段长度，从小到大存储所有线段

    unordered_map<int, line> startMap; // 以p开头的线段
    unordered_map<int, line> endMap; // 以p结尾的线段

    // 增加一个线段
    void addInterval(const line & p) {
        startMap.insert({p.first, p});
        endMap.insert({p.second, p});
        pq.insert(p);
    }

    // 删除一个线段
    void delInterval(const line & p) {
        pq.erase(p);
        startMap.erase(p.first);
        endMap.erase(p.second);
    }

    ExamRoom(int n) {
        N = n;
        inum = n;

        // 存放一个虚拟线段[-1, N]
        addInterval({-1, N});
    }
    
    int seat() {
        // 选出最长的线段来
        line interval = *pq.begin();
        int x = interval.first;
        int y = interval.second;

        // 找到线段中点,也就是seat的位置
        int seat;
        if(x == -1) {
            seat = 0;
        } else if (y == N) {
            seat = N - 1;
        } else {
            seat = (x + y) / 2;
        }

        // 删除这个线段, 并插入两个新的线段
        delInterval(interval);
        addInterval({x, seat});
        addInterval({seat, y});

        // 返回选择的座位
        return seat;
    }
    
    void leave(int p) {
        // 找到两段的线段
        line left = endMap[p];
        line right = startMap[p];

        // 删除这两个线段，并插入一个新的线段
        line newInterval = {left.first, right.second};
        delInterval(left);
        delInterval(right);
        addInterval(newInterval);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */