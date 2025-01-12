#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
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

constexpr int MxN = 303;
ld dp[MxN][MxN][MxN];
int zlicz[4];
int n;

ld f(int a, int b, int c) {
	if (a < 0 || b < 0 || c < 0) return 0;
	if (a == 0 && b == 0 && c == 0) return 0;
	if (dp[a][b][c] > 0) return dp[a][b][c];
	ld res = n + a*f(a-1, b, c) + b*f(a+1, b-1, c) + c*f(a, b+1, c-1);
	return dp[a][b][c] = res / (a + b + c);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i=1; i<=n; i++) {
		int x; cin >> x;
		zlicz[x]++;
	}
	
	memset(dp, -1, sizeof(dp));
	cout << fixed << setprecision(9) << f(zlicz[1], zlicz[2], zlicz[3]) << "\n";

	return 0;
}
