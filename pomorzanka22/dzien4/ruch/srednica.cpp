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

constexpr int MxN = 250005;
constexpr int INF = 1e9+7;
vector<int> G[MxN];
int h[MxN], dp[MxN], l[MxN];
pii k[MxN];
int licz;

void dfs(int v, int p) {
	int mxdp_idx = 0;
	pii mxh_idx = {0, 0};
	for (auto u : G[v])
		if (u != p) {
			dfs(u, v);
			if (h[u] >= h[mxh_idx.FR]) {
				mxh_idx.SD = mxh_idx.FR;
				mxh_idx.FR = u;
			}
			else if (h[u] > h[mxh_idx.SD])
				mxh_idx.SD = u;
			if (dp[u] >= dp[mxdp_idx])
				mxdp_idx = u;
		}
		
	h[v] = max(0, h[mxh_idx.FR]) + 1;
	if (h[v] == 1) l[v] = v;
	else l[v] = l[mxh_idx.FR];
	int op1 = h[v];
	int op2 = h[mxh_idx.FR] + h[mxh_idx.SD] + 2;
	int op3 = dp[mxdp_idx];
	dp[v] = max({op1, op2, op3});
	if (dp[v] == op1)
		k[v] = {v, l[v]};
	else if (dp[v] == op2)
		k[v] = {l[mxh_idx.FR], l[mxh_idx.SD]};
	else k[v] = k[mxdp_idx];
}

void dfs2(int v, int p, int d) {
	licz += d;
	for (auto u : G[v])
		if (u != p) dfs2(u, v, d+1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<n; i++) {
		int a, b; cin >> a >> b;
		G[a].PB(b); G[b].PB(a);
	}
	
	h[0] = dp[0] = -INF;
	dfs(1, 1);
	
	int mx = -INF;
	int k1 = k[1].FR;
	int k2 = k[1].SD;
	licz = 0;
	dfs2(k1, k1, 0);
	mx = max(mx, licz);
	licz = 0;
	dfs2(k2, k2, 0);
	mx = max(mx, licz);
	cout << licz << "\n";

	return 0;
}
