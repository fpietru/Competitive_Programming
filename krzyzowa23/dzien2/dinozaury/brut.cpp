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

constexpr int MxN = 2e5+5;
vector<int> G[2][MxN];
vector<pii> kraw[2][MxN];
int ojciec[2][MxN];
int pre[2][MxN];
int post[2][MxN];
int licznik = 0;

void dfs(int v, int p, int k) {
	pre[k][v] = ++licznik;
	for (auto u : G[k][v])
		if (u != p)
			dfs(u, v, k);
	post[k][v] = ++licznik;
}

// czy a jest przodkiem b
bool przodek(int a, int b, int k) {
	if (pre[k][a] < pre[k][b] && post[k][b] < post[k][a])
		return true;
	return false;
}

ll zapytanie(int a, int b) {
	ll res = 0LL;
	while (a) {
		for (auto it : kraw[0][a]) {
			if (przodek(it.FR, b, 1) || it.FR == b)			
				res += it.SD;
		}
		a = ojciec[0][a];
	}
	return res;
}

int main() {
	// ios_base::sync_with_stdio(0);
	// cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=2; i<=n; i++) {
		int x; cin >> x;
		ojciec[0][i] = x;
		G[0][x].PB(i);
		G[0][i].PB(x);
	}
	int m; cin >> m;
	for (int i=2; i<=m; i++) {
		int x; cin >> x;
		ojciec[1][i] = x;
		G[1][x].PB(i);
		G[1][i].PB(x);
	}
	
	dfs(1, 1, 0);
	licznik = 0;
	dfs(1, 1, 1);
	
	// cout << "done\n";
	
	int k; cin >> k;
	for (int i=1; i<=k; i++) {
		int a, b, x; cin >> a >> b >> x;
		kraw[0][a].PB({b, x});
		kraw[1][b].PB({a, x});	
	}

	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		// deb(a, b);
		cout << zapytanie(a, b) << "\n";
	}	

	return 0;
}
