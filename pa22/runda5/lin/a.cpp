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

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

constexpr int MxN = 2e5+5;
vector<int> G[MxN];
int dist[MxN];
int tab[MxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> tab[i];

	for (int i=1; i<=n-1; i++)
		for (int j=i+1; j<=n; j++)
			if (tab[i] > tab[j]) {
				G[i].PB(j);
				G[j].PB(i);
			}
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++)
			dist[j] = -1;
		dist[i] = 0;
		queue<pii> Q;
		Q.push({i, 0});
		while (!Q.empty()) {
			int v = Q.front().FR;
			int d = Q.front().SD;
			Q.pop();
			for (auto u : G[v])
				if (dist[u] == -1) {
					dist[u] = d + 1;
					Q.push({u, d+1});
				}
		}
		ll suma = 0LL;
		for (int j=1; j<=n; j++)
			if (dist[j] > 0)
				suma += 1LL * dist[j];
		cout << suma << " ";
	}
	cout << "\n";

	return 0;
}
