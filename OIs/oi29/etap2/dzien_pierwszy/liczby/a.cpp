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

vector<ll> p;
vector<ll> ans;

ll ile(ll k) {
	ll suma = 0LL;
	int pierwszych = p.size();
	for (int maska=1; maska<(1<<pierwszych); maska++) {
		ll ilo = 1LL;
		for (int i=0; i<pierwszych; i++)
			if (maska & (1<<i)) ilo *= p[i];
		if (__builtin_popcount(maska)&1)
			suma -= k / ilo;
		else suma += k / ilo;
	}
	return k + suma;
}

ll nwd(ll a, ll b) {
	if (!b) return a;
	else return nwd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	ll n, k; int c;
	cin >> n >> k >> c;
	
	ll _n = n;
	for (ll i=2; i*i<=_n; i++)
		if (_n % i == 0LL) {
			p.PB(i);
			while (_n % i == 0LL)
				_n /= i;
		}
	if (_n != 1) p.PB(_n);
	
	ll low = 1;
	ll high = 1e18;
	while (low < high) {
		ll mid = (low + high) >> 1;
		// cout << low << " " << high << " " << mid << "\n";
		if (ile(mid) < k) low = mid+1;
		else high = mid;
	}
	ans.PB(low);
	
	ll x = low + 1;
	while ((int)ans.size() < c) {
		if (nwd(x, n) == 1)
			ans.PB(x);
		x++;
	}
	
	for (auto it : ans)
		cout << it << " ";
	cout << "\n";

	return 0;
}
