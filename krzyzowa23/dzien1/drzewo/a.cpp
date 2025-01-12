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

struct node {
	int typ;
	int bok;
	int g[4];
};
string s;
int licznik = 1, m;
constexpr int MxN = 1e6+6;
constexpr int MOD = 1e9+7;
vector<int> G[MxN], G2[MxN];
vector<set<int, greater<int>>> sety;
node bloki[MxN];
bool vis[MxN];
set<int, greater<int>> st;

ll fastpow(ll a, ll b) {
	ll res = 1LL;
	while (b) {
		if (b&1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

void polaczPL(int a, int b) {
	if (bloki[a].typ == 0 || bloki[b].typ == 0) return;
	else if (bloki[a].typ == 1 && bloki[b].typ == 1) {
		G2[a].PB(b), G2[b].PB(a);
	}
	else if (bloki[a].typ == 1 && bloki[b].typ == 4) {
		polaczPL(a, bloki[b].g[0]);
		polaczPL(a, bloki[b].g[2]);
	}
	else if (bloki[a].typ == 4 && bloki[b].typ == 1) {
		polaczPL(bloki[a].g[1], b);
		polaczPL(bloki[a].g[3], b);
	}
	else if (bloki[a].typ == 4 && bloki[b].typ == 4) {
		polaczPL(bloki[a].g[1], bloki[b].g[0]);
		polaczPL(bloki[a].g[3], bloki[b].g[2]);
	}
}

void polaczGD(int a, int b) {
	if (bloki[a].typ == 0 || bloki[b].typ == 0) return;
	else if (bloki[a].typ == 1 && bloki[b].typ == 1) {
		G2[a].PB(b), G2[b].PB(a);
	}
	else if (bloki[a].typ == 1 && bloki[b].typ == 4) {
		polaczGD(a, bloki[b].g[0]);
		polaczGD(a, bloki[b].g[1]);
	}
	else if (bloki[a].typ == 4 && bloki[b].typ == 1) {
		polaczGD(bloki[a].g[2], b);
		polaczGD(bloki[a].g[3], b);
	}
	else if (bloki[a].typ == 4 && bloki[b].typ == 4) {
		polaczGD(bloki[a].g[2], bloki[b].g[0]);
		polaczGD(bloki[a].g[3], bloki[b].g[1]);
	}
}

void wczytaj(int v, int side) {
	char c; cin >> c;
	bloki[v].bok = side;
	if (c == '0') bloki[v].typ = 0;
	else if (c == '1') bloki[v].typ = 1;
	else {
		bloki[v].typ = 4;
		for (int i=0; i<4; i++) {
			bloki[v].g[i] = ++licznik;
			wczytaj(licznik, side-1);
		}
	}
}

void dfs(int v) {
	if (bloki[v].typ != 4) return;
	for (int i=0; i<4; i++)
		dfs(bloki[v].g[i]);
	polaczPL(bloki[v].g[0], bloki[v].g[1]);
	polaczPL(bloki[v].g[2], bloki[v].g[3]);
	polaczGD(bloki[v].g[0], bloki[v].g[2]);
	polaczGD(bloki[v].g[1], bloki[v].g[3]);
}

void dodaj(int x) {
	if (st.find(x) == st.end())
		st.insert(x);
	else {
		st.erase(x);
		dodaj(x+1);
	}
}

void dfs2(int v) {
	vis[v] = true;
	dodaj(2*bloki[v].bok);
	for (auto u : G2[v])
		if (!vis[u]) dfs2(u);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> m;
	wczytaj(1, m);
	dfs(1);
	
	int licz = 0;
	for (int v=1; v<=licznik; v++)
		if (!vis[v] && bloki[v].typ == 1) {
			st.clear();
			licz++;
			dfs2(v);
			sety.PB(st);
		}
		
	sort(sety.begin(), sety.end());
	st = sety.back();
	
	ll ans = 0LL;
	for (auto pot : st)
		ans = (ans + fastpow(2, pot)) % MOD;
	
	cout << licz << "\n" << ans << "\n";

	return 0;
}
