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

constexpr int MxN = 5e4+4;
vector<int> G[MxN], tG[MxN], sG[MxN];
bitset<MxN> dp[MxN];
queue<int> Q;
stack<int> S;
int deg[MxN], ssc[MxN];
bool vis[MxN];
int ile_ssc;

void dfs(int v) {
	vis[v] = 1;
	for (auto u : G[v])
		if (!vis[u]) dfs(u);
	S.push(v);
}

void dfs2(int v) {
	ssc[v] = ile_ssc;
	for (auto u : tG[v])
		if (!ssc[u]) dfs2(u);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m, q; cin >> n >> m >> q;
	for (int i=1; i<=m; i++) {
		int a, b; cin >> a >> b;
		G[a].PB(b);
		tG[b].PB(a);
	}
	for (int v=1; v<=n; v++)
		if (!vis[v]) dfs(v);
	while (!S.empty()) {
		int v = S.top(); S.pop();
		if (!ssc[v]) {
			ile_ssc++;
			dfs2(v);
		}
	}
	for (int v=1; v<=n; v++)
		for (auto u : G[v])
			if (ssc[v] != ssc[u]) {
				sG[ssc[v]].PB(ssc[u]);
				deg[ssc[u]]++;	
			}
	for (int i=1; i<=ile_ssc; i++)
		if (deg[i] == 0) Q.push(i);
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		dp[v][v] = 1;
		for (auto u : sG[v]) {
			dp[u] |= dp[v];
			deg[u]--;
			if (deg[u] == 0)
				Q.push(u);
		}
	}
	while (q--) {
		int a, b; cin >> a >> b;
		cout << (dp[ssc[b]][ssc[a]] ? "TAK\n" : "NIE\n");
	}

	return 0;
}
