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

#pragma GCC optimize ("O3")
#pragma GCC target ("avx")

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

// begin fast io

char buf[10000000];
int bufi = 0;

template<typename T>
void readi(T &n) {
    bool negative = false;
    if (buf[bufi] == '-') negative = true, bufi++, readui(n);
    if (negative) n = -n;
}

template<typename T>
void readui(T &n) {
    n = 0;
    int c = buf[bufi++];
    for (; '0' <= c && c <= '9'; c = buf[bufi++])
        n = 10 * n + c - '0';
}

template<typename T>
void readf(T &x) {
    bool negative = false;
    if (buf[bufi] == '-') negative = true, bufi++, readuf(x);
    if (negative) x = -x;
}

template<typename T>
void readuf(T &x) {
    x = 0;
    T y = 0;
    int z = 0;
    int c = buf[bufi++];
    for (; '0' <= c && c <= '9'; c = buf[bufi++])
        x = 10 * x + c - '0';
    if (buf[bufi - 1] == '.')
        for (; '0' <= c && c <= '9'; c = buf[bufi++], ++z)
            y = 10 * y + c - '0';
    x += y / pow(10, z);
}

void reads(string &s) {
    const int begin = bufi;
    int c;
    while (c = buf[bufi++], c != ' ' && c != '\n') {}
    s = string(buf + begin, buf + bufi);
}

void readline(string &s) {
    const int begin = bufi;
    while (buf[bufi++] != '\n') {}
    s = string(buf + begin, buf + bufi);
}

// end fast io

constexpr int64 mod = 1e9 + 7;

// Begin Mod
template<typename T, T mod_, bool is_prime = true>
class Mod {
public:
    using Self = Mod<T, mod_, is_prime>;
    T value;
    static constexpr T mod = mod_;
    Mod() { value = 0; }
    Mod(T x) { value = x % mod; }
    explicit operator T&() { return value; }
    Self operator +(Self const x) const { return (value + x.value) % mod; }
    Self operator *(Self const x) const { return (value * x.value) % mod; }
    Self operator -(Self const x) const { return (mod + value - x.value) % mod; }
    Self operator /(Self const x) const { return (value * x.inv().value) % mod; }
    Self operator +=(Self const x) { return value = (value + x.value) % mod; }
    Self operator *=(Self const x) { return value = (value * x.value) % mod; }
    Self operator -=(Self const x) { return value = (mod + value - x.value) % mod; }
    Self operator /=(Self const x) { return value = (value * x.inv().value) % mod; }
    Self inv() const {
        T a = value, b = mod, u = 1, v = 0;
        while (b) {
            T t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        u %= mod;
        if (u < 0) u += mod;
        return u;
    }
    Self pow(int e) const {
        if (e < 0) return inv().pow(-e);
        if (is_prime) e %= mod - 1;
        Self base = value;
        Self res = 1;
        while (e > 0) {
            if (e & 1) res *= base;
            base *= base;
            e >>= 1;
        }
        return res;
    }
};
// End Mod

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.read(buf, sizeof buf); // 注意: ./a.out < in か pbp | ./a.out で入力すること

    using M = Mod<int64, mod>;
    int n, x[100100];
    readui(n);
    rep(i, n) readui(x[i]);

