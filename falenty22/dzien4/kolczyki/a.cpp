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
constexpr int M = 1e9+7;
int fact[MxN];
int ile[MxN];

int fastpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b&1) res = ((ll)res * a) % M;
		a = ((ll)a * a) % M;
		b >>= 1;
	}
	return res;
}

int newton(int n, int k) {
	int A = fact[n];
	int B = fastpow(fact[k], M-2);
	int C = fastpow(fact[n-k], M-2);	
	int res = 1;
	res = ((ll)res * A) % M;
	res = ((ll)res * B) % M;
	res = ((ll)res * C) % M;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	fact[0] = fact[1] = 1;
	for (int i=2; i<MxN; i++)
		fact[i] = ((ll)fact[i-1] * i) % M;
	
	int suma = 0;
	int n, k; cin >> n >> k;
	for (int i=1; i<=k; i++) {
		cin >> ile[i];
		suma += ile[i];
	}
	
	int P = fact[suma];
	for (int i=1; i<=k; i++)
		if (ile[i] > 1)
			P = ((ll)P * fastpow(fact[ile[i]], M-2)) % M;
	
	int ans = ((ll)P * newton(suma+n-1, n-1)) % M;
	
	cout << ans << "\n";

	return 0;
}
