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

constexpr int MxN = 33;
vector<int> G[MxN*MxN];
int plansza[MxN][MxN];
int skojarzony[MxN*MxN];
bool vis[MxN*MxN], niema[MxN*MxN];
int n, m, gtime;

bool powieksz(int v) {
	vis[v] = gtime;
	for (auto u : G[v])
		if (skojarzony[u] == -1) {
			skojarzony[v] = u;
			skojarzony[u] = v;
			return true;
		}
	for (auto u : G[v])
		if (vis[skojarzony[u]] != gtime && powieksz(skojarzony[u])) {
			skojarzony[v] = u;
			skojarzony[u] = v;
			return true;
		}
	return false;
}

int f(int i, int j) {
	return (i-1) * m + j;
}

void connect(int i, int j, int i2, int j2) {
	if ((i2 < 1 || i2 > n) || (j2 < 1 || j2 > m) || !plansza[i2][j2])
		return;
	
	deb(i, j, i2, j2, f(i, j), f(i2, j2));
	
	G[f(i, j)].PB(f(i2, j2));
	G[f(i2, j2)].PB(f(i, j));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int wolne = 0;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		string s; cin >> s;
		for (int j=1; j<=m; j++) {
			plansza[i][j] = (s[j-1] == '.');
			if (s[j-1] == '#') niema[f(i, j)] = 1;
			wolne += plansza[i][j];
		}
	}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			connect(i, j, i-2, j+1);
			connect(i, j, i-1, j+2);
			connect(i, j, i+1, j+2);
			connect(i, j, i+2, j+1);
			connect(i, j, i+2, j-1);
			connect(i, j, i+1, j-2);
			connect(i, j, i-1, j-2);
			connect(i, j, i-2, j-1);
		}
	
	memset(skojarzony, -1, size(skojarzony));
	while (true) {
		gtime++;
		bool any = false;
		for (int i=1; i<=n*m; i++)
			if (!niema[i] && skojarzony[i] == -1 && powieksz(i))
				any = true;
		if (!any)
			break;
	}
	int matching = 0;
	for (int i=1; i<=n*m; i++)
		if (skojarzony[i] != -1)
			matching++;
	matching >>= 1;
	
	cout << wolne - matching << "\n"; 

	return 0;
}
