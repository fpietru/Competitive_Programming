/*
	Link: https://atcoder.jp/contests/agc023/tasks/agc023_b
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__) // debugging /*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename ...Args> void logger(string vars, Args&&... values) { cout<<"[ "<<vars<<" = "; string delim=""; (..., (cout<<delim<<values, delim=", ")); cout <<" ]\n"; }
/**/

constexpr int MxN = 606;
ll p[2] = {31LL, 37LL};
constexpr ll MOD = 1e9+7;
char tab[MxN][MxN];
ll h[2][2][MxN][MxN];
ll ppow[2][MxN];

ll Hash(int pos, int a, int b, int k, int o) {
	ll A = (h[k][o][pos][a-1] * ppow[k][b-a+1]) % MOD;
	ll H = (h[k][o][pos][b] - A + MOD) % MOD;
	return H;
}

bool symetryczny(int y, int x, int n) {
	for (int i=y; i<=y+n; i++) {
		int h1poziomy = Hash(i, x, x+n-1, 0, 0);
		int h2poziomy = Hash(i, x, x+n-1, 1, 0);
		int h1pionowy = Hash(x+(i-y), y, y+n-1, 0, 1);
		int h2pionowy = Hash(x+(i-y), y, y+n-1, 1, 1);		
		if ((h1poziomy == h1pionowy) && (h2poziomy == h2pionowy)) continue;
		else return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) {
			char c; cin >> c;
			tab[i][j] = tab[i+n][j] = tab[i][j+n] = tab[i+n][j+n] = c;
	}
	
	for (int k=0; k<2; k++) {
		ppow[k][0] = 1;
		for (int i=1; i<=n; i++)
			ppow[k][i] = (ppow[k][i-1] * p[k]) % MOD;
	}
	
	for (int i=1; i<=2*n; i++)
		for (int j=1; j<=2*n; j++)
			for (int k=0; k<2; k++)
				h[k][0][i][j] = (h[k][0][i][j-1] * p[k] + (tab[i][j]-'a'+1)) % MOD;
	
	for (int j=1; j<=2*n; j++)
		for (int i=1; i<=2*n; i++)
			for (int k=0; k<2; k++)
				h[k][1][j][i] = (h[k][1][j][i-1] * p[k] + (tab[i][j]-'a'+1)) % MOD;

	int ans = 0;
	for (int i=1; i<=n; i++)
		if (symetryczny(i, 1, n)) ans += n;
	
	cout << ans << "\n";
	
	return 0;
}
