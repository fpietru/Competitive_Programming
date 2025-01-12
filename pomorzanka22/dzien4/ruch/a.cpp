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
vector<int> G[MxN];
int rozmiar[MxN];
int centroid;
int ile[MxN];
int dp[MxN];
int n;

void dfs(int v, int p) {
	rozmiar[v] = 1;
	for (auto u : G[v])
		if (u != p) {
			dfs(u, v);
			rozmiar[v] += rozmiar[u];
		}
	int mx = n - v[rozmiar];
	for (auto u : G[v])
		if (u != p) mx = max(mx, rozmiar[u]);
	if (2*mx <= n) centroid = v;
}

ll dfs2(int v, int p, int d) {
	rozmiar[v] = 1;
	ll res = (ll)d;
	for (auto u : G[v])
		if (u != p) {
			res += dfs2(u, v, d+1);
			rozmiar[v] += rozmiar[u];
		}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i=1; i<=n-1; i++) {
		int a, b; cin >> a >> b;
		G[a].PB(b); G[b].PB(a);
	}
	dfs(1, 1);
	
	ll sumapar = 0LL;
	memset(rozmiar, 0, sizeof(rozmiar));
	for (auto u : G[centroid]) {
		sumapar += dfs2(u, centroid, 0);
		ile[rozmiar[u]]++;
	}
	
	vector<int> vec;
	for (int x=1; x<=n-1; x++) {
		while (ile[x] >= 3) {
			ile[x] -= 2;
			ile[2*x]++;
		}
		while (ile[x]--)
			vec.PB(x);
	}
	
	dp[0] = 1;
	for (auto x : vec)
		for (int i=n-1; i>=x; i--)
			dp[i] |= dp[i-x];
			
	int polowa = (n-1) / 2;
	while (!dp[polowa]) polowa++;	
		
	ll iloczyn = (ll)polowa*(n-1-polowa);
	ll ans = iloczyn + sumapar + (ll)(n-1);

	cout << n-1 << " " << ans << "\n";

	return 0;
}
