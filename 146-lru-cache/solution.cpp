class Node {
public:
    int key, val;
    Node * next, * prev;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
    }
};


class DoubleList {
public:
    int size;
    DoubleList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addLast(Node* x) {
        tail->prev->next = x;
        x->prev = tail->prev;
        tail->prev = x;
        x->next = tail;
        size ++;
    }

    void remove(Node* x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
        x->next = NULL;
        x->prev = NULL;
        // delete x;
        size --;
    }
    
    Node* removeFirst() {
        if (head->next == tail) {
            return NULL;
        }
        Node* first = head->next;
        remove(first);
        return first;
    }

private: 
    Node * head, * tail;
};


class LRUCache {
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        if (map.count(key) != 1) {
            return -1;
        }
        makeRecently(key);
        return map[key]->val;

    }

    void makeRecently(int key) {
        Node* x = map[key];
        cache.remove(x);
        cache.addLast(x);
    }
    
    void put(int key, int value) {
        if (map.count(key) == 1) {
            deleteKey(key);
            addRecently(key, value);
            return;
        }
        
        if (cache.size >= cap) {
            removeLeastRecently();
        }
        addRecently(key, value);
    }

    void removeLeastRecently() {
        Node* deletedNode = cache.removeFirst();
        int deletedKey = deletedNode->key;
        map.erase(deletedKey);
    }

    void deleteKey(int key) {
        Node* x = map[key];
        cache.remove(x);
        delete x;
        map.erase(key);
    }

    void addRecently(int key, int val) {
        Node* x = new Node(key, val);
        cache.addLast(x);
        map[key] = x;
    }

private:
    int cap;
    DoubleList cache;
    map<int, Node*> map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */