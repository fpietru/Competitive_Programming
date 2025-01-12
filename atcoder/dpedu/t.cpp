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

constexpr int MxN = 3e3+3;
constexpr ll MOD = 1e9+7;
ll dp[MxN][MxN]; // dp[i][j] = wynik dla prefiksu 'i', którego ostatnim elementem jest 'j'
ll p[MxN];

ll suma(int a, int b) {
	return (p[b] - p[a-1] + MOD) % MOD;
}

void dodaj(ll &a, ll b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	string s; cin >> s;
	
	dp[1][1] = 1;
	for (int i=2; i<=n; i++) {
		p[0] = 0;
		for (int j=1; j<=i-1; j++)
			p[j] = (p[j-1] + dp[i-1][j]) % MOD;
		
		for (int x=1; x<=i; x++) {
			int L, R;
			if (s[i-2] == '<')
				L = 1, R = x-1;
			else L = x, R = i-1;
			dodaj(dp[i][x], suma(L, R));
		}
	}
	
	ll ans = 0;
	for (int i=1; i<=n+1; i++)
		dodaj(ans, dp[n][i]);
	cout << ans << "\n";

	return 0;
}
