/*
	Link: https://codeforces.com/contest/1737/problem/D
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

constexpr int MxN = 505;
constexpr ll INF = 1e18+7;
ll krawedz[MxN][MxN];
ll dist[MxN][MxN];

void reset(int n) {
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) {
			if (i == j) dist[i][j] = dist[j][i] = krawedz[i][j] = krawedz[j][i] = 0LL;
			else dist[i][j] = dist[j][i] = krawedz[i][j] = krawedz[j][i] = INF;
		}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		reset(n);
		for (int i=1; i<=m; i++) {
			int a, b, w; cin >> a >> b >> w;
			krawedz[a][b] = krawedz[b][a] = min(krawedz[a][b], 1LL * w);
			dist[a][b] = dist[b][a] = 1;
		}
		for (int k=1; k<=n; k++)
			for (int i=1; i<=n; i++)
				for (int j=1; j<=n; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[j][k]);
		ll ans = INF;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				if (i != j && krawedz[i][j] < INF) {
					ans = min(ans, krawedz[i][j] * (dist[1][i] + dist[j][n] + 1));
					for (int k=1; k<=n; k++)
						ans = min(ans, krawedz[i][j] * (min(dist[i][k], dist[j][k]) + 1 + dist[1][k] + dist[k][n] + 1));
				}
		cout << ans << "\n";
	}

	return 0;
}
