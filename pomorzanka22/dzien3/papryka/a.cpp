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

constexpr int MxN = 1e5+5;
vector<int> G[MxN];
ll wart[MxN];
ll rozmiar[MxN];
int cut;
ll k;

void dfs(int v, int p) {
	for (auto u : G[v]) 
		if (u != p) dfs(u, v);
	
	vector<int> synowie;
	ll suma = wart[v];
	for (auto u : G[v])
		if (u != p) {
			synowie.PB(rozmiar[u]);
			suma += rozmiar[u];
		}
	sort(synowie.begin(), synowie.end(), greater<int>());
	for (auto r : synowie) {
		if (suma > k) {
			cut++;
			suma -= r;
		} else break;
	}
	rozmiar[v] = suma;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n >> k;
	for (int i=1; i<=n; i++) cin >> wart[i];
	for (int i=1; i<=n-1; i++) {
		int a, b; cin >> a >> b;
		G[a].PB(b); G[b].PB(a);
	}
	dfs(1,1);
	cout << cut << "\n";

	return 0;
}
