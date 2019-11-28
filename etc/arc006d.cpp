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
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include <complex>
#include <array>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;

using int64 = long long;
using uint64 = unsigned long long;
using vi = vector<int>;
using vl = vector<int64>;
using pii = pair<int, int>;


#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
#define print(x) cout << (x) << '\n'
#define debug(x) cerr << #x << ": " << (x) << '\n'
#define dbg(v) for (size_t _ = 0; _ < v.size(); ++_){cerr << #v << "[" << _ << "] : " << v[_] << '\n';}
// constant
const int INF = (1<<30) - 1;
const int64 INF64 = (1LL<<62) - 1;

int h, w;
bool s[1010][1010];
int sum[1010][1010];
bool used[1010][1010];
bool a[4][7][7];
bool b[4][7][7];
bool c[4][7][7];
int suma = 12;
int sumb = 16;
int sumc = 11;

void parse(array<string, 7> s, bool x[7][7]) {
    rep(hi, 7) rep(wi, 7) {
        x[hi][wi] = char(s[hi][wi]) == char('o');
    }
}

void rotate(bool src[7][7], bool dist[7][7]) {
    rep(wi, 7) rep(hi, 7) {
        dist[6 - wi][hi] = src[hi][wi];
    }
}

bool match(int sh, int sw, int scale, bool x[7][7]) {
    rep(hi, 7) rep(wi, 7) rep(hs, scale) rep(ws, scale) {
        if (s[sh + scale * hi + hs][sw + scale * wi + ws] != x[hi][wi]) {
            return false;
        }
    }
    return true;
}

bool match_one(int sh, int sw, int scale, bool x[4][7][7]) {
    cerr << "match: " << sh << ' ' << sw << ' ' << scale << '\n';
    rep(i, 4) {
        if (match(sh, sw, scale, x[i])) return true;
    }
    return false;
}

int main(){
    cout << fixed << setprecision(15);

    cin >> h >> w;
    cin.get();
    rep(hi, h) {
        rep(wi, w) {
            s[hi][wi] = cin.get() == int('o');
        }
        cin.get();
    }
    parse(array<string, 7>{"       ", "   o   ", "  o o  ", " o   o ", " ooooo ", " o   o ", "       "}, a[0]);
    parse(array<string, 7>{"       ", " oooo  ", " o   o ", " oooo  ", " o   o ", " oooo  ", "       "}, b[0]);
    parse(array<string, 7>{"       ", "  ooo  ", " o   o ", " o     ", " o   o ", "  ooo  ", "       "}, c[0]);
    rep(i, 3) {
        rotate(a[i], a[i+1]); rotate(b[i], b[i+1]); rotate(c[i], c[i+1]); 
    }

    rep(hi, h) {
        int sumw = 0;
        rep(wi, w) {
            sum[hi][wi] = sumw + (s[hi][wi] ? 1 : 0);
            sumw = sum[hi][wi];
            if (h > 0) sum[hi][wi] += sum[hi - 1][wi];
        }
    }

    rep(hi, h + 1) { rep(wi, w + 1) cerr << setw(3) << sum[hi][wi]; cerr << '\n'; }
    
    int ansa = 0, ansb = 0, ansc = 0;

    memset(used,  0, 1010*1010);
    for(int scale = 1; scale < 1001 / 7; scale++) rep(hi, h - scale * 7 + 1) rep(wi, w - scale * 7 + 1) {
        if (used[hi][wi] || used[hi+7][wi+7]) continue;
        int s = sum[hi + 7 * scale - 1][wi + 7 * scale - 1]
            - sum[hi][wi + 7 * scale - 1]
            - sum[hi+7*scale - 1][wi]
            + sum[hi][wi];
        bool matched = false;
        if (s == scale * scale * suma && match_one(hi, wi, scale, a)) {matched = true; ansa++;}
        if (s == scale * scale * sumb && match_one(hi, wi, scale, b)) {matched = true; ansb++;}
        if (s == scale * scale * sumc && match_one(hi, wi, scale, c)) {matched = true; ansc++;}
        if (matched) {
            for (int hii = hi; hii < hi + 7 * scale; hii++) {
                for (int wii = wi; wii < wi + 7 * scale; wii++) {
                    used[hii][wii] = true;
                }
            }
        }
    }
    
    cout << ansa << ' ' << ansb << ' ' << ansc << endl;

    // rep(i, 4) rep(hi, 7){ rep(wi, 7) cerr << (b[i][hi][wi] ? 'x' : ' '); cerr << '\n'; }

    return 0;
}

