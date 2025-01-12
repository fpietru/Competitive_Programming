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

constexpr int MxN = 2e5+5;
constexpr int LOG = 18;
int jump[MxN][LOG+1];
int lvl[MxN];
int K[2];

int lca(int a, int b) {
	if (lvl[a] < lvl[b]) swap(a, b);
	int diff = lvl[a] - lvl[b];
	for (int i=LOG; i>=0; i--)
		if (diff&(1<<i)) a = jump[a][i];
	if (a == b) return a;
	for (int i=LOG; i>=0; i--)
		if (jump[a][i] != jump[b][i])
			a = jump[a][i], b = jump[b][i];
	return jump[a][0]; 
}

int sciezka(int a, int b) {
	return lvl[a] + lvl[b] - 2*lvl[lca(a, b)];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		int x; cin >> x;
		lvl[i] = lvl[x] + 1;
		jump[i][0] = x;
		
		for (int k=1; k<=LOG; k++)
			jump[i][k] = jump[jump[i][k-1]][k-1];
		
		int s1 = sciezka(K[0], K[1]);
		int s2 = sciezka(K[0], i);
		int s3 = sciezka(K[1], i);
		
		if (s2 > s1) K[1] = i;
		else if (s3 > s1) K[0] = i; 
		
		int mx = max({s1, s2, s3});
		cout << mx << "\n";
		
		// deb(mx, K[0], K[1]);
	}

	return 0;
}
