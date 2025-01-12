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
constexpr int INF = 1e9+7;
int dp[MxN][MxN];
string A, B, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> A >> B;
	int n = A.size();
	int m = B.size();

	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			if (A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else                  dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
		
	while (n && m) {
		if (A[n-1] == B[m-1]) {
			ans += A[n-1];
			n--;
			m--;
		}
		else if (dp[n-1][m] > dp[n][m-1]) n--;
		else m--;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";

	return 0;
}
