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

constexpr int MxN = 22;
constexpr int INF = 1e9+7;
vector<pii> G[MxN];
ll wart[MxN];
ll rozmiar;
bool vis[MxN];
ll k;
int maska;

void dfs(int v, int from) {
	// deb(v, from);
	vis[v] = true;
	rozmiar += wart[v];
	for (auto e : G[v])
		if (!vis[e.FR] && ((maska&(1<<e.SD)) == false))
			dfs(e.FR, from); 
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n >> k;
	for (int i=1; i<=n; i++) cin >> wart[i];
	for (int i=0; i<n-1; i++) {
		int a, b; cin >> a >> b;
		G[a].PB({b, i});
		G[b].PB({a, i});
	}
	
	int best = INF;
	for (maska=0; maska<(1<<n); maska++) {
		memset(vis, 0, sizeof(vis));
		bool ok = 1;
		for (int i=1; i<=n; i++)
			if (!vis[i]) {
				rozmiar = 0LL;
				dfs(i, i);
				ok &= (rozmiar <= k);
			}
		// deb(maska, ok);
		if (ok) {
			best = min(best, __builtin_popcount(maska));
		}
	}
	
	cout << best << "\n";

	return 0;
}
