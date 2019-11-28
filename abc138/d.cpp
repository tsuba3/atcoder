#include <iostream>
#include <vector>

using namespace std;

void dfs(int i, vector<int>* res, vector<vector<int> >* vec) {
    for (const auto& j : (*vec)[i]) {
        (*res)[j] += (*res)[i];
        dfs(j, res, vec);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int> > vec (n, vector<int>(0));
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        vec[a-1].push_back(b-1);
    }
    vector<int> res(n, 0);
    for (int i = 0; i < q; ++i) {
        int j, x;
        cin >> j >> x;
        res[j-1] += x;
    }

    dfs(0, &res, &vec);

    for (auto it = res.begin(); it < res.end() - 1; ++it) {
        cout << *it << " ";
    }
    cout << res.back() << endl;

    return 0;
}


