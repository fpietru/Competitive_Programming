/*
	Link: https://codeforces.com/contest/853/problem/B
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

struct flight {
	int dzien, typ, kto, koszt;
	bool operator < (const flight& b) {
		return (dzien < b.dzien);
	}
};
constexpr int MxNM = 1e5+5, MxD = 1e6+6;
flight lot[MxNM];
int best[MxNM];
ll dp[2][MxD];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k; cin >> n >> m >> k;
	int mxd = 0;
	for (int i=1; i<=m; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		if (c == 0) lot[i] = {a, 0, b, d};
		else        lot[i] = {a, 1, c, d};
		mxd = max(mxd, a);
	}
	sort(lot+1, lot+1+m);
	
	for (int l=0; l<2; l++) {
		int ktoma = 0;
		ll suma = 0LL;
		for (int i=1; i<=m; i++) {
			int dzien = lot[i].dzien;
			int typ = lot[i].typ;
			int kto = lot[i].kto;
			int koszt = lot[i].koszt;
			if (typ == l) {
				if (!best[kto]) {
					best[kto] = koszt;
					ktoma++;
					if (ktoma == n) {
						for (int j=1; j<=n; j++)
							suma += best[j];
						dp[l][dzien] = suma;
					}
				}
				else if (best[kto] > koszt) {
					if (ktoma == n) {
						suma -= (best[kto] - koszt);
						best[kto] = koszt;
						dp[l][dzien] = suma;
					}
					else best[kto] = koszt;
				}
			}	
		}
		if (ktoma != n) {
			cout << "-1\n";
			return 0;
		}
		reverse(lot+1, lot+1+m);
		memset(best, 0, sizeof(best));
	}
	
	for (int i=1; i<=mxd; i++) {
		if (dp[0][i] == 0) dp[0][i] = dp[0][i-1];
		else if (dp[0][i-1] > 0) dp[0][i] = min(dp[0][i], dp[0][i-1]);
	}
	for (int i=mxd; i>=1; i--) {
		if (dp[1][i] == 0) dp[1][i] = dp[1][i+1];
		else if (dp[1][i+1] > 0) dp[1][i] = min(dp[1][i], dp[1][i+1]);
	}
	
	ll ans = 1e18+7;
	for (int i=1; i<=mxd-k-1; i++)
		if (dp[0][i] && dp[1][i+k+1])
			ans = min(ans, dp[0][i] + dp[1][i+k+1]);
	
	if (ans >= 1e18+7)
		cout << "-1\n";
	else cout << ans << "\n";

	return 0;
}
