#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ull = unsigned long long;
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

constexpr int MxN = 105;
vector<int> G[MxN];
int licznik[MxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		int x; cin >> x;
		for (int j=1; j<=x; j++) {
			int u; cin >> u;
			G[i].PB(u);
		}
	}
	
	int tura = 1;
	while (true) {
		int v = 1;
		while (G[v].size()) {
			int u = G[v][licznik[v]++];
			if (licznik[v] > (int)G[v].size()-1)
				licznik[v] = 0;
			v = u;
		}
		bool koniec = true;
		for (int i=1; i<=n; i++)
			if (licznik[i] != 0)
				koniec = false;
		if (koniec)
			break;
		else tura++;
	}
	cout << tura << "\n";

	return 0;
}
