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

constexpr int MxN = 1e6;
constexpr int MOD = 1e9+7;
ll silnia[MxN+10], odw[MxN+10];
bool pierwsza[MxN+10];
map<int, int> mp;

ll fastpow(ll a, ll b) {
	ll res = 1LL;
	while (b) {
		if (b&1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

ll newton(ll a, ll b) {
	ll res = silnia[a];
	res = res * odw[b] % MOD;
	res = res * odw[a-b] % MOD;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int k, p; cin >> k >> p;
	
	silnia[0] = silnia[1] = 1LL;
	for (int i=2; i<=MxN; i++)
		silnia[i] = silnia[i-1] * i % MOD;
	odw[MxN] = fastpow(silnia[MxN], MOD-2);
	for (int i=MxN-1; i>=0; i--)
		odw[i] = odw[i+1] * (i+1) % MOD;
	
	memset(pierwsza, 1, sizeof(pierwsza));
	pierwsza[0] = pierwsza[1] = false;
	for (int i=2; i*i<=MxN; i++)
		if (pierwsza[i])
			for (int j=i*i; j<=MxN; j+=i)
				pierwsza[j] = false;
	int P = 0;
	for (int i=2; i<=p; i++)
		P += pierwsza[i];
	
	int _k = k;
	for (int i=2; i*i<=k; i++)
		while (_k % i == 0) {
			mp[i]++;
			_k /= i;
		}
	if (_k != 1) mp[_k]++;

	ll ans = 1LL;
	for (auto it : mp) {
		ll ile = (ll)it.SD;
		ans = ans * newton(ile+P-1, ile) % MOD;
	}
	
	cout << ans << "\n";

	return 0;
}
