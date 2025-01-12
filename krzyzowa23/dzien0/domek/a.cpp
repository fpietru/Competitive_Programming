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

constexpr int MxN = (1<<17)+111;
constexpr int INF = 1e9+7;
constexpr int MxK = 21;
int dp[MxN][MxK];
int K, licz = 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int w; cin >> w >> K; K /= 2;
	int ile = 2;
	for (int i=1; i<=w; i++) {
		for (int j=1; j<=ile; j+=2) {
			ll a, b; cin >> a >> b;			
			dp[licz++][1] = a + b;
		}
		ile *= 2;
	}
	licz--;
	
	for (int v=licz; v>=1; v--) {
		if (2*v >= licz) { // lisc
			dp[v][0] = 0;
			for (int k=2; k<=K; k++)
				dp[v][k] = -INF;
		}
		else {
			int u1 = 2*v;
			int u2 = 2*v+1;
			for (int i=2; i<=K; i++) {
				dp[v][i] = -INF;
				for (int j=0; j<=i-1; j++) {
					int wyn = dp[u1][j] + dp[u2][i-j-1] + dp[v][1];
					dp[v][i] = max(dp[v][i], wyn);
				}
			}
		}
	}
	
	int ans = -INF;
	for (int i=0; i<=K; i++)
		ans = max(ans, dp[1][i]);
	cout << ans << "\n";

	return 0;
}
