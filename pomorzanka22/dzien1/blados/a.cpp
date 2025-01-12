#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__) // debugging 
/*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename ...Args> void logger(string vars, Args&&... values) { cout<<"[ "<<vars<<" = "; string delim=""; (..., (cout<<delim<<values, delim=", ")); cout <<" ]\n"; }
/**/

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	vector<pair<ll,int>> vec;
	int n; ll a, b;
	cin >> n >> a >> b;
	for (int i=0; i<n; i++) {
		ll x; cin >> x;
		vec.PB({x, i});
	}
	sort(vec.begin(), vec.end(), greater<pair<ll,int>>());
	ll sum = 0LL;
	
	int kon = 0, pocz = 0;
	while (pocz < n && sum < a)
		sum += vec[pocz++].FR;
	while (sum > b && pocz < n)
		sum = sum - vec[kon++].FR + vec[pocz++].FR;
	if (sum < a || b < sum) cout << "-1\n";
	else {
		pocz--;
		cout << pocz - kon + 1 << "\n";
		for (int i=pocz; i>=kon; i--)
			cout << vec[i].SD << " ";
		cout << "\n";
	}

	return 0;
}
