/*                         _
                        _ooOoo_
                       o8888888o
                       88" . "88
                       (| -_- |)
                       O\  =  /O
                    ____/`---'\____
                  .'  \\|     |//  `.
                 /  \\|||  :  |||//  \
                /  _||||| -:- |||||_  \
                |   | \\\  -  /'| |   |
                | \_|  `\`---'//  |_/ |
                \  .-\__ `-. -'__/-.  /
              ___`. .'  /--.--\  `. .'___
           ."" '<  `.___\_<|>_/___.' _> \"".
          | | :  `- \`. ;`. _/; .'/ /  .' ; |
          \  \ `-.   \_\_`. _.'_/_/  -' _.' /
===========`-.`___`-.__\ \___  /__.-'_.'_.-'================

                  Please give me AC.
*/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include <complex>
#include <bitset>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <chrono>
#include <random>

using namespace std;

using int64 = long long;
using uint64 = unsigned long long;
using vi = vector<int>;
using vl = vector<int64>;
using pii = pair<int, int>;
using pll = pair<int64, int64>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
#define print(x) cout << (x) << '\n'
#define print2(x, y) cout << (x) << ' ' << (y) << '\n'
#define print3(x, y, z) cout << (x) << ' ' << (y) << ' ' << (z) << '\n'
#define printn(v) rep(i, (v).size() - 1) cout << (v)[i] << ' '; cout << (v)[n - 1] << '\n';
#define debug(x) cerr << #x << ": " << (x) << '\n'
#define debug2(x, y) cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << '\n'
#define debug3(x, y, z) cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << ", " << #z << ": " << (z) << '\n'
#define dbg(v) for (size_t _ = 0; _ < v.size(); ++_){cerr << #v << "[" << _ << "] : " << v[_] << '\n';}
// constant
const int INF = (1<<30) - 1;
const int64 INF64 = (1LL<<62) - 1;

template<typename T> T gcd(T a, T b) {
    if (a < b) return gcd(b, a);
    T r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

template<typename T> T lcm(const T a, const T b) {
    return a / gcd(a, b) * b;
}

template<typename T> bool chmin(T& a, const T& b) {
    if (a > b) return a = b, true; else return false;
}

template<typename T> bool chmax(T& a, const T& b) {
    if (a < b) return a = b, true; else return false;
}

// End of template.

constexpr int8_t A = 0;
constexpr int8_t B = 1;
constexpr int8_t C = 2;

vector<int8_t> ans;

int8_t other(int8_t a, int8_t b) {
    if (b > a) swap(a, b);
    if (a == A && b == B) return C;
    if (a == A && b == C) return B;
    if (a == B && b == C) return A;
}

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin.read(buf, sizeof buf); // 注意: ./a.out < in か pbp | ./a.out で入力すること

    int n, a, b, c;
    int8_t s[100100];
    cin >> n >> a >> b >> c;
    rep(i, n) {
        string str;
        cin >> str;
        if (str == "AB")
            s[i] = C;
        else if (str == "BC")
            s[i] = A;
        else
            s[i] = B;
    }

    if (a + b + c == 0) {
        print("No");
        return 0;
    }

    if (a + b + c == 1) {
        bool ok = true;
        ans.resize(n);
        rep(i, n) {
            if ((s[i] == A && a == 1) || (s[i] == B && b == 1) || (s[i] == C && c == 1)) ok = false;
            if (s[i] == A) {
                if (b == 0) ans[i] = B;
                else ans[i] = c;
            } else if (s[i] == B) {
                if (a == 0) ans[i] = A;
                else ans[i] = C;
            } else { // s[i] == C
                if (a == 0) ans[i] = A;
                else ans[i] = B;
            }
        }
        if (ok) {
            print("Yes");
            rep(i, n) print(char(ans[i] + 'A'));
        } else {
            print("No");
        }
        return 0;
    }

    // a + b + c >= 2
    int8_t zero, two;
    ans.reserve(n);
    if (a > 0 && b > 0 && c > 0) {
        a = 1, b = 1, c = 0;
        zero = C, two = -1;
    } else if ((a == 0) + (b == 0) + (c == 0) == 2) {
        if (a > 0) a = 2, two = A;
        if (b > 0) b = 2, two = B;
        if (c > 0) c = 2, two = C;
        if ((s[0] == A && a > 0) || (s[0] == C && c > 0) || (s[0] == B && b > 0)) {
            print("No");
            return 0;
        }
        zero = -1;
    } else {
        a = a > 0;
        b = b > 0;
        c = c > 0;
        two = -1;
        if (a == 0) zero = A;
        else if (b == 0) zero = B;
        else zero = C;
    }
    // Must be ok
    int i = 0;
    for (i = 0; i < n - 1; ++i) {
        if (two != -1) {
            if (two == A) {
                if (s[i] == B) ans.push_back(C);
                else ans.push_back(B);
            } else if (two == B) {
                if (s[i] == A) ans.push_back(C);
                else ans.push_back(A);
            } else { // two == C
                if (s[i] == A) ans.push_back(B);
                else ans.push_back(C);
            }
            two = -1;
            if (a == 0) zero = A;
            if (b == 0) zero = B;
            if (c == 0) zero = C;
        } else {
            if (zero != s[i]) {
                ans.push_back(zero);
                zero = other(zero, s[i]);
            } else {
                if (s[i] == s[i + 1]) {
                    ans.push_back((s[i] + 1) % 3);
                    ans.push_back((s[i] + 1) % 3);
                    i += 1;
                } else {
                    ans.push_back(other(s[i], s[i + 1]));
                    two = other(s[i], s[i + 1]);
                    zero = -1;
                }
            }
        }
    }

    if (i < n) {
        if (two == -1) {
            if (zero == s[i]) ans.push_back((s[i] + 1) % 3);
            else ans.push_back(zero);
        } else {
            ans.push_back(two);
        }
    }

    print("Yes");
    for (auto x : ans) {
        print(char(x + 'A'));
    }

    return 0;
}

