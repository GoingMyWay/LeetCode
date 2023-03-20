// ASCII 码个数
const int R = 27;

template<class T>
class TrieNode {
public:
    TrieNode() {
        val = T();
        children = vector<TrieNode*>(R);
    }
    T val;
    vector<TrieNode*> children;
};

// 底层用 Trie 树实现的键值映射
// 键为 string 类型，值为类型 T
template<class T>
class TrieMap {
public:
    TrieMap() {
        root = new TrieNode<T>();
        _size = 0;
    }

    /***** 增/改 *****/

    // 在 Map 中添加 key
    void put(string & key, T val) {
        if (!containsKey(key)) {
            // 新增键值对
            _size ++;
        }
        // 需要一个额外的辅助函数，并接收其返回值
        root = put(root, key, val, 0);
    }

    // 定义：向以 node 为根的 Trie 树中插入 key[i..]，返回插入完成后的根节点
    TrieNode<T> * put(TrieNode<T> * node, string & key, T val, int i) {
        if (node == nullptr) {
            // 如果树枝不存在，新建
            node = new TrieNode<T>();
        }
        if (i == key.length()) {
            // key 的路径已插入完成，将值 val 存入节点
            node->val = val;
            return node;
        }
        char c = key[i];
        if (checkBound()) c = c - 'a';
        // 递归插入子节点，并接收返回值
        node->children[(int)c] = put(node->children[(int)c], key, val, i + 1);
        return node;
    }

    /***** 删 *****/

    // 删除键 key 以及对应的值
    void remove(string & key) {
        if (!containsKey(key)) {
            return;
        }
        // 递归修改数据结构要接收函数的返回值
        root = remove(root, key, 0);
        _size--;
    }

    // 定义：在以 node 为根的 Trie 树中删除 key[i..]，返回删除后的根节点
    TrieNode<T> * remove(TrieNode<T> * node, string & key, int i) {
        if (node == nullptr) {
            return nullptr;
        }
        if (i == key.length()) {
            // 找到了 key 对应的 TrieNode，删除 val
            node->val = T();
        } else {
            char c = key[i];
            // 递归去子树进行删除
            node->children[(int)c] = remove(node->children[(int)c], key, i + 1);
        }
        // 后序位置，递归路径上的节点可能需要被清理
        if (node->val != T()) {
            // 如果该 TireNode 存储着 val，不需要被清理
            return node;
        }
        // 检查该 TrieNode 是否还有后缀
        for (char c = 0; (int)c < R; c++) {
            if (node->children[(int)c] != nullptr) {
                // 只要存在一个子节点（后缀树枝），就不需要被清理
                return node;
            }
        }
        // 既没有存储 val，也没有后缀树枝，则该节点需要被清理
        delete node;
        return nullptr;
    }

    /***** 查 *****/
    // 搜索 key 对应的值，不存在则返回 null
    // get("the") -> 4
    // get("tha") -> null
    T get(string & key) {
        TrieNode<T> * x = getNode(root, key);
        if (x == nullptr || x->val == T()) {
            return T();
        }
        return x->val;
    }

    TrieNode<T> * getNode(TrieNode<T>* node, string& key) {
        TrieNode<T> * p = node;
        // 从节点 node 开始搜索 key
        for (int i = 0; i < key.length(); i++) {
            if (p == nullptr) {
                // 无法向下搜索
                return nullptr;
            }
            // 向下搜索
            char c = key[i];
            if (checkBound()) c = c - 'a';
            p = p->children[(int)c];
        }
        return p;
   }

    // 判断 key 是否存在在 Map 中
    // containsKey("tea") -> false
    // containsKey("team") -> true
    bool containsKey(string & key) {
        return get(key) != T();
    }

    // 在 Map 的所有键中搜索 query 的最短前缀
    // shortestPrefixOf("themxyz") -> "the"
    string shortestPrefixOf(string & query) {
        TrieNode<T> * p = root;
        // 从节点 node 开始搜索 key
        for (int i = 0; i < query.length(); i++) {
            if (p == nullptr) {
                // 无法向下搜索
                return "";
            }
            if (p->val != T()) {
                // 找到一个键是 query 的前缀
                return query.substr(0, i);
            }
            // 向下搜索
            char c = query[i];
            if (checkBound()) c = c - 'a';
            p = p->children[(int)c];
        }

        if (p != nullptr && p->val != T()) {
            // 如果 query 本身就是一个键
            return query;
        }
        return "";
    }

    // 在 Map 的所有键中搜索 query 的最长前缀
    // longestPrefixOf("themxyz") -> "them"
    string longestPrefixOf(string & query) {
        TrieNode<T> * p = root;
        // 记录前缀的最大长度
        int maxLen = 0;
        for (int i = 0; i < query.size(); i ++) {
            if (p == nullptr) {
                // 无法向下搜索
                return "";
            }
            if (p->val != T()) {
                // 找到一个键是 query 的前缀
                maxLen = i;
            }
            // 向下搜索
            char c = query[i];
            if (checkBound()) c = c - 'a';
            p = p->children[(int)c];
        }
        if (p != nullptr && p->val != T()) {
            // 如果 query 本身就是一个键
            return query;
        }
        return query.substr(0, maxLen);
    }

