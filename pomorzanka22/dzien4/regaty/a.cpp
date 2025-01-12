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

void normalize(int &x, int r, int m) {
	x -= r;
	if (x < 0) x += m;
}

bool przecina(int a, int b, int c, int d, int n) {
	int r = a;
	normalize(a, r, n);
	normalize(b, r, n);
	normalize(c, r, n);
	normalize(d, r, n);
	
	deb(a, b, c, d);
	
	if ((c < a && a < d && c < b) || (c < b && b < d)) return true;
	else return false;
}

int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);

/*
	int n, k; cin >> n >> k;
	for (int i=1; i<=n; i++) {
		while (true) {
			int x; cin >> x;
			if (x == 0) break;
			G[i].PB(x); G[x].PB(i);
		}
	} */
	
	while (true) {
		int a, b, c, d, n; cin >> a >> b >> c >> d >> n;
		a--;
		b--;
		c--;
		d--;
		deb(przecina(a,b,c,d,n));
	
	}

	return 0;
}
