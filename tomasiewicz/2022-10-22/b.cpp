/*
	Link: https://codeforces.com/contest/960/problem/E
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

constexpr int MxN = 2e5+5;
constexpr ll MOD = 1e9+7;
vector<int> G[MxN];
ll wart[MxN];
int kolor[MxN];
ll ileczerwonych[MxN];
ll ileczarnych[MxN];
ll rozmiar[MxN];
ll sumaczerwonych, sumaczarnych;
ll n, ans = 0LL;
struct pack {
	ll wszystkich;
	ll czerwonych;
	ll czarnych;
};

void dfs(int v, int p, int c=0) {
	kolor[v] = c;
	rozmiar[v] = 1LL;
	if (kolor[v]) {
		ileczerwonych[v]++;
		sumaczerwonych++;
	}
	else {
		ileczarnych[v]++;
		sumaczarnych++;
	}
	for (auto u : G[v])
		if (u != p) {
			dfs(u, v, c^1);
			rozmiar[v] += rozmiar[u];
			ileczerwonych[v] += ileczerwonych[u];
			ileczarnych[v] += ileczarnych[u];
		}
}

inline ll M(ll x) {
	return x % MOD;
}

void dfs2(int v, int p) {
	vector<pack> poddrzewa;
	poddrzewa.PB({n-rozmiar[v], sumaczerwonych-ileczerwonych[v], sumaczarnych-ileczarnych[v]});
	for (auto u : G[v])
		if (u != p) {
			dfs2(u, v);
			poddrzewa.PB({rozmiar[u], ileczerwonych[u], ileczarnych[u]});
		}
	ll sciezekczerwonych = 0LL;
	ll sciezekczarnych = 0LL;
	for (auto u : poddrzewa) {
		sciezekczerwonych = M(sciezekczerwonych + M(u.czerwonych * (n - u.wszystkich - (kolor[v] == 0))));
		sciezekczarnych = M(sciezekczarnych + M(u.czarnych * (n - u.wszystkich - (kolor[v] == 1))));	
	}
	if (kolor[v] == 1) sciezekczerwonych = M(sciezekczerwonych + sumaczerwonych);
	else sciezekczarnych = M(sciezekczarnych + sumaczarnych);
	
	if (kolor[v] == 1) {
		ans = M(ans + M(wart[v] * sciezekczerwonych));
		ans = M(ans - M(wart[v] * sciezekczarnych) + MOD);
	}
	else {
		ans = M(ans + M(wart[v] * sciezekczarnych));
		ans = M(ans - M(wart[v] * sciezekczerwonych) + MOD);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> wart[i];
	for (int i=1; i<=n-1; i++) {
		int a, b; cin >> a >> b;
		G[a].PB(b); G[b].PB(a);
	}
	dfs(1, 1);
	dfs2(1, 1);
	cout << ans << "\n";
	
	return 0;
}	
