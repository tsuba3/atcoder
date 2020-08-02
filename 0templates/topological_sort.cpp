// begin topological sort

// トポロジカル・ソートした順位を返す O(V + E)
// 閉路がある場合は空の vector を返す
// V は vector<vector<int>> と同等であること。
template<typename V>
vector<int> topological_sort(const V& edge, int n) {
    vector<int> incnt(n);
    stack<int> stack;
    vector<int> res(n);
    rep(i, n) {
        incnt[i] = edge[i].size();
        if (edge[i].size() == 0) stack.push(i);
    }

    int k = 0;
    while (!stack.empty()) {
        int i = stack.top();
        stack.pop();
        res[i] = k++;
        for (int j : edge[i]) if (--incnt[j] == 0) stack.push(j);
    }
    if (k == n) {
        return res;
    } else {
        return {};
    }
}

// end topological sort