    // 320 * 320 = 102400 >= max n
    M dp[100100];
    M ans = M(0);
    M fact320 = {1, 44958071, 196613531, 456965253, 82258458, 19055157, 199641625, 830056839, 886901539, 394888900, 406550952, 26900221, 263414257, 200606103, 547295935, 764072301, 690746858, 342496964, 326432270, 192170249, 380720579, 799791202, 123748935, 415553083, 141007414, 532467852, 147096971, 90740529, 154524818, 900070389, 747441725, 701751088, 558164830, 817355242, 95025579, 830834436, 194511721, 192605468, 900934185, 79854831, 342781022, 407433729, 15890774, 765961428, 740048935, 854869794, 499694985, 545349485, 916372711, 756802411, 317614965, 90300589, 326141415, 638122678, 399214770, 412197753, 577373655, 844482667, 181299979, 162247064, 224496577, 75084663, 458352393, 236783177, 960011178, 425401251, 356638183, 815089937, 827974383, 222096357, 343383160, 85941754, 887317787, 863455079, 481532232, 965651681, 568895364, 763704802, 785070920, 655075019, 685687553, 656972446, 36892359, 619562099, 275808713, 687272398, 341872267, 329910695, 579658741, 858908716, 320822040, 24451933, 218024449, 557044204, 712604144, 414973328, 138616501, 549172330, 82239619, 75337821, 200360748, 412050217, 13150110, 168263741, 264275448, 455285322, 679362335, 588217533, 230219619, 762492492, 834011569, 816701442, 649008795, 43703854, 924834452, 482209772, 486896800, 817578760, 959134557, 150672576, 658072182, 599685132, 691921093, 437349724, 170542482, 422550956, 383066370, 697479862, 779906992, 299353772, 619362396, 960004529, 727993766, 909729362, 720979321, 722446075, 219187421, 789119233, 644802630, 203668395, 313235165, 3609591, 681184874, 269125471, 889761575, 138938342, 482251234, 453299299, 348204933, 736637467, 473058849, 874349548, 968045038, 807052966, 493109637, 345366515, 662644378, 970515513, 599884013, 966619079, 110949981, 842802756, 339633465, 750530592, 943120718, 231821182, 399978241, 210746347, 987401742, 156518168, 354410308, 864761462, 123083599, 584931037, 216309966, 307636910, 54240893, 699337033, 953719875, 982560442, 562494885, 846981420, 855596445, 691068764, 457819814, 73700185, 341222766, 321148722, 770530590, 229859992, 189099472, 897422349, 590237245, 872486812, 781865101, 788127248, 608542011, 683950442, 859800981, 563551532, 616292959, 358431173, 699207388, 159581133, 42057171, 749373796, 943351165, 131767041, 74775714, 864312582, 258598151, 489995022, 307438277, 910275705, 590574561, 334038704, 442853004, 288661023, 698586962, 416048849, 274952061, 154223714, 268407490, 564211227, 434888300, 604632373, 319238945, 440413159, 239095364, 934442976, 554131598, 496995335, 734000767, 899063448, 311168089, 269610437, 618109396, 868360986, 94357562, 249359516, 666808812, 667154274, 757769131, 636533310, 230114340, 167897791, 675926194, 434875373, 964166813, 837855463, 65533322, 820211966, 256395389, 90392441, 868643945, 355862327, 324433771, 499165214, 746481142, 211722478, 775373984, 143886676, 794363909, 308086793, 544474756, 669701582, 304397084, 433205368, 979144269, 372917940, 866978149, 583231782, 472625466, 42942463, 158920228, 19122513, 721793026, 372992740, 730528462, 741002796, 811802215, 163489874, 744406313, 350446076, 952944478, 394225159, 261193596, 89066910, 855456001, 748599559, 784373520, 199253314, 424761510, 634588682, 761175927, 37693984, 655241078, 810275002, 344083848, 631917044, 318526308, 724599065, 764042647, 452854888, 450077038, 367421824, 511618861, 333890904, 917636185, 800562158, 671417846, 314997922, 75551356, 725546667, 396216980, 530581311, 760743532, 123438942, 324293939, 264617017, 783112758, 589360325};
    M fact = M(1);
    rep(i, n - 1) {
        dp[i + 1] = dp[i] * (i + 1) + fact;
        fact *= (i + 1);
    }

    fact = M(1);
    for (int i = n - 1; i >= 1; --i) {
        ans += dp[i] * fact * (x[i] - x[i - 1]);
        fact *= i;
    }

    print(ans.value);


    return 0;
}

