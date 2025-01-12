/*
	Link: https://atcoder.jp/contests/arc092/tasks/arc092_c
	Lepsze omównienie niż te oficialne: https://kmjp.hatenablog.jp/entry/2018/03/20/0930
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

constexpr int MxN = 1e3+3;
constexpr ll INF = 1e18+7;
vector<int> ruchy;
ll dp[MxN]; // dp[i] = maksymalna suma elementów, po między którymi są przerwy nieparzystej długości i ostatnim elementem jest ten na i-tej pozycji
ll przed[MxN];
ll best_idx;
ll mx = -INF;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		ll x; cin >> x;
		dp[i] = x;
		for (int j=1; j<i; j++)
			if (!((i-j)&1) && dp[i] < dp[j] + x) {
				dp[i] = dp[j] + x;
				przed[i] = j;
			}
		if (mx < dp[i]) {
			mx = dp[i];
			best_idx = i;
		}
	}
	cout << mx << "\n";
	for (int i=n; i>best_idx; i--) ruchy.PB(i); // usuwamy wszystkie z prawej granicy
	int v = best_idx;
	while (przed[v] > 0) {
		int u = przed[v];
		while (u < v) { // usuwamy wszystkie po między elementami, które bierzemy
			int mid = (u + v) >> 1;
			ruchy.PB(mid);
			v -= 2;
		}
	}
	for (int i=1; i<v; i++) ruchy.PB(1); // usuwamy wszystkie z lewej granicy
	cout << ruchy.size() << "\n";
	for (auto it : ruchy)
		cout << it << "\n";
	
	return 0;
}
