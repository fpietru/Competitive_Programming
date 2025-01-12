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

constexpr ll INF = 1e18+7;
string s;

ll ilenawiasow(int st, int ed) {
	ll res = 0LL, w = 0LL;
	stack<ll> S;
	for (int i=st; i<=ed; i++) {
		if (s[i] == '(') {
			S.push(w+1);
			w = 0LL;
		}
		else {
			if (!S.empty()) {
				w = S.top();
				S.pop();
				res += w; 
			}
			else w = 0LL;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k; cin >> n >> k; k--;
	cin >> s;
	ll ans = INF;
	for (int maska=0; maska<(1<<n); maska++)
		if (__builtin_popcount(maska) == k) {
			vector<int> granice;
			granice.PB(-1);
			for (int i=0; i<n; i++)
				if (maska&(1<<i))
					granice.PB(i);
			granice.PB(n-1);
			
			ll suma = 0LL;
			int m = granice.size();
			for (int i=0; i<m-1; i++)
				suma += ilenawiasow(granice[i]+1, granice[i+1]);
			if (ans > suma)
				ans = suma;
		}
		
	cout << ans << "\n";

	return 0;
}