    // 搜索所有前缀为 prefix 的键
    // keysWithPrefix("th") -> ["that", "the", "them"]
    vector<string> keysWithPrefix(string & prefix) {
        vector<string> res;
        // 找到匹配 prefix 在 Trie 树中的那个节点
        TrieNode<T>* x = getNode(root, prefix);
        if (x == nullptr) {
            return res;
        }
        // DFS 遍历以 x 为根的这棵 Trie 树
        traverse(x, prefix, res);
        return res;
    }

    void traverse(TrieNode<T>* node, string& path, vector<string>& res) {
        if (node == nullptr) {
            // 到达 Trie 树底部叶子结点
            return;
        }

        if (node->val != T()) {
            // 找到一个 key，添加到结果列表中
            res.push_back(path);
        }

        // 回溯算法遍历框架
        for (char c = 0; (int)c < R; c++) {
            // 做选择
            path.push_back(c);
            traverse(node->children[(int)c], path, res);
            // 撤销选择
            path.pop_back();
        }
    }

    // 判断是和否存在前缀为 prefix 的键
    // hasKeyWithPrefix("tha") -> true
    // hasKeyWithPrefix("apple") -> false
    bool hasKeyWithPrefix(string & prefix) {
        // 只要能找到一个节点，就是存在前缀
        return prefix.size() > 0 && getNode(root, prefix) != nullptr;
    }

    // 通配符 . 匹配任意字符，搜索所有匹配的键
    // keysWithPattern("t.a.") -> ["team", "that"]
    vector<string> keysWithPattern(string & pattern) {
        vector<string> res;
        string path = "";
        traverse(root, path, pattern, 0, res);
        return res;
    }

    // 遍历函数，尝试在「以 node 为根的 Trie 树中」匹配 pattern[i..]
    void traverse(TrieNode<T> * node, string& path, string& pattern, int i, vector<string>& res) {
        if (node == nullptr) {
            // 树枝不存在，即字符 pattern[i-1] 匹配失败
            return;
        }
        if (i == pattern.size()) {
            // pattern 匹配完成
            if (node->val != T()) {
                // 如果这个节点存储着 val，则找到一个匹配的键
                res.push_back(path);
            }
            return;
        }
        char c = pattern[i];
        if (c == '.') {
            // pattern[i] 是通配符，可以变化成任意字符
            // 多叉树（回溯算法）遍历框架
            for (char j = 0; (int)j < R; j++) {
                path.push_back(j);
                traverse(node->children[(int)j], path, pattern, i + 1, res);
                path.pop_back();
            }
        } else {
            // pattern[i] 是普通字符 c
            path.push_back(c);
            if (checkBound()) c = c - 'a';
            traverse(node->children[(int)c], path, pattern, i + 1, res);
            path.pop_back();
        }
    }

    // 通配符 . 匹配任意字符，判断是否存在匹配的键
    // hasKeyWithPattern(".ip") -> true
    // hasKeyWithPattern(".i") -> false
    bool hasKeyWithPattern(string & pattern) {
        return hasKeyWithPattern(root, pattern, 0);
    }

    // 函数定义：从 node 节点开始匹配 pattern[i..]，返回是否成功匹配
    bool hasKeyWithPattern(TrieNode<T> * node, string& pattern, int i) {
        if (node == nullptr) {
            // 树枝不存在，即匹配失败
            return false;
        }
        if (i == pattern.length()) {
            // 模式串走到头了，看看匹配到的是否是一个键
            return node->val != T();
        }
        char c = pattern[i];
        // 没有遇到通配符
        if (c != '.') {
            if (checkBound()) c = c - 'a';
            // 从 node.children[c] 节点开始匹配 pattern[i+1..]
            return hasKeyWithPattern(node->children[(int)c], pattern, i + 1);
        }
        // 遇到通配符
        for (int j = 0; (int)j < R; j++) {
            // pattern[i] 可以变化成任意字符，尝试所有可能，只要遇到一个匹配成功就返回
            if (hasKeyWithPattern(node->children[(int)j], pattern, i + 1)) {
                return true;
            }
        }
        // 都没有匹配
        return false;
    }

    // 返回 Map 中键值对的数量
    int size() {
        return _size;
    }

private:
    TrieNode<T> * root;
    // 当前存在 Map 中的键值对个数
    int _size;
    bool checkBound() {
        return R <= 27;
    }
};

class Trie {
public:
    Trie() {
        s = TrieMap<int>();    
    }
    
    void insert(string word) {
        s.put(word, 1);
    }
    
    bool search(string word) {
        return s.containsKey(word);
    }
    
    bool startsWith(string prefix) {
        return s.hasKeyWithPrefix(prefix);
    }

private:
    TrieMap<int> s;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */