/*
	Link: https://atcoder.jp/contests/arc101/tasks/arc101_b
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
constexpr int base = (1<<18);
constexpr int INF = 1e9+7;
int tab[MxN], tab2[MxN], Tree[2*base];
int n;
 
void update(int v) {
	v += base;
	Tree[v]++;
	while (v) {
		v >>= 1;
		Tree[v] = Tree[2*v] + Tree[2*v+1];
	}
}
 
int query(int a, int b) {
	int res = 0;
	a += base - 1;
	b += base + 1;
	while ((a>>1) != (b>>1)) {
		if ((a&1) == 0) res += Tree[a+1];
		if ((b&1) == 1) res += Tree[b-1];
		a >>= 1; b >>= 1; 
	}
	return res;
}
 
bool check(int k) {
	for (int i=1; i<=n; i++) {
		if (tab[i] < k) tab2[i] = -1;
		else tab2[i] = 1;
	}
	memset(Tree, 0, sizeof(Tree));
	
	int p = 0;
	update(n);
	ll iledodatnich = 0LL;
	for (int i=1; i<=n; i++) {
		p += tab2[i];
		iledodatnich += (ll)query(0, p+n);
		update(p+n);
	}
	return (4*iledodatnich >= 1LL*n*(n+1));
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int low = INF, high = -INF;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> tab[i];
		low = min(low, tab[i]);
		high = max(high, tab[i]);
	}
	high++;
	while (low < high) {
		int mid = (1LL*low + high) >> 1;
		if (check(mid)) low = mid + 1;
		else high = mid;
	}
	cout << low-1 << "\n";
 
	return 0;
}
