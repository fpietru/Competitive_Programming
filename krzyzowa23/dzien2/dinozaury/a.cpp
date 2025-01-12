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

struct punkt {
	int x, y;
	int typ; // 1-pocz prost, 2-koniec prost, 3-zapytanie
	int side;
	int wart;
};
constexpr int base = (1<<19);
constexpr int MxN = 2e5+5;
ll Tree[2*base];
vector<int> G[2][MxN];
int sz[2];
ll ans[MxN];
int pre[2][MxN], post[2][MxN];
int licznik = 0;
vector<punkt> punkty;

void update(int a, int b, ll x) {
	a += base - 1;
	b += base + 1;
	while ((a>>1) != (b>>1)) {
		if ((a&1) == 0) Tree[a+1] += x;
		if ((b&1) == 1) Tree[b-1] += x; 
		a >>= 1, b >>= 1;
	}
}

ll query(int v) {
	ll res = 0LL;
	v += base;
	while (v) {
		res += Tree[v];
		v >>= 1;
	}
	return res;
}

bool comp(punkt &a, punkt &b) {
	if (a.x == b.x) {
		if (a.y == b.y) {
			return (a.typ < b.typ);
		}
		else return a.y < b.y;
	}
	return a.x < b.x;
}

void dfs(int v, int p, int k) {
	pre[k][v] = ++licznik;
	for (auto u : G[k][v])
		if (u != p)
			dfs(u, v, k);
	post[k][v] = ++licznik;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int k=0; k<2; k++) {
		cin >> sz[k];
		for (int i=2; i<=sz[k]; i++) {
			int x; cin >> x;
			G[k][x].PB(i);
			G[k][i].PB(x);
		}
		licznik = 0;
		dfs(1, 1, k);
		/*cout << k << ":\n";
		for (int i=1; i<=sz[k]; i++)
			deb(i, pre[k][i], post[k][i]); */
	}
	
	int d; cin >> d;
	for (int i=1; i<=d; i++) {
		int a, b, x; cin >> a >> b >> x;
		int dl = post[1][b] - pre[1][b] + 1;
		punkt p1 = {pre[0][a], pre[1][b], 1, dl, x};
		punkt p2 = {post[0][a], post[1][b], 2, dl, -x};
		punkty.PB(p1);
		punkty.PB(p2);
	}
	
	int q; cin >> q;
	for (int i=1; i<=q; i++) {
		int a, b; cin >> a >> b;
		punkt p1 = {pre[0][a], pre[1][b], 3, 0, i};
		punkty.PB(p1);
	}
	
	sort(punkty.begin(), punkty.end(), comp);
	
	for (auto p : punkty) {
		// cout << p.x << " " << p.y << " " << p.typ << " " << p.wart << "\n";
		
		if (p.typ == 1) {
			// cout << "dodaje " << p.y << " " << p.y+p.side-1 << "\n";
			update(p.y, p.y+p.side-1, p.wart);
		}
		else if (p.typ == 2) {
			// cout << "usuwam " << p.y-p.side+1 << " " << p.y << "\n";
			update(p.y-p.side+1, p.y, p.wart);
		}
		else {
			ans[p.wart] = query(p.y);	
			// cout << "biore " << p.y << " " << ans[p.wart] << "\n";
		}		
	}
	
	for (int i=1; i<=q; i++)
		cout << ans[i] << "\n";

	return 0;
}
