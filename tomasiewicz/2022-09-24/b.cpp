/*
	Link: https://codeforces.com/contest/706/problem/D
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

constexpr int MxN = 6400004;
int trie[MxN][2];
int ile[MxN];
int licznik = 1;

void dodaj(int x) {
	int v = 1;
	for (int i=31; i>=0; i--) {
		int bit = (bool)(x&(1<<i));
		ile[v]++;
		if (trie[v][bit] == -1)
			trie[v][bit] = ++licznik;
		v = trie[v][bit];
	}
	ile[v]++;
}

void usun(int x) {
	int v = 1;
	for (int i=31; i>=0; i--) {
		int bit = (bool)(x&(1<<i));
		ile[v]--;
		v = trie[v][bit];
	}
	ile[v]--;
}

int maxxor(int x) {
	int v = 1;
	int res = 0;	
	for (int i=31; i>=0; i--) {
		int bit = (bool)(x&(1<<i));
		int abit = bit ^ 1;
		int biore;
		if (trie[v][abit] != -1 && ile[trie[v][abit]] > 0) {
			v = trie[v][abit];
			biore = abit;
		}
		else {
			v = trie[v][bit];
			biore = bit;
		}
		if (biore == 1) res |= (1<<i);
	}
	return res;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(trie, -1, sizeof(trie));
	dodaj(0);

	int q; cin >> q;
	while (q--) {
		char op; int x; cin >> op >> x;
		if (op == '+') dodaj(x);
		else if (op == '-') usun(x);
		else {
			cout << (x ^ maxxor(x)) << "\n";
		}
	}

	return 0;
}
