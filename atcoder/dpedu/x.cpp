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
constexpr int MxS = 2e4+4;
int w[MxN], s[MxN], v[MxN];
int order[MxN];
ll dp[MxS];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> w[i] >> s[i] >> v[i];
		order[i] = i;
	}
	sort(order+1, order+n+1, [&](int a, int b) { return w[a] + s[a] < w[b] + s[b]; });
	
	for (int i=1; i<=n; i++) {
		int x = order[i];
		for (int j=s[x]; j>=0; j--)
			dp[j + w[x]] = max(dp[j + w[x]], dp[j] + v[x]);
	}
	
	ll ans = 0LL;
	for (int j=0; j<MxS; j++)
		ans = max(ans, dp[j]);
	cout << ans << "\n";

	return 0;
}
