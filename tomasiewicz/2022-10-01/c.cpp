/*
	Link: https://codeforces.com/contest/1350/problem/D	
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

constexpr int MxN = 1e5+5;
int p[MxN];
int tab[MxN];

int suma(int a, int b) {
	return p[b] - p[a-1];
}

bool solve() {
	int n, k; cin >> n >> k;
	p[0] = 0;
	bool exists = false;
	for (int i=1; i<=n; i++) {
		cin >> tab[i];
		if (tab[i] >= k) {
			 p[i] = p[i-1] + 1;
			 if (tab[i] == k) exists = true;
		}
		else p[i] = p[i-1] - 1;
	}
	if (n == 1) return tab[1] == k;	
	for (int dl=2; dl<=3; dl++)
		for (int i=1; i+dl-1<=n; i++)
			if (suma(i, i+dl-1) > 0 && exists) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		cout << (solve() ? "YES\n" : "NO\n");		
	}

	return 0;
}
