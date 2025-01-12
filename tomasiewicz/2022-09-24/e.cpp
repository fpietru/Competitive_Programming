/*
	Link: https://www.spoj.com/problems/XORX/
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

constexpr int MxN = 6200022;
constexpr int Blim = 31;
int trie[MxN][2];
int licznik;

void dodaj(int x) {
	int v = 1;
	for (int i=Blim; i>=0; i--) {
		int bit = (bool)(x&(1<<i));
		if (trie[v][bit] == -1)
			trie[v][bit] = ++licznik;
		v = trie[v][bit];
	}
}

int mxxor(int x) {
	int v = 1;
	int res = 0;
	for (int i=Blim; i>=0; i--) {
		int bit = (bool)(x&(1<<i));
		int abit = bit ^ 1;
		if (trie[v][abit] != -1) {
			if (abit) res |= (1<<i);
			v = trie[v][abit];
		}
		else {
			if (bit) res |= (1<<i);
			v = trie[v][bit];
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		licznik = 1;
		memset(trie, -1, sizeof(trie));
		int n, k; cin >> n >> k;
		int px = 0, best = 0;
		dodaj(0);
		for (int i=1; i<=n; i++) {
			int x; cin >> x;
			px ^= x;
			int curr = px ^ mxxor(px ^ k);
			if ((k ^ curr) > (k ^ best))
				best = curr;
			dodaj(px);
		}
		cout << best << "\n";
	}

	return 0;
}
