#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ull = unsigned long long;
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

constexpr int MxN = 1e6+6;
constexpr int p1 = 47, p2 = 2137;
ull p1_pow[MxN], p2_pow[MxN];
ull h1[MxN], h2[MxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
		
	int n, k; cin >> n >> k;
	string s; cin >> s;
	
	p1_pow[0] = 1ULL;
	p1_pow[1] = p1;
	p2_pow[0] = 1ULL;
	p2_pow[1] = p2;
	for (int i=2; i<=n; i++) {
		p1_pow[i] = p1_pow[i-1] * p1;
		p2_pow[i] = p2_pow[i-1] * p2;
	}
	
	h1[0] = 0ULL;
	h2[0] = 0ULL;
	for (int i=1; i<=n; i++) {
		h1[i] = h1[i-1] * p1 + (s[i-1]-'a'+1);
		h2[i] = h2[i-1] * p2 + (s[i-1]-'a'+1);
	}

	int low = 1;
	int high = n;
	while (low < high) {
		int mid = (low + high) >> 1;
		int mx = 0;
		map<pair<ull, ull>, int> mp;
		for (int i=0; i+mid-1<n; i++) {
			int a = i, b = i+mid-1;
			ull H1 = h1[b+1] - h1[a] * p1_pow[b-a+1];
			ull H2 = h2[b+1] - h2[a] * p2_pow[b-a+1];
			int ile = ++mp[{H1, H2}];
			mx = max(mx, ile);
		}
		if (mx >= k) low = mid + 1;
		else high = mid;
	}
	low--;
	
	if (low > 0) cout << low << "\n";
	else cout << "-1\n";

	return 0;
}

