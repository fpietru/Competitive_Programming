/*
	Link: https://codeforces.com/contest/440/problem/D
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

constexpr int MxN = 404;
constexpr int INF = 1e9+7;
vector<int> G[MxN];
int dp[MxN][MxN];
int dp2[MxN][MxN][MxN];
int par[MxN];
int krawedz[MxN][MxN];
int n, k;

void dfs(int v, int p=0) {
	par[v] = p;
	dp[v][0] = 1;
	dp[v][1] = 0;
	for (int i=2; i<=k; i++)
		dp[v][i] = INF;
	for (int s=0; s<(int)G[v].size(); s++)
		if (G[v][s] != p) {
			int u = G[v][s];
			dfs(u, v);
			for (int i=k; i>=1; i--) {
				int tmp = INF;
				for (int j=0; j<i; j++) {			
					if (tmp > dp[v][i-j] + dp[u][j]) {
						tmp = dp[v][i-j] + dp[u][j];
						dp2[v][i][s] = j;
					}
				}
				dp[v][i] = tmp;
			}
		}
}

void dfs2(int v, int sz, int p) {
	for (int s=G[v].size()-1; s>=0; s--)
		if (G[v][s] != p) {
			int u = G[v][s];
			if (dp2[v][sz][s] == 0) cout << krawedz[v][u] << " ";
			else dfs2(u, dp2[v][sz][s], v);
			sz -= dp2[v][sz][s];
		}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i=1; i<=n-1; i++) {
		int a, b; cin >> a >> b;
		G[a].PB(b); G[b].PB(a);
		krawedz[a][b] = krawedz[b][a] = i;
	}
	dfs(1);
	
	int ans = INF, root = 1;
	for (int i=1; i<=n; i++) {
		int w = dp[i][k] + (i != 1);
		if (ans > w) {
			ans = w;
			root = i;
		}
	}

	cout << ans << "\n";
	if (root != 1) cout << krawedz[root][par[root]] << " ";
	dfs2(root, k, par[root]);
	cout << "\n";

	return 0;
}
