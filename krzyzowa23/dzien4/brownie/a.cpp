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

constexpr int MxN = 3e5+5;
constexpr int INF = 1e9+7;
vector<int> G[MxN];
vector<int> sciezka;
int dp[MxN];
pii pomin;

int dfs0(int v, int p, int x) {
	bool jestem = false;
	for (auto u : G[v])
		if (u != p) {
			if (dfs0(u, v, x)) {
				sciezka.PB(u);
				jestem = true;
			}
		}
	return (v == x || jestem);
}

void dfs(int v, int p) {
	vector<int> synowie;
	for (auto u : G[v])
		if (u != p && (make_pair(v, u) != pomin && make_pair(u, v) != pomin)) {
			dfs(u, v);
			synowie.PB(dp[u]);
		}
	sort(synowie.begin(), synowie.end(), greater<int>());
	int czekam = 1;
	for (auto it : synowie) {
		dp[v] = max(dp[v], it+czekam);
		czekam++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, x, y; cin >> n >> x >> y;
	for (int i=1; i<=n-1; i++) {
		int a, b; cin >> a >> b;
		G[a].PB(b); G[b].PB(a);
	}
	
	dfs0(y, y, x);
	sciezka.PB(y);
	int sz = sciezka.size();
	
	int low = 0;
	int high = sz-2;
	
	int best = INF;
	for (int i=1; i<=20; i++) {
		for (int j=1; j<=n; j++)
			dp[j] = 0;
		int mid = (low + high) >> 1;
		pomin = {sciezka[mid], sciezka[mid+1]};
		dfs(x, x); dfs(y, y);
	
		best = min(best, max(dp[x], dp[y]));
		
		if (low == mid && mid == high)
			break;
		
		// deb(low, mid, high, pomin, dp[x], dp[y]);
		if (dp[x] < dp[y])
			low = min(mid + 1, sz-2);
		else high = mid;
	}
	
	cout << best << "\n";

	return 0;
}
