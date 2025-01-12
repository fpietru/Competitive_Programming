/*
	Link: https://atcoder.jp/contests/arc092/tasks/arc092_b
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

constexpr int MxN = 2e5+5;
constexpr int INF = 1e9+7;
int A[MxN], B[MxN], a[MxN], b[MxN];
int n;

ll getprzedzialy(int L, int R) {
	ll res = 0LL;
	int pocz = n, kon = n;
	for (int i=1; i<=n; i++) {
		while (pocz >= 1 && a[i] + b[pocz] > R) pocz--; 
		while (kon >= 1 && a[i] + b[kon] > L-1) kon--; 
		res += (ll)(pocz - kon);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i=1; i<=n; i++) cin >> A[i];	
	for (int i=1; i<=n; i++) cin >> B[i];
	
	int ans = 0;
	for (int k=28; k>=0; k--) {
		int t = (1<<k);
		for (int i=1; i<=n; i++) {
			a[i] = A[i] % (t<<1);
			b[i] = B[i] % (t<<1);
		}
		sort(a+1, a+n+1);
		sort(b+1, b+n+1);
		ll ile1 = getprzedzialy(t, 2*t-1) + getprzedzialy(3*t, 4*t-1);
		if (ile1&1) ans |= (1<<k);
	}
	cout << ans << "\n";

	return 0;
}
