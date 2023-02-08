class UF {
public:
    UF(int n) {
        count = n;
        parent = vector<int>(n);
        for (int i = 0; i < n; i ++) {
            parent[i] = i;
        }
    }

    void union_(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;
        parent[rootP] = rootQ;
        count -= 1;
    }

    bool connect(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    int getCount() {
        return count;
    }

private:
    int count;
    vector<int> parent;
};


class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UF uf(26);
        for (string s: equations) {
            if (s[1] == '=') {
                uf.union_(s[0]-'a', s[3]-'a');
            }
        }

          for (string s: equations) {
            if (s[1] == '!') {
                if (uf.connect(s[0]-'a', s[3]-'a')) return false;
            }
        }
        return true;
    }
};