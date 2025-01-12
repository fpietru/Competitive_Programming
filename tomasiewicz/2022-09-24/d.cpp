/*
	Link: https://www.spoj.com/problems/SUBXOR/
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

constexpr int MxN = 2222222;
int trie[MxN][2];
int rozmiar[MxN];
int licznik;

void dodaj(int x) {
	int v = 1;
	for (int i=20; i>=0; i--) {
		rozmiar[v]++;
		int bit = (bool)(x&(1<<i));
		if (trie[v][bit] == -1)
			trie[v][bit] = ++licznik;
		v = trie[v][bit];
	}
	rozmiar[v]++;
}

ll zlicz(int x, int k) {
	int v = 1;
	int y = 0;
	ll suma = 0LL;
	for (int i=20; i>=0; i--) {
		int bit = (bool)(x&(1<<i));
		int abit = bit ^ 1;
		int kbit = (bool)(k&(1<<i));
		if (kbit == 1) {
			if (trie[v][abit] != -1) {
				if (abit == 1) y |= (1<<i);				
				if (trie[v][bit] != -1) {
					suma += (ll)rozmiar[trie[v][bit]];
				}
				v = trie[v][abit];
			}
			else {
				if (trie[v][bit] != -1)
					suma += (ll)rozmiar[trie[v][bit]];
				return suma;
			}			
		}
		else {
			if (trie[v][bit] != -1) {
				if (bit == 1) y |= (1<<i);
				v = trie[v][bit];
			}
			else return suma;
		}
	}
	return suma;
}

void solve() {
	licznik = 1;
	memset(trie, -1, sizeof(trie));
	memset(rozmiar, 0, sizeof(rozmiar));
	int n, k; cin >> n >> k;
	dodaj(0);
	int prefxor = 0;
	ll res = 0LL;
	for (int i=1; i<=n; i++) {
		int x; cin >> x;
		prefxor ^= x;
		res += zlicz(prefxor, k);
		dodaj(prefxor);
	}
	cout << res << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}
