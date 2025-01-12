/*
	link: https://codeforces.com/contest/1393/problem/D
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

constexpr int MxN = 2e3+3;
char tab[MxN][MxN];
int dp[2][MxN][MxN];
ll ans;
int n, m;

void processletter(char literka) {
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			if (tab[i][j] == literka) dp[0][i][j] = 1;
			else dp[0][i][j] = 0;
			if (j >= 3 && i >= 2 && tab[i][j] == literka && tab[i][j-1] == literka && dp[0][i-1][j-1] && dp[0][i][j-2])
				dp[0][i][j] = min(dp[0][i-1][j-1], dp[0][i][j-2]) + 2;
		}	
	for (int i=n; i>=1; i--)
		for (int j=1; j<=m; j++) {
			if (tab[i][j] == literka) dp[1][i][j] = 1;
			else dp[1][i][j] = 0;
			if (j >= 3 && i <= n-1 && tab[i][j] == literka && tab[i][j-1] == literka && dp[1][i+1][j-1] && dp[1][i][j-2])
				dp[1][i][j] = min(dp[1][i+1][j-1], dp[1][i][j-2]) + 2;
		}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			ans += (ll)((min(dp[0][i][j], dp[1][i][j])+1)>>1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			cin >> tab[i][j];
			
	for (char c='a'; c<='z'; c++)
		processletter(c);
		
	cout << ans << "\n";

	return 0;
}
