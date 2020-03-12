// begin of lca

class LCA {
public:
    // depth[i]: distance between node i and node 0
    vector<int> depth;
    // parent[i][j]: (1 << i)th parent of node j if exists otherwise -1
    vector<vector<int>> parent2;

    LCA(const vector<vector<int>> &vec, const int root = 0) {
        depth.resize(vec.size(), -1);
        parent2.resize(1 + 8 * sizeof(int) - __builtin_clz(vec.size()));
        rep(i, parent2.size()) parent2[i].resize(vec.size(), -1);
        stack<int> dfs;
        dfs.push(root);
        depth[root] = 0;
        while (!dfs.empty()) {
            int i = dfs.top();
            dfs.pop();
            for (int j : vec[i]) if (depth[j] == -1) {
                depth[j] = depth[i] + 1;
                parent2[0][j] = i;
                dfs.push(j);
            }
        }
        rep(pi, parent2.size() - 1) {
            rep(i, vec.size()) parent2[pi + 1][i] = parent2[pi][parent2[pi][i]];
        }
    }

    int parent(int i, int n = 1) const {
        for (int pi = 0; n; ++pi, n >>= 1) if (n & 1) i = parent2[pi][i];
        return i;
    }

    int find(int a, int b) const {
        if (a == b) return a;
        int da = depth[a], db = depth[b];
        if (da > db)
            a = parent(a, da - db);
        else if (db > da)
            b = parent(b, db - da);
        if (a == b) return a;
        for (int p = (8 * sizeof(int) - __builtin_clz(min(da, db))); p >= 0; --p)
            if (parent2[p][a] != parent2[p][b]) a = parent2[p][a], b = parent2[p][b];
        return parent2[0][a];
    }
};

// end of lca
