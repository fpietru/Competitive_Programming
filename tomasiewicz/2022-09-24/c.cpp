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

constexpr int MxN = 1e5+5;
constexpr int ALP = 26;
int trie[MxN][ALP];
bool wygrywa[MxN];
bool przegra[MxN];
int licznik = 1;

void dodaj(const string &s) {
	int v = 1;
	for (int i=0; i<(int)s.size(); i++) {
		if (trie[v][s[i]-'a'] == -1)
			trie[v][s[i]-'a'] = ++licznik;
		v = trie[v][s[i]-'a'];
	}
}

void dfs(int v) {
	bool lisc = true;
	for (int i=0; i<ALP; i++) {
		int u = trie[v][i];
		if (u != -1) {
			dfs(u);
			lisc = false;
			wygrywa[v] = (wygrywa[v] || !wygrywa[u]);
			przegra[v] = (przegra[v] || !przegra[u]);
		}	
	}
	if (lisc) {
		wygrywa[v] = false;
		przegra[v] = true;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	memset(trie, -1, sizeof(trie));
	
	int n, k; cin >> n >> k;
	for (int i=1; i<=n; i++) {
		string s; cin >> s;
		dodaj(s);
	}
	
	dfs(1);

	bool res = 1;
	if (wygrywa[1] == false) res = false;
	else {
		if (przegra[1] == true) res = true;
		else res = (k % 2 == 1);
	}
	cout << (res ? "First\n" : "Second\n");
	
	return 0;
}
