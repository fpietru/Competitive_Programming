/*
	Link: https://codeforces.com/contest/915/problem/G
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

constexpr int MxN = 2e6+6;
constexpr int MOD = 1e9+7;
vector<int> dzielniki[MxN];
ll wynik[MxN];
bool zlozona[MxN];
int miu[MxN], pw[MxN];

ll fastpow(ll a, ll b) {
	ll res = 1LL;
	while (b) {
		if (b&1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k; cin >> n >> k;
	for (int i=1; i<=k; i++) {
		miu[i] = 1;
		pw[i] = fastpow(i, n);
	}
	for (int i=2; i<=k; i++) {
		if (zlozona[i] == false) {
			for (int j=i; j<=k; j+=i) {
				if (j > i) zlozona[j] = true;
				if (j % (i*i) == 0) miu[j] = 0;
				miu[j] *= -1;
			}
		}
	}

	for (int i=2; i<=k; i++)
		for (int j=i; j<=k; j+=i)
			dzielniki[j].PB(i);

	ll ans = 0LL;
	wynik[1] = 1;
	for (int i=2; i<=k; i++) {
		wynik[i] = (wynik[i-1] - pw[i-1] + pw[i] + MOD) % MOD;
		for (auto d : dzielniki[i]) {
			if (miu[d] == 1)       wynik[i] = (wynik[i] - pw[(i-1)/d] + pw[i/d] + MOD) % MOD;
			else if (miu[d] == -1) wynik[i] = (wynik[i] + pw[(i-1)/d] - pw[i/d] + MOD) % MOD;
		}
		ans = (ans + (wynik[i] ^ i)) % MOD;
	}
	
	cout << ans << "\n";

	return 0;
}
