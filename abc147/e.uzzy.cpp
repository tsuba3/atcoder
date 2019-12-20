#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<bitset>
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

const int cm = 1 << 16;
char cn[cm], * ci = cn, ct;
inline int getint() {
	int A = 0;
	while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
	return A;
}

//bitset使ったことほぼないなぁ
bitset<6500> dp1[81];

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);

    chrono::system_clock::time_point start, end, s1, s2, s3;
    start = chrono::system_clock::now();

	fread(ci, 1, cm, stdin);
	int H, W;
	H = getint(), W = getint();
	char AB[80][80];
	rep(i, H) rep(j, W) {
		AB[i][j] = getint();
	}
	rep(i, H) rep(j, W) {
		AB[i][j] = abs(AB[i][j] - getint());
	}

	dp1[0][0] = true;
	for (int hw = 0; hw <= H + W - 2; hw++) {
		for (int w = min(hw, W - 1); w >= max(0, hw - H + 1); w--) {
			int h = hw - w;
			dp1[w] |= dp1[w] << AB[h][w] * 2;
			rep1(i, AB[h][w]) dp1[w][AB[h][w] + i] = (dp1[w][AB[h][w] + i] | dp1[w][AB[h][w] - i]);
			dp1[w] >>= AB[h][w];
			dp1[w + 1] |= dp1[w];
		}
	}


	rep(i, 81) {
		if (dp1[W - 1][i]) {
			printf("%d", i);
            break;
		}
	}

    end = chrono::system_clock::now();
    double t1 = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
    cerr << t1 << '\n';
	Would you please return 0;
}

