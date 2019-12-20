#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please

//みなさん天才すぎないすか

const int cm = 6000000;
char cn[cm], * ci = cn, ct;
inline char getcha() {
	return *ci++;
}
inline ll getint() {
	ll A = 0;
	if (ci - cn + 24 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';
	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
	return A;
}


int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);

    chrono::system_clock::time_point start, end, s1, s2, s3;
    start = chrono::high_resolution_clock::now();
    cin.read(cn, sizeof cn);
    s1 = chrono::system_clock::now();

	int N = getint();
	ll kazu[20] = {};
	const int mod = 1e9 + 7;
	const ll m = 1 + (1 << 20) + (1ll << 40);
	//なんではやいのかな？ブロック化的な奴なの？
	rep(i, N / 2) {
		ll a = getint();
		ll b = getint();
		rep(j, 20) {
			kazu[j] += a >> j & m;
			kazu[j] += b >> j & m;
		}
	}
	rep(i, N % 2) {
		ll a = getint();
		rep(j, 20) kazu[j] += a >> j & m;
	}

    s2 = chrono::system_clock::now();

	ll kotae = 0;
	const ll m2 = (1 << 20) - 1;
	rep(j, 20) {
		ll tmp = (1ll << j) % mod;
		ll tmpk = (kazu[j] & m2);
		tmpk = tmpk * (N - tmpk) % mod;
		kotae += tmp * tmpk % mod;

		tmp = (1ll << (j + 20)) % mod;
		tmpk = (kazu[j] >> 20 & m2);
		tmpk = tmpk * (N - tmpk) % mod;
		kotae += tmp * tmpk % mod;

		tmp = (1ll << (j + 40)) % mod;
		tmpk = (kazu[j] >> 40 & m2);
		tmpk = tmpk * (N - tmpk) % mod;
		kotae += tmp * tmpk % mod;
	}

	printf("%lld\n", kotae% mod);

    end = chrono::system_clock::now();
    
    double t1 = static_cast<double>(chrono::duration_cast<chrono::microseconds>(s1 - start).count() / 1000.0);
    double t2 = static_cast<double>(chrono::duration_cast<chrono::microseconds>(s2 - s1).count() / 1000.0);
    double t3 = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end -s2).count() / 1000.0);
    double t = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
    fprintf(stderr, "%.3fms %.3fms %.3fms %.3fms\n", t1, t2, t3, t);
    

	Would you please return 0;
}

