// Link: https://szkopul.edu.pl/problemset/problem/ovRIpLFK3IhyFPjnVXeZtGxH/site/?key=statement
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

constexpr int MxN = 2e4+4;
constexpr ll INF = 1e18+7;
int waga[MxN], d[MxN];
ll suma[MxN], dist[MxN], koszt[MxN];
ll dp[MxN][3];

// dp[i][k] = min(dp[j][k-1] + cost(j, i)), gdzie j < i 

ll cost(int a, int b) {
	ll suma_wag = suma[a] - suma[b];
	ll suma_dl = dist[b];
	ll res = koszt[a] - koszt[b] - suma_wag*suma_dl;
	return res;
}

void compute(int k, int st, int ed, int opt1, int opt2) {
	if (st > ed) return;
	int md = (st + ed) >> 1;
	int best = -1;
	dp[md][k] = INF;
	for (int i=opt1; i<=min(opt2, md); i++) {
		ll val = dp[i][k-1] + cost(i+1, md);
		if (dp[md][k] > val) {
			dp[md][k] = val;
			best = i;
		}
	}
	compute(k, st, md-1, opt1, best);
	compute(k, md+1, ed, best, opt2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> waga[i] >> d[i];
	}
	
	suma[n+1] = 0;
	dist[n+1] = 0;
	koszt[n+1] = 0;
	for (int i=n; i>=1; i--) {
		suma[i] = suma[i+1] + waga[i];
		dist[i] = dist[i+1] + d[i];
		koszt[i] = koszt[i+1] + waga[i] * dist[i];
	}

	for (int i=1; i<=n+1; i++)
		dp[i][0] = cost(1, i);
	
	for (int k=1; k<3; k++)
		compute(k, 1, n+1, 1, n+1);
	
	cout << dp[n+1][2] << "\n";

	return 0;
}
