// begin swag
// monoid に依存

/*
 * SWAG (Sliding-Window Aggregation Algorithms)
 * 合計を定数時間で計算できるキュー
 */
template<typename M>
class SWAG {
public:
    using MT = typename M::type;
    SWAG(): right_sum(M::unit) {}

    // O(1)
    MT get() const {
        if (left.empty())
            return right_sum;
        else
            return M::f(left[left.size() - 1].second, right_sum);
    }

    // 末尾に追加 O(1)
    void push_back(MT const m) {
        right_sum = M::f(right_sum, m);
        right.push_back(m);
    }

    // 先頭を削除 ならしO(1)
    void pop_front() {
        if (left.empty()) swap();
        left.pop_back();
    }

    int size() const {
        return left.size() + right.size();
    }

    void reserve(int const n) {
        right.reserve(n);
    }

    MT operator[](int const i) const {
        if (i >= left.size())
            return right[i - left.size()];
        else
            return left[left.size() - i - 1].first;
    }

private:
    void swap() {
        // assert(left.empty());
        const int n = right.size();
        MT sum = M::unit;
        left.reserve(n);
        right_sum = M::unit;
        rep(i, n) {
            sum = M::f(right[n - i - 1], sum);
            left.emplace_back(make_pair(right[n - i - 1], sum));
        }
        right.clear();
    }

    vector<pair<MT, MT>> left;
    vector<MT> right;
    MT right_sum;
};

// end swag

