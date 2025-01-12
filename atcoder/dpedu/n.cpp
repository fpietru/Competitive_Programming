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

constexpr int MxN = 4e2+2;
constexpr ll INF = 1e18+7;
ll dp[MxN][MxN]; // dp[i][j] = minimalny koszt na otrzymanie slime'a na przedziale [i, j]
int opt[MxN][MxN];
ll a[MxN];
ll p[MxN];

inline ll cost(int i, int j) {
	return p[j] - p[i-1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	for (int i=1; i<=n; i++)
		p[i] = p[i-1] + a[i];

	for (int i=1; i<=n; i++) {
		dp[i][i] = 0;
		opt[i][i] = i;
	}

	// Optymalizacja Knuth'a
	for (int i=n-1; i>=1; i--)
		for (int j=i+1; j<=n; j++) {
			dp[i][j] = INF;
			for (int k=opt[i][j-1]; k<=min(j-1, opt[i+1][j]); k++) {
				ll wart = dp[i][k] + dp[k+1][j] + cost(i, j);
				if (wart < dp[i][j]) {
					dp[i][j] = wart;
					opt[i][j] = k;
				}
			}		
		}
	cout << dp[1][n] << "\n";

	return 0;
}
