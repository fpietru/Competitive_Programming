#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__) // debugging 
/*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename ...Args> void logger(string vars, Args&&... values) { cout<<"[ "<<vars<<" = "; string delim=""; (..., (cout<<delim<<values, delim=", ")); cout <<" ]\n"; }
/**/

constexpr int MxN = 2022;
constexpr ll MOD = 1e9+7;
ll tab[MxN][MxN];
ll p[MxN][MxN];
int offset, n, m, q;

void genspirale() {
	ll val = 1LL;
	int y = offset;
	int x = offset;
	int dl = 0;
	int i = 1;
	ll kroki = 0;
	int limit = m*m;
	while (true) {
		if (i == 1 || i == 3) dl++;
		for (int j=1; j<=dl; j++) {
			tab[y][x] = val++;
			kroki++;
			if (kroki >= limit)
				return;
			if (i == 1) x++;
			else if (i == 2) y--;
			else if (i == 3) x--;
			else y++;
		}
		i++;
		if (i > 4) i -= 4;
	}
}

int query(int x1, int y1, int x2, int y2) {
	pii A = {m-(y1 + offset)+1, x1 + offset};
	pii C = {m-(y2 + offset)+1, x2 + offset};
	pii B = {A.FR, C.SD};
	pii D = {C.FR, A.SD};
	
	ll res = p[B.FR][B.SD];
	res = (res - p[A.FR][A.SD-1] + MOD);
	res = (res - p[C.FR-1][C.SD] + MOD);
	res = (res + p[D.FR-1][D.SD-1]);
	while (res >= MOD) res -= MOD;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> q;
	offset = n+1;
	m = 2*n+1;
	genspirale();
		
	for (int i=1; i<=m; i++)
		for (int j=1; j<=m; j++) {
			p[i][j] = tab[i][j];
			p[i][j] = (p[i][j] + p[i-1][j]);
			p[i][j] = (p[i][j] + p[i][j-1]);
			p[i][j] = (p[i][j] - p[i-1][j-1] + MOD);
			while (p[i][j] >= MOD) p[i][j] -= MOD;	
		}
	
	while (q--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		ll ans = query(x1, y1, x2, y2);
		cout << ans << "\n";
	}

	return 0;
}
